#include <tins/tins.h>
#include <iostream>
#include <set>

using namespace Tins;

Tins::HWAddress<6> targetBSSID1;

std::set<HWAddress<6>> list;

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

bool isTargetAssociated(FRAME_DIRECTION fd, Dot11 *dot) {
	if (fd == TO_AP)
		return (dot->addr1() == targetBSSID);
	else if (fd == FROM_AP)
		return (dot->find_pdu<Dot11Data>()->addr2() == targetBSSID);
	else
		return false;
}


int main(int argc, char* argv[]) {
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_filter("type data subtype data");
	config.set_rfmon(true);
	Sniffer sniffer(argv[1], config);
	HWAddress<6> targetBSSID = HWAddress<6>(argv[2]);
	targetBSSID1 = targetBSSID;

	while (1) {
		Packet packet = sniffer.next_packet();

		Dot11 *dot11 = packet.pdu()->find_pdu<Dot11>();

		Dot11Data *data = packet.pdu()->find_pdu<Dot11Data>();

		FRAME_DIRECTION fd = getFrameDirection(dot11);

		if (!isTargetAssociated(fd, dot11))
			continue;

		if (fd == TO_AP) {
			if (dot->find_pdu<Dot11Data>()->addr2() != targetBSSID1)
				list.insert(dot->find_pdu<Dot11Data>()->addr2());
			if (dot->find_pdu<Dot11Data>()->addr3() != targetBSSID1)
				list.insert(dot->find_pdu<Dot11Data>()->addr3());
		}
		else if (fd == FROM_AP) {
			if (dot->addr1() != targetBSSID1)
				list.insert(dot->find_pdu<Dot11Data>()->addr2());
			if (dot->find_pdu<Dot11Data>()->addr3() != targetBSSID1)
				list.insert(dot->find_pdu<Dot11Data>()->addr3());
		}


		for (auto iter = list.begin(); iter != list.end(); ++iter) {
			std::cout << *iter << std::endl;
		}
		std::cout << std::endl;
	}
}