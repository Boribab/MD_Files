#include "Enemy.hpp"

Enemy::Enemy()
{
	name = " ";
}

void Enemy::setName(string name) {
	this->name = name;
}
string Enemy::getName() {
	return name;
}
bool Enemy::damaged() {
	health -= 1;
	if (health == 0) {
		kill();
		cout << "You killed the " << name << endl;
		return killed;
	}
}
void Enemy::kill() {
	alive = false;
	killed = true;
}
bool Enemy::getAlive() {
	return alive;
}
