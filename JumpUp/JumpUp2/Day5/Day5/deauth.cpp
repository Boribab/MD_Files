#include <tins/tins.h>
#include <iostream>

using namespace Tins;

enum FRAME_DIRECTION {
	TO_AP = 1,
	FROM_AP = 2,
	OTHER = 3
};

FRAME_DIRECTION getFrameDirection(Dot11 *dot) {
	if (dot->to_ds() && !dot->from_ds()) {
		return TO_AP;
	}
	else if (dot->from_ds() && !dot->to_ds()) {
		return FROM_AP;
	}
	else
		return OTHER;
}

int main(int argc, char* argv[]) {
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_filter("type data subtype data");
	config.set_rfmon(true);
	Sniffer sniffer(argv[1], config);

	while (1) {
		Packet packet = sniffer.next_packet();

		Dot11 *dot11 = packet.pdu()->find_pdu<Dot11>();

		Dot11Data *data = packet.pdu()->find_pdu<Dot11Data>();

		FRAME_DIRECTION ck = getFrameDirection(dot11);

		if (ck == TO_AP)
			std::cout << "To AP" << std::endl;
		else if (ck == FROM_AP)
			std::cout << "From AP" << std::endl;
		else
			std::cout << "other" << std::endl;
	}
}