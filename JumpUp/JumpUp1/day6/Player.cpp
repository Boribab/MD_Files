#include "Player.h"

Player::Player() {
	sword = false;
}
Player::Player(Room *room) {
	this->room = room;
	sword = false;
}
int Player::PlayerOption() {
	if (health < 0) {
		cout << "YOU DIED" << endl;
		return 0;
	}

	cout << "움직일 수 있는 방향 (0 입력시 종료)" << endl;

	string s[4] = { "East(1)  ", "West(2)  ", "South(3)  ", "North(4)  " };

	for (int i = 0; i < 4; i++) {
		if (room->getRefe(i) != NULL)
			cout << s[i];
	}

	cout << ">> ";
	int ans;
	cin >> ans;

	if (ans == 0) return 0;

	if (room->getRefe(ans - 1) != NULL) {
		room = room->getRefe(ans - 1);
		cout << room->getNum() - 1 << "번 방으로 이동 성공" << endl;
	}
	else {
		cout << "길이 읎다" << endl;
	}

	if (room->getType() == 1) {
		openChest();
	}
	else if (room->getType() == 2) {
		Attack();
	}
	else if (room->getType() == 3) {
		if (room->IsFountain() == true) {
			cout << "체력 +1 " << endl;
			health += 1;
		}
	}	
	return 1;
}

void Player::Attack() {
	if (room->getEName() != " " && room->getAlive() == 1) {
		cout << room->getEName() << "가 나타남! " << endl;
		cout << "Attack " << room->getEName() << "?(y/n) >>";
		char ans;
		cin >> ans;
		if (ans == 'y') {
			if (sword == true) {
				room->damage();
				health -= 1;
			}
			else {
				cout << "You can't kill the " << room->getEName() << endl;
				health -= 1;
			}
		}
		else {
			cout << "Damaged by " << room->getEName() << endl;
			health -= 1;
			return;
		}
	}
}
void Player::openChest() {
	if (room->getChestitem() != " " && room->getChestExist() == 1) {
		char ans1;
		cout << "상자 발견!  Open?(y/n) >> ";
		cin >> ans1;
		if (ans1 == 'y') {
			cout << "상자에서 " << room->getChestitem() << " 발견" << endl;
			char ans2;
			cout << "Get? (y/n) >> ";
			cin >> ans2;
			if (ans2 == 'y') {
				sword = true;
				room->noItem();
			}
		}
	}
}

Player::~Player() {
	delete room;
}