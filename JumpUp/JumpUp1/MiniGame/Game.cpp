#include <iostream>
#include "Game.h"
#include "Room.h"
#include "Player.h"
using namespace std;

Game::Game() {
	for (int i = 0; i < 5; i++) {
		r.push_back(new Room());
		room.push_back(r[i]);
	}

	r[0]->chestSet("Sword");
	r[1]->enemySet(" ");
	r[2]->enemySet("Dragon");
	r[3]->enemySet("Orc");
	r[4]->setFountain();

	room[0]->setRoom(nullptr, nullptr, room[4], room[1], 1);
	room[1]->setRoom(room[2], room[3], room[0], nullptr, 2);
	room[2]->setRoom(nullptr, room[1], nullptr, nullptr, 3);
	room[3]->setRoom(room[1], nullptr, nullptr, nullptr, 4);
	room[4]->setRoom(nullptr, nullptr, nullptr, room[0], 5);

	Player p(room[1]);

	while (true) {
		p.PlayerOption();
		cout << endl << endl;
	}
}