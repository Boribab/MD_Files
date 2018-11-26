#include "Room.h"

Room::Room() {

};
Room::~Room() {
	delete enemy;
	delete fountain;
	delete chest;
}
Room::Room(Room* e, Room* w, Room* s, Room* n, int num) {
	location[0] = e;
	location[1] = w;
	location[2] = s;
	location[3] = n;
	this->num = num;
}
void Room::setRoom(Room* e, Room* w, Room* s, Room* n, int num, int type) {
	location[0] = e;
	location[1] = w;
	location[2] = s;
	location[3] = n;
	this->num = num;
	this->type = type;
	
	if (type == 1) {
		chest = new Chest();
		chest->setItem("Sword");
	}
	else if (type == 2) {
		enemy = new Enemy();
	}
	else if (type == 3) {
		fountain = new Fountain();
		fountain->fountain();
	}
}
int Room::getNum() {
	return num;
}
Room* Room::getRefe(int ans) {
	return location[ans];
}
void Room::enemySet(string name) {
	enemy->setName(name);
}
void Room::chestSet(string name) {
	chest->setItem(name);
}
string Room::getEName() {
	return enemy->getName();
}
bool Room::getAlive() {
	return enemy->getAlive();
}
void Room::kill() {
	enemy->kill();
}
string Room::getChestitem() {
	return chest->giveItem();
}
bool Room::getChestExist() {
	return chest->getExist();
}
void Room::noItem() {
	chest->noItem();
}
void Room::setFountain() {
	fountain->fountain();
}
bool Room::IsFountain() {
	return fountain->IsFountain();
}
bool Room::damage() {
	return enemy->damaged();
}
int Room::getType() {
	return type;
}
