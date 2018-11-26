#include "Chest.h"

void Chest::setItem(string name) {
	item = name;
	itemExist = true;
}
string Chest::giveItem() {
	if (itemExist == false) return " ";
	else { return item; }
}
bool Chest::getExist() {
	return itemExist;
}
void Chest::noItem() {
	itemExist = false;
}
