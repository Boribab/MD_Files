#include <stdio.h>
#include <iostream>
#include <pcap.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>
#include <string>
#include <set>
#include <sstream>
#include <iomanip>

using namespace std;

#define MAXBYTES2CAPTURE 2048

typedef struct ieeeRadioPrefix {
	uint8_t version;
	uint8_t pad;
	uint16_t len;
	uint32_t present;
} __attribute__((packed)) ieeeRadioPrefix;

typedef struct frameControl {
	uint8_t verTypeSubType;
	uint8_t flag;
} __attribute__((packed)) frameControl;

typedef struct ieee80211Hdr {
	frameControl fc;
	uint16_t durationId;
	uint8_t addr1[6];
	uint8_t addr2[6];
	uint8_t addr3[6];
	uint16_t seqCtl;
} __attribute__((packed)) ieee80211Hdr;

typedef struct beaconHdr {
	uint8_t timestamp[8];
	uint16_t beaconIT;
	uint16_t capabilityIF;
} __attribute__((packed)) beaconHdr;

int main(int argc, char *argv[])
{
	int i, channel;
	int count = 0, ret = 0;
	pcap_t *descr = NULL;
	struct pcap_pkthdr *header;
	struct ieee80211Hdr *ieeeHdr;
	struct V20 *ssid;
	const u_char *packet = NULL;
	char errbuf[PCAP_ERRBUF_SIZE], *device = NULL;
	struct bpf_program filter;
	struct ieeeRadioPrefix *radio;
	bpf_u_int32 netaddr = 0, mask = 0;

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

	if (pcap_compile(descr, &filter, "type mgt subtype beacon", 1, mask) == -1) {
		printf("%s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}

	if (pcap_setfilter(descr, &filter) == -1) {
		printf("%s\n", pcap_geterr(descr));
		exit(EXIT_FAILURE);
	}

	while (1) {
		string name;
		ret = pcap_next_ex(descr, &header, &packet);

		if (ret == 0)
			continue;

		if (ret == -1) {
			printf("%s\n", pcap_geterr(descr));
			exit(EXIT_FAILURE);
		}
		bool ssid_flag = false;
		bool channel_flag = false;

		radio = (struct ieeeRadioPrefix *)(packet);
		const u_char *tag = (packet + radio->len + sizeof(ieee80211Hdr) + sizeof(beaconHdr));
		int id = tag[0];
		int length = tag[1];
		string ssid;
		int channel;

		while (ssid_flag == false || channel_flag == false)
		{
			tag += 2;
			if (id == 0)
			{
				for (int i = 0; i < length; i++)
				{
					ssid.push_back(tag[i]);
				}

				ssid_flag = true;
			}
			//channel
			else if (id == 3)
			{
				channel = tag[0];
				channel_flag = true;
			}

			tag += length;
			id = tag[0];
			length = tag[1];
		}

		cout << "SSID : " << ssid << ", channel : " << channel << endl;
	}

	pcap_close(descr);

	return 0;
}