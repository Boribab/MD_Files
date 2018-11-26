#include <iostream>
#include <tins/tins.h>
#include <cassert>
#include <string>

using namespace Tins;

int main() {
	NetworkInterface iface = NetworkInterface::default_interface();

	NetworkInterface::Info info = iface.addresses();

	EthernetII eth = EthernetII("77:22:33:11:ad:ad", info.hw_addr) /
		IP("192.168.0.1", info.ip_addr) /
		TCP(13, 15) /
		RawPDU("I'm a payload!");

	PacketSender sender;
	sender.send(eth, iface);
}