# 2018년 7월 23일 월요일 수업 일지
## C++에 대한 기초
1. 객체 지향 언어

2. C와 문법 공유
## Hello.cpp
```c++
#include <iostream>

int main() {
    std::cout << "Hello, there!" << std::endl;
    
    return 0;
}
```
```
출력 : Hello, there!
```
+ c언어와 비슷한 구조를 갖고 있음

+ stdio.h 대신 iostream

+ #include `<>` - 컴파일러 제공 |  #include `""` - 사용자 헤더

## 기본 문법을 이용한 구구단 프로그램

```c++
#include<iostream>

int main() {
	int i, j;

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			std::cout << j << " * " << i << " = " << i*j << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}
```
```
출력 : 
1 * 1 = 1       2 * 1 = 2       3 * 1 = 3       4 * 1 = 4       5 * 1 = 5       6 * 1 = 6       7 * 1 = 7       8 * 1 = 8       9 * 1 = 9
1 * 2 = 2       2 * 2 = 4       3 * 2 = 6       4 * 2 = 8       5 * 2 = 10      6 * 2 = 12      7 * 2 = 14      8 * 2 = 16      9 * 2 = 18
1 * 3 = 3       2 * 3 = 6       3 * 3 = 9       4 * 3 = 12      5 * 3 = 15      6 * 3 = 18      7 * 3 = 21      8 * 3 = 24      9 * 3 = 27
1 * 4 = 4       2 * 4 = 8       3 * 4 = 12      4 * 4 = 16      5 * 4 = 20      6 * 4 = 24      7 * 4 = 28      8 * 4 = 32      9 * 4 = 36
1 * 5 = 5       2 * 5 = 10      3 * 5 = 15      4 * 5 = 20      5 * 5 = 25      6 * 5 = 30      7 * 5 = 35      8 * 5 = 40      9 * 5 = 45
1 * 6 = 6       2 * 6 = 12      3 * 6 = 18      4 * 6 = 24      5 * 6 = 30      6 * 6 = 36      7 * 6 = 42      8 * 6 = 48      9 * 6 = 54
1 * 7 = 7       2 * 7 = 14      3 * 7 = 21      4 * 7 = 28      5 * 7 = 35      6 * 7 = 42      7 * 7 = 49      8 * 7 = 56      9 * 7 = 63
1 * 8 = 8       2 * 8 = 16      3 * 8 = 24      4 * 8 = 32      5 * 8 = 40      6 * 8 = 48      7 * 8 = 56      8 * 8 = 64      9 * 8 = 72
1 * 9 = 9       2 * 9 = 18      3 * 9 = 27      4 * 9 = 36      5 * 9 = 45      6 * 9 = 54      7 * 9 = 63      8 * 9 = 72      9 * 9 = 81
```
+ c와 같은 반복문 for 사용

## using namespace
### namespace란
+ 어디에 포함되어 있는지 나타내어 주는 것 

+ ex) std, 클래스명 등등
+ 생략하기 위해 `'using namespace 이름'` 사용

```c++
#include <iostream>
using namespace std;

int main() {
	cout << "너비를 입력하세여>>";
	int width;

	cin >> width;
	cout << "높이를 입력하세여>>";

	int height;
	cin >> height;

	int area = width*height;
	cout << "면적은 " << area << "\n";
}
```
```
3 5

출력 : 15
```

## string 라이브러리
+ #include `<string>` 
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;

	cout << song + "를 부른 가수는? ";
	cout << "(힌트 : 첫글자는 " << elvis[0] << ") : ";

	getline(cin, singer);
	if (singer == elvis)
		cout << "맞았습니다" << endl;
	else
		cout << "틀렸습니다. " + elvis + "입니다." << endl;
}
```
```
Elvis Presly

출력 : 맞았습니다
```
+ string이라는 자료형 사용 가능
+ getline(cin, singer) -> cin으로 singer에 문자열 입력(공백 포함) 

## string 라이브러리를 이용한 간단한 문자열 출력
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int len, i = 0, j;

	getline(cin, str);
	len = str.length();

	while (i < len) {
		for (j = 0; j <= i; j++) {
			cout << str[j];
		}
		cout << endl;
		i++;
	}
}
```
```
HELLO

출력:
H
HE
HEL
HELL  
HELLO
```

## Class란
+ C언어의 구조체와 비슷한 개념

