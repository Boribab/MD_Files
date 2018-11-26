#include <iostream>
#include <string>
#include <stdlib.h>
#include "Room.h"
#include "Chest.h"

using namespace std;

class Player {
	Room *room;
	bool sword;
	int health = 1;
public:
	Player();

	Player(Room *room);

	void PlayerOption();

	void Attack(); 

	void openChest();
};