# MiniGame 보고서
## 일반
### 개요

요번 방학에 진행하는 JumpUp Camp를 통하여 C++에 대한 지식을 습득하고 그 지식을 기반으로 간단한 텍스트 기반 게임을 만들어 보았다. 

방향에 따른 숫자를 입력하여 맵을 이동하고 오브젝트와 상호작용하며 진행하는 방식의 게임이다.

플레이어의 입력에 따라 상자를 열지, 열지 않을지, 아이템을 얻을지,  얻지 않을지, 공격할지 하지 않을지와 같은 많은 선택지가 있다.

전투시에는 hp가 감소하는데 0 미만으로 내려가게 되면 게임오버가 되는데, 우물에 가서 hp를 채울 수 있다.

### 실행 환경 및 개발 환경
+ IDE : Visual Studio 2017

+ Compiler : Visual Studio 2017 c++

## 프로그램 설계
### 구조
![Structure](./MiniGame/Structure.png)
### 클래스 다이어그램
![ClassDiagram](./MiniGame/ClassDiagram.png)
### 시퀀스 다이어그램
![SequenceDiagram](./MiniGame/SequenceDiagram.png)
## 상세 설계
### class Game
```c++
// Game.h
#include <vector>
#include "Room.h"

class Game {
	vector<Room*> room; // 방향값을 담을 포인터 변수 벡터
	vector<Room*> r; // 내부 값을 담을 Room 변수 벡터
public:
	Game();
	~Game();
};
```
```c++
// Game.cpp
#include <iostream>
#include "Game.h"
#include "Room.h"
#include "Player.h"
using namespace std;

Game::Game() {
	for (int i = 0; i < 5; i++) { // 원하는 수만큼 맵 생성
		r.push_back(new Room());
		room.push_back(r[i]);
	}

	room[0]->setRoom(nullptr, nullptr, room[4], room[1], 1, 1); // 방향 설정
	room[1]->setRoom(room[2], room[3], room[0], nullptr, 2, 0);
	room[2]->setRoom(nullptr, room[1], nullptr, nullptr, 3, 2);
	room[3]->setRoom(room[1], nullptr, nullptr, nullptr, 4, 2);
	room[4]->setRoom(nullptr, nullptr, nullptr, room[0], 5, 3);

	r[2]->enemySet("Orc"); // 몬스터 설정 
	r[3]->enemySet("Dragon");

	Player p(room[1]); // 플레이어는 1번 방에서 시작

	while (p.PlayerOption()) { // 죽거나 나가기 전까지 루프
		cout << endl << endl;
	}
}
Game::~Game() { // 할당 해제
	for (int i = 0; i < r.size(); i++) {
		delete r[i];
		delete room[i];
	}
}
```

