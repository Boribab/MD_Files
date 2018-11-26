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

int main(int argc, char *argv[]) {
	struct in_addr myIP;
	u_char myMAC[6];
	char ip[16];
	char errbuf[PCAP_ERRBUF_SIZE], *device = NULL;
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
}