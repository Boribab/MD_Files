#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <net/if_arp.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <ctype.h>
#include <pcap/pcap.h>

#define MAXBYTES2CAPTURE 2048

int get_mac_by_inf(u_char mac[6], const char *dev) {
	struct ifreq ifr;
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);

	strncpy(ifr.ifr_name, dev, IFNAMSIZ - 1);

	if (ioctl(fd, SIOCGIFHWADDR, &ifr) != 0) {
		printf("can't get MAC Address\n");
		close(fd);
		return 0;
	}

	for (int i = 0; i < 6; ++i) {
		mac[i] = ifr.ifr_addr.sa_data[i];	
	}

	close(fd);
	return 1;
}

int get_ip_by_inf(struct in_addr* ip, const char *dev) {
	struct ifreq ifr;
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in *sin;

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name, dev, IFNAMSIZ - 1);

	if (ioctl(fd, SIOCGIFADDR, &ifr) != 0) {
		printf("can't get IP Address\n");
		close(fd);
		return 0;
	}

	close(fd);

	sin = (struct sockaddr_in*) &ifr.ifr_addr;
	*ip = sin->sin_addr;

	return 1;
}

void
make_arp_packet(u_char **packet, int *length, int opcode, struct in_addr my_ip, struct in_addr vic_ip, u_char *my_mac, u_char *vic_mac) {
	struct ether_header eth;
	struct ether_arp arp;

	//fill the ethernet header
	if (opcode == ARPOP_REQUEST) {
		for (int i = 0; i<6; i++)
			eth.ether_dhost[i] = 0xff;
	}
	else {

		for (int i = 0; i<6; i++)
			eth.ether_dhost[i] = vic_mac[i];
	}


	for (int i = 0; i<6; i++) {
		eth.ether_shost[i] = my_mac[i];
	}

	eth.ether_type = htons(ETHERTYPE_ARP);

	memcpy(*packet, &eth, sizeof(eth));
	(*length) += sizeof(eth);

	//fill the arp request header
	arp.arp_hrd = htons(0x0001);
	arp.arp_pro = htons(0x0800);
	arp.arp_hln = 0x06;
	arp.arp_pln = 0x04;
	arp.arp_op = htons(opcode);

	for (int i = 0; i<6; i++) {
		arp.arp_sha[i] = my_mac[i];
	}

	if (opcode == ARPOP_REPLY) {
		for (int i = 0; i<6; i++)
			arp.arp_tha[i] = vic_mac[i];
	}
	else {
		for (int i = 0; i<6; i++)
			arp.arp_tha[i] = 0x00;
	}

	memcpy(arp.arp_spa, &my_ip, sizeof(my_ip));
	memcpy(arp.arp_tpa, &vic_ip, sizeof(vic_ip));

	memcpy((*packet) + (*length), &arp, sizeof(arp));
	(*length) += sizeof(arp);

}

int main(int argc, char *argv[]) {
	struct in_addr myIP;
	u_char myMAC[6];
	char ip[16];
	pcap_t *descr = NULL;
	char errbuf[PCAP_ERRBUF_SIZE], *device = NULL;
	struct in_addr vic_ip_addr;
	struct in_addr target_ip_addr;
	u_char *packet = (u_char *)malloc(sizeof(u_char) * 100);
	int length = 0;
	memset(errbuf, 0, PCAP_ERRBUF_SIZE);

	device = argv[1];

	printf("Opening device %s\n", device);

	get_ip_by_inf(&myIP, device);

	inet_ntop(AF_INET, &myIP, ip, sizeof(ip));

	printf("%s\n", ip);

	get_mac_by_inf(myMAC, device);

	for (int i = 0; i < 6; i++)
		printf("%02x ", myMAC[i]);
	printf("\n");

	descr = pcap_open_live(device, MAXBYTES2CAPTURE, 1, 512, errbuf);

	inet_pton(AF_INET, argv[2], &vic_ip_addr);
	make_arp_packet(&packet, &length, ARPOP_REQUEST, myIP, vic_ip_addr, myMAC, NULL);

	if (pcap_sendpacket(descr, packet, length) != 0) {
		fprintf(stderr, "\nError sending the packet : %s\n", pcap_geterr(descr));
		return -1;
	}

	free(packet);
	pcap_close(descr);
}

