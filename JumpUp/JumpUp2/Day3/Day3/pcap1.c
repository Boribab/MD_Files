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

typedef struct ieeeRadioPrefix {
	uint8_t version;
	uint8_t pad;
	uint16_t len;
	uint32_t present;
} __attribute__((packed)) ieeeRadioPrefix;

void dumpcode(const u_char *, int);

int main(int argc, char *argv[])
{
	int count = 0, ret = 0;
	pcap_t *descr = NULL;
	struct pcap_pkthdr *header;
	const u_char *packet = NULL;
	char errbuf[PCAP_ERRBUF_SIZE], *device = NULL;
	struct bpf_program filter;
	struct ieeeRadioPrefix *radio;
	bpf_u_int32 netaddr = 0, mask = 0;
	memset(errbuf, 0, PCAP_ERRBUF_SIZE);

	device = argv[1];

	printf("Opening device %s\n", device);

	descr = pcap_create(device, errbuf);

	if (pcap_can_set_rfmon(descr) == 0) {
		fprintf(stderr, "Couldn't set monitor mode %s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}

	if (pcap_set_rfmon(descr, 1)) {
		fprintf(stderr, "Failed to set monitor mode %s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}

	if (pcap_set_snaplen(descr, BUFSIZ)) {
		fprintf(stderr, "Couldn't set buff size of pcap handle %s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}
	
	if (pcap_set_timeout(descr, 10)) {
		fprintf(stderr, "Couldn't set timeout of pcap handle %s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}

	if (pcap_activate(descr)) {
		fprintf(stderr, "Couldn't active pcap handle %s\n", pcap_geterr(descr));
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
		radio = (struct ieeeRadioPrefix *)(packet);
		//dumpcode(packet, header->len);

		printf("ieeeRadioPrefix length : %d\n\n", radio->len);
	}

	pcap_close(descr);

	return 0;
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