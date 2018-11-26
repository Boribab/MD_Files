#include "Room.h"

Room::Room() {

};

Room::Room(Room* e, Room* w, Room* s, Room* n, int num) {
	location[0] = e;
	location[1] = w;
	location[2] = s;
	location[3] = n;
	this->num = num;
}

void Room::setRoom(Room* e, Room* w, Room* s, Room* n, int num) {
	location[0] = e;
	location[1] = w;
	location[2] = s;
	location[3] = n;
	this->num = num;
}
int Room::getNum() {
	return num;
}
Room* Room::getRefe(int ans) {
	return location[ans];
}

void Room::enemySet(string name) {
	enemy.setName(name);
}

void Room::chestSet(string name) {
	chest.setItem(name);
}
string Room::getEName() {
	return enemy.getName();
}
bool Room::getAlive() {
	return enemy.getAlive();
}
void Room::kill() {
	enemy.kill();
}
string Room::getChestitem() {
	return chest.giveItem();
}
bool Room::getChestExist() {
	return chest.getExist();
}
void Room::noItem() {
	chest.noItem();
}
void Room::setFountain() {
	fountain.fountain();
}
bool Room::IsFountain() {
	return fountain.IsFountain();
}
bool Room::damage() {
	return enemy.damaged();
}