#include <tins/tins.h>
#include <iostream>

using namespace Tins;

int main(int argc, char* argv[]) {
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_filter("type mgt subtype beacon");
	config.set_rfmon(true);
	Sniffer sniffer(iface, config);

	int cnt = 100;

	while (cnt--) {
		Packet packet = sniffer.next_packet();

		Dot11Beacon *beacon = packet.pdu()->find_pdu<Dot11Beacon>();

		if (beacon != NULL) {
			cout << beacon.ssid() << beacon.addr2();
		}
	}
}