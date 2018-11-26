#include "datasniffer.h"


DataSniffer::DataSniffer(string monDevice, string target, string etherDevice) : inf(monDevice) {
	NetworkInterface inf = NetworkInterface(etherDevice);
	NetworkInterface::Info info = inf.addresses();
	this->myMAC = HWAddress<6>(info.hw_addr);

	this->targetBSSID = HWAddress<6>(target);

	set = new std::set<HWAddress<6>>();

	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_rfmon(true);
	config.set_timeout(10);
	config.set_filter(this->filter);

	this->sniffer = new Sniffer(this->inf, config);
}

std::set<HWAddress<6>>* DataSniffer::getSet() {
	return this->set;
}

bool DataSniffer::isTargetAssociated(FRAME_DIRECTION fd, Dot11 *dot) {
	if (fd == TO_AP)
		return (dot->addr1() == targetBSSID);
	else if (fd == FROM_AP)
		return (dot->find_pdu<Dot11Data>()->addr2() == targetBSSID);
	else
		return false;
}

DataSniffer::FRAME_DIRECTION DataSniffer::getFrameDirection(Dot11 *dot) {
	if (dot->to_ds() && !dot->from_ds()) {
		return TO_AP;
	}
	else if (dot->from_ds() && !dot->to_ds()) {
		return FROM_AP;
	}
	else
		return OTHER;
}

void DataSniffer::sniffData() {
	while (flag) {
		Packet pk = sniffer->next_packet();
		if (pk.pdu() == NULL) continue;
		Dot11 *dot11 = pk.pdu()->find_pdu<Dot11>();

		if (dot11 == NULL) continue;
		Dot11Data *data = pk.pdu()->find_pdu<Dot11Data>();

		if (data == NULL) continue;

		FRAME_DIRECTION fd = getFrameDirection(dot11);

		if (!isTargetAssociated(fd, dot11)) {
			continue;
		}

		if (fd == TO_AP) {
			if(data->addr2() != myMAC)
				set->insert(data->addr2());

			if(data->addr3() != myMAC)
				set->insert(data->addr3());
		}
		else if (fd == FROM_AP) {
			if (data->addr1() != myMAC)
				set->insert(data->addr1());

			if (data->addr3() != myMAC)
				set->insert(data->addr3());
		}
		else {
			continue;
		}
	}
}