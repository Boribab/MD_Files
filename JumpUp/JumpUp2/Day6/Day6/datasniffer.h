#ifndef DATASNIFFER_H
#define DATASNIFFER_H

#include <iostream>
#include <string>
#include <thread>
#include <set>
#include <tins/tins.h>

#include "safe_queue.h"

using namespace Tins;
using std::cout;
using std::endl;
using std::string;

class DataSniffer {
private:
	string inf;
	HWAddress<6> myMAC;
	HWAddress<6> targetBSSID;
	string filter = "type data subtype data";
	Sniffer *sniffer;
	std::set<HWAddress<6>> *set;

	bool flag = true;
	enum FRAME_DIRECTION {
		TO_AP = 1,
		FROM_AP = 2,
		OTHER = 3
	};
public :
	DataSniffer(string, string, string);
	void sniffData();
	bool isTargetAssociated(FRAME_DIRECTION fd, Dot11 *);
	FRAME_DIRECTION getFrameDirection(Dot11 *); 
	std::set<HWAddress<6>>* getSet();
};
#endif