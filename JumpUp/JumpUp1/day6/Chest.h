#pragma once
#include <iostream>
#include <string>
using namespace std;

class Chest {
	string item = " ";
	bool itemExist = false;
public:
	void setItem(string name);
	string giveItem();
	bool getExist();
	void noItem();
};