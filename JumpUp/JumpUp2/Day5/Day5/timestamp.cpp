#include <vector>
#include <tins/tins.h>
#include <iostream>

using namespace Tins;

int main(int argc, char* argv[]) {
	std::vector<Packet> vt;

	NetworkInterface iface = NetworkInterface::default_interface();

	Sniffer sniffer(iface.name());
	while (vt.size() != 10) {
		vt.push_back(sniffer.next_packet());
	}

	for (const auto& packet : vt) {
		if (packet.pdu()->find_pdu<IP>()) {
			std::cout << "At: " << packet.timestamp().seconds() << ", " << packet.pdu()->rfind_pdu<IP>().src_addr() << std::endl;
		}
	}
}