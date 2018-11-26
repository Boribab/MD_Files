#pragma once
#include <iostream>
#include <string>
using namespace std;

class Enemy {
	string name;
	int health = 3;
	bool alive = true;
	bool killed = false;
public:
	Enemy();

	void setName(string name);
	string getName();
	bool damaged();
	void kill();
	bool getAlive();
};