+ 객체를 생성할 수 있다.
+ Class 기본 접근 제한 : private
+ Struct 기본 접근 제한 : public

### 날짜 출력
```c++
#include <iostream>
using namespace std;

class Date {
public:
	int year, month, day;
	int getYear();
	int getMonth();
	int getDay();
};

int Date::getYear() {
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

int main() {
	Date birth;
	birth.year = 2014;
	birth.month = 3;
	birth.day = 20;
	cout << birth.getYear() << "." << birth.getMonth() << "." << birth.getDay() << endl;
}
```
```
출력 : 2014.3.20
```
### 면적 구하기
```c++
#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	donut.radius = 1;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
```
```
출력:
donut 면적은 3.14
pizza 면적은 2826
```
## 생성자란?
+ 객체가 생성되고 바로 호출되는 함수

+ 생성자를 임의로 만들어주지 않으면 컴파일러가 생성해줌
+ 오버로딩 가능
+ private 안에 넣어놓으면 생성 안됨

### 생성자를 통한 면적 구하기
```c++
#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle() {
	radius = 1;
	return;
}

Circle::Circle(int r) {
	radius = r;
	return;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
```
```
출력: 
donut 면적은 3.14
pizza 면적은 2826
```
### 클래스를 이용해 커피 자판기 구현
```c++
#include <iostream>
using namespace std;

class CoffeeMachine {
private:
	int water, coffee, sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();
};

CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	water = w;
	coffee = c;
	sugar = s;
}

void CoffeeMachine::drinkEspresso() {
	water -= 1;
	coffee -= 1;
}

void CoffeeMachine::drinkAmericano() {
	water -= 2;
	coffee -= 1;
}

void CoffeeMachine::drinkSugarCoffee() {
	water -= 2;
	coffee -= 1;
	sugar -= 1;
}

void CoffeeMachine::show() {
	cout << "커피머신 상태, 커피:" << coffee << " 물:" << water << " 설탕:" << sugar << endl;
}

void CoffeeMachine::fill() {
	water = 10;
	sugar = 10;
	coffee = 10;
}

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}
```
```
출력:
커피머신 상태, 커피:4 물:9 설탕:3
커피머신 상태, 커피:3 물:7 설탕:3
커피머신 상태, 커피:2 물:5 설탕:2
커피머신 상태, 커피:10 물:10 설탕:10
```
## 나만의 게임 제작
+ Critter 키우기
```c++
#include <iostream>
using namespace std;

class Critter {
private:
	int m_Hunger = 0, m_Boredom = 0;
	void getMood();
	void passTime();
public:
	void talk();
	void eat();
	void play();
};

void Critter::getMood() {
	cout << "Feeling : " << m_Boredom << endl;
}

void Critter::passTime() {
	m_Hunger += 1;
	m_Boredom += 1;
}

void Critter::talk() {
	if (m_Hunger < 5 && m_Boredom < 5) cout << "I'm good" << endl;
	else if (m_Hunger < 10 && m_Boredom < 10) cout << "Not bad" << endl;
	else if (m_Hunger < 15 && m_Boredom < 15) cout << "Not good" << endl;
	else cout << "GRRRR" << endl;

	getMood();
	passTime();
}

void Critter::eat() {
	m_Hunger -= 2;
	getMood();
	passTime();
}

void Critter::play() {
	m_Boredom -= 2;
	getMood();
	passTime();
}

int main() {
	int n;

	Critter pet;

	cout << "Critter Caretaker" << endl << endl;

	while (1) {
		cout << endl << "0 - Quit" << endl << "1 - Talk with your Critter" << endl << "2 - Feed your Critter" << endl << "3 - Play with your Critter" << endl << endl;

		cin >> n;

		if (n == 0) break;

		switch (n) {
		case 1:
			pet.talk();
			break;
		case 2:
			pet.eat();
			break;
		case 3:
			pet.play();
		}
	}
}
```
```
출력 & 입력:

Critter Caretaker


0 - Quit
1 - Talk with your Critter
2 - Feed your Critter
3 - Play with your Critter

1
I'm good
Feeling : 0

0 - Quit
1 - Talk with your Critter
2 - Feed your Critter
3 - Play with your Critter

2
Feeling : 1

0 - Quit
1 - Talk with your Critter
2 - Feed your Critter
3 - Play with your Critter

3
Feeling : 0

0 - Quit
1 - Talk with your Critter
2 - Feed your Critter
3 - Play with your Critter
```