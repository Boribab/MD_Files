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

	cout << "������ �� �ִ� ���� (0 �Է½� ����)" << endl;

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
		cout << room->getNum() - 1 << "�� ������ �̵� ����" << endl;
	}
	else {
		cout << "���� ����" << endl;
	}

	if (room->getType() == 1) {
		openChest();
	}
	else if (room->getType() == 2) {
		Attack();
	}
	else if (room->getType() == 3) {
		if (room->IsFountain() == true) {
			cout << "ü�� +1 " << endl;
			health += 1;
		}
	}	
	return 1;
}

void Player::Attack() {
	if (room->getEName() != " " && room->getAlive() == 1) {
		cout << room->getEName() << "�� ��Ÿ��! " << endl;
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
		cout << "���� �߰�!  Open?(y/n) >> ";
		cin >> ans1;
		if (ans1 == 'y') {
			cout << "���ڿ��� " << room->getChestitem() << " �߰�" << endl;
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