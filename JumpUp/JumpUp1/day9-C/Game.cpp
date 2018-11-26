#include <iostream>
#include "Game.hpp"
#include "Room.hpp"
#include "Player.hpp"
using namespace std;

Game::Game() {
	for (int i = 0; i < 5; i++) {
		r.push_back(new Room());
		room.push_back(r[i]);
	}

	room[0]->setRoom(nullptr, nullptr, room[4], room[1], 1, 1);
	room[1]->setRoom(room[2], room[3], room[0], nullptr, 2, 0);
	room[2]->setRoom(nullptr, room[1], nullptr, nullptr, 3, 2);
	room[3]->setRoom(room[1], nullptr, nullptr, nullptr, 4, 2);
	room[4]->setRoom(nullptr, nullptr, nullptr, room[0], 5, 3);

	r[2]->enemySet("Orc");
	r[3]->enemySet("Dragon");

	Player p(room[1]);

	while (p.PlayerOption()) {
		cout << endl << endl;
	}
}
Game::~Game() {
	for (int i = 0; i < r.size(); i++) {
		delete r[i];
		delete room[i];
	}
}
