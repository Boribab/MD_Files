#include <tins/tins.h>
#include <iostream>

using namespace Tins;

int main(int argc, char* argv[]) {
	Dot11Beacon beacon;

	beacon.addr1(Dot11::BROADCAST);
	beacon.addr2("00:01:02:03:04:05");
	beacon.addr3(beacon.addr2());

	beacon.ssid("libtins");
	beacon.ds_parameter_set(8);
	beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

	beacon.rsn_information(RSNInformation::wpa2_psk());

	RadioTap radio = RadioTap();

	PacketSender *sender = new PacketSender(argv[1], 100);

	RadioTap pkt = radio / beacon;

	sender->send(pkt);
}