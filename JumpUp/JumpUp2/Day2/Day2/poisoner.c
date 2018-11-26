#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>


#define MAXBYTES2CAPTURE 2048

typedef struct {
	u_char da[6];
	u_char sa[6];
	u_short type;
} V20; //ethernet

typedef struct {
	u_char vl;
	u_char tos;
	u_char t_len[2];
	u_char Id[2];
	u_char offset[2];
	u_char ttl;
	u_char protocol;
	u_char check[2];
	struct in_addr ip_src, ip_dst;
} V30; //IP

typedef struct arphdr {
	u_int16_t htype;
	u_int16_t ptype;
	u_char hlen;
	u_char plen;
	u_int16_t oper;
	u_char sha[6];
	u_char spa[4];
	u_char tha[6];
	u_char tpa[4];
} __attribute__((packed)) arphdr_t; //size 감소 dummy x cache x

void dumpcode(const u_char *, int);
void processPacket(int *, const struct pcap_pkthdr *, const u_char *);
int get_ip_by_inf(struct in_addr*, const char *);
int get_mac_by_inf(u_char mac[6], const char *);

int main(int argc, char *argv[])
{
	int count = 0, ret = 0;
	pcap_t *descr = NULL;
	struct pcap_pkthdr *header;
	const u_char *packet = NULL;
	char errbuf[PCAP_ERRBUF_SIZE], *device = NULL;
	struct bpf_program filter;
	bpf_u_int32 netaddr = 0, mask = 0;
	struct in_addr* myIP;
	u_char myMAC[6];
	memset(errbuf, 0, PCAP_ERRBUF_SIZE);

	device = pcap_lookupdev(errbuf);

	printf("Opening device %s\n", device);

	get_ip_by_inf(myIP, device);
	get_mac_by_inf(myMAC, device);

	printf("%s\n%s\n", myIP, myMAC);

	descr = pcap_open_live(device, MAXBYTES2CAPTURE, 1, 512, errbuf);

	if (pcap_compile(descr, &filter, "arp", 1, mask) == -1) {
		printf("%s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}

	if (pcap_setfilter(descr, &filter) == -1) {
		printf("%s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}

	while (1) {
		ret = pcap_next_ex(descr, &header, &packet);

		if (ret == 0)
			continue;

		if (ret == -1) {
			printf("%s\n", pcap_geterr(descr));
			exit(EXIT_FAILURE);
		}
		processPacket(&count, header, packet);
	}

	pcap_close(descr);

	return 0;
}

void processPacket(int* counter, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
	int i;
	V20* ethernet;
	arphdr_t *arp;

	printf("Packet Count : %d\n", ++(*counter));
	printf("Received Packet SIze : %d\n", pkthdr->len);
	printf("Payload : \n\n");

	ethernet = (struct V20 *)(packet);
	arp = (struct arphdr_t *)(packet + 14);

	printf("Destination : ");
	for (i = 0; i < 6; i++) {
		printf("%02x ", ethernet->da[i]);
	}
	printf("\n");

	printf("Start : ");
	for (i = 0; i < 6; i++) {
		printf("%02x ", ethernet->sa[i]);
	}
	printf("\n");

	printf("Type : ");
	printf("%04x ", ethernet->type);
	printf("\n");

	printf("Hardware address type : %02x\n", ntohs(arp->htype));
	printf("Protocol type : %04x\n", ntohs(arp->ptype));
	printf("Hardware length : %02x\n", arp->hlen);
	printf("Protocol length : %02x\n", arp->plen);
	printf("Operation : %02x\n", ntohs(arp->oper));	
	printf("Source hardware : ");
	for (i = 0; i < 6; i++) {
		printf("%02x ", arp->sha[i]);
	}
	printf("\n");
	printf("Source IP : ");
	for (i = 0; i < 4; i++) {
		printf("%02x ",arp->spa[i]);
	}
	printf("\n");
	printf("Destination hardware : ");
	for (i = 0; i < 6; i++) {
		printf("%02x ", arp->tha[i]);
	}
	printf("\n");
	printf("Destination IP : ");
	for (i = 0; i < 4; i++) {
		printf("%02x ", arp->tpa[i]);
	}
	printf("\n");

	dumpcode(packet, pkthdr->len);

	return;
}

void dumpcode(const u_char *buf, int len) {
	int i;

	printf("%7s", "offset ");
	for (i = 0; i < 16; i++) {
		printf("%02x ", i);

		if (!(i % 16 - 7))
			printf("- ");
	}

	printf("\n\r");

	for (i = 0; i < len; i++) {
		if (!(i % 16))
			printf("0x%04x ", i);

		printf("%02x ", buf[i]);

		if (!(i % 16 - 7))
			printf("- ");

		if (!(i % 16 - 15)) {
			putchar(' ');
			printf("\n\r");
		}
	}

	printf("\n\r");
}

int get_ip_by_inf(struct in_addr* ip, const char *dev) { //ip 받아오기
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

int get_mac_by_inf(u_char mac[6], const char *dev) { //mac 받아오기
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