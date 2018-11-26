#include <iostream>
#include <string>
#include <thread>
#include <set>
#include <tins/tins.h>

using namespace Tins;
using std::cout;
using std::endl;
using std::string;
using std::set;


class DeauthSender{
private:
	string inf;
	bool flag = true;
	const int SEND_NUM_PER_STA = 5;
	HWAddress<6> targetBSSID;
public:
	DeauthSender(string inf, string bssid);
	void sendDeauth(set<HWAddress<6>> *addressSet);

	std::thread getSendThread(set<HWAddress<6>> *addressSet);
};