### class Player
```c++
// Player.h
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Room.h"
#include "Chest.h"

using namespace std;

class Player {
	Room *room; // 현재 플레이어가 있는 방
	bool sword; // 칼의 소유 여부
	int health = 1; // 플레이어 hp
public:
	Player();

	~Player();

	Player(Room *room);

	int PlayerOption();

	void Attack();

	void openChest();
};
```
```c++
// Player.cpp
#include "Player.h"

Player::Player() {
	sword = false;
}
Player::Player(Room *room) { 
	this->room = room; // 시작 방 지정
	sword = false; // 시작은 칼이 없음
}
int Player::PlayerOption() { // 전체적인 동작 프로그램
	if (health < 0) { // hp가 0보다 적을 시 게임오버
		cout << "YOU DIED" << endl;
		return 0;
	}

	cout << "움직일 수 있는 방향 (0 입력시 종료)" << endl;

	string s[4] = { "East(1)  ", "West(2)  ", "South(3)  ", "North(4)  " };

	for (int i = 0; i < 4; i++) {
		if (room->getRefe(i) != NULL) // 갈 수 있는 방향만 표시
			cout << s[i];
	}

	cout << ">> ";
	int ans;
	cin >> ans;

	if (ans == 0) return 0; // 0입력 시 종료

	if (room->getRefe(ans - 1) != NULL) { // 이동할 맵이 있을 시
		room = room->getRefe(ans - 1);
		cout << room->getNum() - 1 << "번 방으로 이동 성공" << endl;
	}
	else {
		cout << "길이 읎다" << endl;
	}

	if (room->getType() == 1) { // 타입에 따른 맵의 오브젝트 상호작용
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
	return 1; // 게임 계속 진행
}

void Player::Attack() { 
	if (room->getEName() != " " && room->getAlive() == 1) { // 몬스터가 생성 되었고 살아 있을 때
		cout << room->getEName() << "가 나타남! " << endl;
		cout << "Attack " << room->getEName() << "?(y/n) >>";
		char ans;
		cin >> ans;
		if (ans == 'y') { // 공격 했을 때
			if (sword == true) { // 칼이 있을 때
				room->damage();
				health -= 1;
			}
			else { // 칼이 없을 때
				cout << "You can't kill the " << room->getEName() << endl;
				health -= 1;
			}
		}
		else { // 도망갔을 때
			cout << "Damaged by " << room->getEName() << endl;
			health -= 1;
			return;
		}
	}
}
void Player::openChest() {
	if (room->getChestitem() != " " && room->getChestExist() == 1) { // 상자가 생성되었고 존재할 때
		char ans1;
		cout << "상자 발견!  Open?(y/n) >> ";
		cin >> ans1;
		if (ans1 == 'y') {
			cout << "상자에서 " << room->getChestitem() << " 발견" << endl;
			char ans2;
			cout << "Get? (y/n) >> ";
			cin >> ans2;
			if (ans2 == 'y') { // 칼 획득
				sword = true;
				room->noItem(); // 존재 false로 변경
			}
		}
	}
}

Player::~Player() { // 할당 해제
	delete room;
}
```
### class Room
```c++
// Room.h
#pragma once
#include <iostream>
#include <string>
#include "Chest.h"
#include "Fountain.h"
#include "Enemy.h"
using namespace std;

class Room {
	Room* location[4]; // 동서남북 방향에 대한 다른 맵 주소
	Chest *chest = nullptr; // 있을 시 할당
	Enemy *enemy = nullptr; // 있을 시 할당
	Fountain *fountain = nullptr; // 있을 시 할당
	int num, type; // 방의 번호와 타입
public:
	Room();
	~Room();
	Room(Room* e, Room* w, Room* s, Room* n, int num);
	void setRoom(Room* e, Room* w, Room* s, Room* n, int num ,int type);
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
	int getType();
};
```
```c++
// Room.cpp
#include "Room.h"

Room::Room() {

};
Room::~Room() { // 할당 해제
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
void Room::setRoom(Room* e, Room* w, Room* s, Room* n, int num, int type) { // 방 세팅
	location[0] = e;
	location[1] = w;
	location[2] = s;
	location[3] = n;
	this->num = num;
	this->type = type; // 0은 빈 방, 1은 상자 방, 2는 몬스터 방, 3은 우물
	
	if (type == 1) { // 타입에 따른 할당
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
int Room::getNum() { // 방 번호 리턴
	return num;
}
Room* Room::getRefe(int ans) { // 방 주소 리턴
	return location[ans];
}
void Room::enemySet(string name) { // 적 이름 세팅
	enemy->setName(name);
}
void Room::chestSet(string name) { // 상자 안의 아이템 세팅
	chest->setItem(name);
}
string Room::getEName() { // 방에 있는 몬스터 이름 리턴
	return enemy->getName();
}
bool Room::getAlive() { // 적이 살아있는지 리턴
	return enemy->getAlive();
}
void Room::kill() { // 적 사살
	enemy->kill();
}
string Room::getChestitem() { // 상자의 아이템 리턴
	return chest->giveItem();
}
bool Room::getChestExist() { // 상자의 존재 여부 리턴
	return chest->getExist();
}
void Room::noItem() { // 아이템 존재 여부 false로 변경
	chest->noItem();
}
void Room::setFountain() { // 우물 설정
	fountain->fountain();
}
bool Room::IsFountain() { // 우물의 여부 리턴
	return fountain->IsFountain();
}
bool Room::damage() { // 적이 죽었는지 리턴
	return enemy->damaged();
}
int Room::getType() { // 타입 리턴
	return type;
}
```
### class Chest
```c++
// Chest.h

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Chest {
	string item = " ";
	bool itemExist = false;
public:
	void setItem(string name);
	string giveItem();
	bool getExist();
	void noItem();
};
```
```c++
// Chest.cpp
#include "Chest.h"

void Chest::setItem(string name) { // 상자 안 아이템 생성
	item = name;
	itemExist = true;
}
string Chest::giveItem() { // 아이템 꺼내기
	if (itemExist == false) return " ";
	else { return item; }
}
bool Chest::getExist() { // 아이템 존재 여부
	return itemExist;
}
void Chest::noItem() { // 아이템을 꺼냈을 때
	itemExist = false;
}
```
### class Enemy
```c++
// Enemy.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Enemy {
	string name; // 몬스터의 이름
	int health = 3; // 몬스터의 기본 체력
	bool alive = true; // 몬스터의 생존 여부
	bool killed = false; // 몬스터의 죽음 여부
public:
	Enemy();

	void setName(string name);
	string getName();
	bool damaged();
	void kill();
	bool getAlive();
};
```
```c++
// Enemy.cpp
#include "Enemy.h"

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
bool Enemy::damaged() { // 몬스터의 피격
	health -= 1;
	if (health == 0) {
		kill();
		cout << "You killed the " << name << endl;
		return killed;
	}
}
void Enemy::kill() { // 몬스터 사살
	alive = false;
	killed = true;
}
bool Enemy::getAlive() { // 몬스터의 생존 여부
	return alive;
}
```
### class Fountain
```c++
// Fountain.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fountain {
	bool is = false;
public:
	void fountain();
	bool IsFountain();
};
```
```c++
// Fountain.cpp
#include "Fountain.h"

void Fountain::fountain() { // 우물로 설정
	is = true;
}
bool Fountain::IsFountain() { // 우물 여부 리턴
	return is;
}
```
## 시나리오
+ 진행 방식 - 사용자에게 이동할 방향을 입력받아 방을 움직이는 형식으로 진행

+ 게임이 끝나는 경우 - 사용자에게 exit을 입력받거나 죽으면 게임 끝
+ 죽는 경우 - 몬스터와 대면할 때마다 hp가 1씩 줄어드는데 0보다 적어지면 사망
+ 칼을 얻는 경우 - 0번 방의 상자에서 열기와 아이템 얻기 입력 값을 모두 y로 했을 시
+ 몬스터를 잡는 경우 - 칼을 소지하고 있고 hp가 0 미만으로 내려가지 않으면서 Attack 3번

## 실행 화면
![Run1](./MiniGame/Run1.png)
![Run2](./MiniGame/Run2.png)
![Run3](./MiniGame/Run3.png)