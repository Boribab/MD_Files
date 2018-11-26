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

#define MAXBYTES2CAPTURE 2048

typedef struct {
	u_char da[6];
	u_char sa[6];
	u_short type;
} V20;

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
} V30;

void dumpcode(const u_char *, int);
void processPacket(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char *argv[])
{
	int count = 0;
	pcap_t *descr = NULL;
	char errbuf[PCAP_ERRBUF_SIZE], *device = NULL;
	memset(errbuf, 0, PCAP_ERRBUF_SIZE);

	device = pcap_lookupdev(errbuf);

	printf("Opening device %s\n", device);

	descr = pcap_open_live(device, MAXBYTES2CAPTURE, 1, 512, errbuf);

	pcap_loop(descr, -1, processPacket, (u_char *)&count);

	pcap_close(descr);

	return 0;
}

void processPacket(u_char *arg, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
	int *counter = (int *)arg;
	int i;
	V20* ethernet;
	V30* ip;

	char sip[16];
	char dip[16];

	printf("Packet Count : %d\n", ++(*counter));
	printf("Received Packet SIze : %d\n", pkthdr->len);
	printf("Payload : \n\n");

	ethernet = (struct V20 *)(packet);
	ip = (struct V30 *)(packet + 14);

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

	if (ethernet->type == ntohs(0x0800)) {
		printf("SIP : ");
		inet_ntop(AF_INET, &(ip->ip_src), sip, sizeof(sip));
		printf("%s", sip);
		printf("\n");

		printf("DIP : ");
		inet_ntop(AF_INET, &(ip->ip_dst), dip, sizeof(dip));
		printf("%s", dip);
		printf("\n");
	}

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