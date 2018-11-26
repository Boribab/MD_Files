#pragma once
#include <iostream>
#include <string>
#include "Chest.h"
#include "Fountain.h"
#include "Enemy.h"
using namespace std;

class Room {
	Room* location[4];
	Chest chest;
	Enemy enemy;
	Fountain fountain;
	bool player = false;
	int num;
public:
	Room();

	Room(Room* e, Room* w, Room* s, Room* n, int num);

	void setRoom(Room* e, Room* w, Room* s, Room* n, int num);

	int getNum();

	Room* getRefe(int ans);

	void enemySet(string name);

	void chestSet(string name);

	string getEName();

	bool getAlive();

	void kill();

	string getChestitem();

	bool getChestExist();

	void noItem();

	void setFountain();

	bool IsFountain();

	bool damage();
};
