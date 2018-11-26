# 2018년 7월 25일 수요일 수업 일지
## Friend란?
+ class 내의 함수가 아니지만 private에 접근 가능

+ friend 반환형 함수 이름 ();으로 선언

### friend 예시
```c++
#include <iostream>
using namespace std;

class Rect;
bool equals(Rect r, Rect s);

class Rect {
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}
	friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
```
```
출력 :

not equal
```

## 연산자 함수
+ 객체에 +나 -를 했을 때 사용되는 함수

+ 클래스 내에 선언해도 되고 밖에 해도 됨
+ ex) 안에 선언 시 컴파일러가 c = a + b를 c = a . + b로 바꿈
+ ex) 밖에 선언 시 컴파일러가 c = a + b를 c = +( a, b )로 바꿈 <a, b는 객체>
+ 반환형 oprator연산자(매개변수 리스트);로 선언
### 연산자 함수
```c++
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator+ (Power op2);
	bool operator== (Power op2);
	Power operator+= (Power op2);
};

void Power::show() {
	cout << "kick = " << kick << "," << " punch = " << punch << endl;
}

Power Power::operator+(Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power op2) {
	if (kick == op2.kick && punch == op2.punch) return true;
	else return false;
}

Power Power::operator+= (Power op2) {
	kick = kick + op2.kick;
	punch = punch + op2.punch;

	return *this;
}

int main() {
	Power a(3, 5), b(4, 6), c;
	c = a += b;
	a.show();
	b.show();
	c.show();
}
```
```
출력 :

kick = 7, punch = 11
kick = 4, punch = 6
kick = 7, punch = 11
```
## 상속
+ 자식 클래스는 기존에 있던 클래스의 멤버는 그대로 사용하고 추가로 멤버 생성

+ 베이스가 되는 부모 클래스
+ class 자식클래스명:접근지정자 부모클래스 {};로 선언

### 상속의 기본
```c++
#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "( " << x << ", " << y << " )" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << " : ";
	showPoint();
}

int main() {
	Point p;
	ColorPoint cp;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
}
```
```
출력 :

Red : ( 3, 4 )
```

## 접근 지정자, protected
+ public 보다는 엄격하고 private보단 자유로운 지정자

+ 외부 함수에서 접근 불가능
+ 파생 클래스에서 접근 가능

### protected 예시
```c++
#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "( " << x << ", " << y << " )" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
	bool equals(ColorPoint p);
};

void ColorPoint::showColorPoint() {
	cout << color << " : ";
	showPoint();
}

bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color) return true; // private이었다면 error
	else return false;
}

int main() {
	Point p;
	p.set(2, 3);
	p.x = 5; // error
	p.y = 5; // error
	p.showPoint();

	ColorPoint cp;
	cp.x = 10; // error
	cp.y = 10; // error
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false");
}
```
## 기본 생성자
+ 자식 클래스에서 부모 클래스를 상속받을 때 기본 생성자가 없으면 오류 발생

+ 해결법 : default 매개변수 or 기본 생성자 생성 or 매개변수 직접 지정
+ default 매개변수 : class 부모 (int x = 0){};
+ 기본 생성자 생성 : class 부모() {...};
+ 매개변수 직접 지정 : class 자식():부모(int x = 0) {};

### 기본 생성자 예시
```c++
#include <iostream>
using namespace std;

class A {
public:
	A(int x = 0) {
		cout << "매개변수 생성자 A" << x << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "생성자 B" << endl;
	}
	B(int x):A(x + 3) {
		cout << "매개변수 생성자 B" << endl;
	}
};

int main() {
	B b;
}
```
```
출력 :

매개변수 생성자 A0
생성자 B
```
### 기본 생성자와 protected 예시
```c++
#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "BLACK") {
		move(x, y);
		this->color = color;
	}
	void setPoint(int x, int y) { move(x, y); }
	void setColor(string color) { this->color = color; }

	void show() { cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl; }
};

int main() {
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}
```
```
출력 :

BLACK색으로 (0,0)에 위치한 점입니다.
BLUE색으로 (10,20)에 위치한 점입니다.
```

## 연습문제
### BaseMemory
```c++
#include <iostream>
#include <cstring>
using namespace std;

class BaseMemory {
	char *mem;
protected:
	BaseMemory(int size = 1024) { mem = new char[size]; }
	~BaseMemory() { delete[] mem; }
	void burn(char arr[],int n) {
		strncpy(mem, arr, n);
	}
	char read(int i) { return mem[i]; }
	void write(int n, char c) { mem[n] = c; }
};

class ROM : public BaseMemory {
public:
	ROM(int size, char arr[],int arrs):BaseMemory(size) {
		burn(arr, arrs);
	}
	char read(int i) { return BaseMemory::read(i); }
};

class RAM : public BaseMemory {
public:
	RAM(int size) :BaseMemory(size) {}
	void write(int i, char c) { BaseMemory::write(i, c); }
	char read(int i) { return BaseMemory::read(i); }
};

int main() {
	char x[5] = { 'h', 'e', 'l', 'l', 'o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}
```
```
출력 :

hello
```
### OpenChallenge
```c++
#include <iostream>
#include <string>
using namespace std;

class Product {
	string descP, producer;
	int price, PID;
public:
	Product(string descP="", string producer = "", int price = 0, int PID = 0) {
		this->descP = descP;
		this->producer = producer;
		this->price = price;
		this->PID = PID;
	}
	
	virtual void write(string descP, string producer, int price, int PID) {
		this->descP = descP;
		this->producer = producer;
		this->price = price;
		this->PID = PID;
	}

	virtual void read() {
		cout << "--- 상품ID : " << PID << endl << "상품설명 : " << descP << endl << "생산자 : " << producer << endl << "가격 : " << price << endl;
	}
};

class Book:public Product {
	string Bname, author;
	int ISBN;
public:
	Book(string descP = "", string producer = "", int price = 0, int PID = 0, string Bname = "", string author = "", int ISBN = 0) :Product(descP, producer, price, PID) {
		this->Bname = Bname;
		this->author = author;
		this->ISBN = ISBN;
	}
	
	virtual void write(string descP, string producer, int price, int PID, string Bname, string author, int ISBN) {
		Product::write(descP, producer, price, PID);
		this->Bname = Bname;
		this->author = author;
		this->ISBN = ISBN;
	}
	virtual void read() {
		Product::read();
		cout << "ISBN : " << ISBN << endl << "책 제목 : " << Bname << endl << "저자 : " << author << endl;
	}
};

class CompactDisc:public Product {
	string DiscName, singer;
public:
	CompactDisc(string descP = "", string producer = "", int price = 0, int PID = 0, string DiscName = "", string singer = "") :Product(descP, producer, price, PID) {
		this->DiscName = DiscName;
		this->singer = singer;
	}
	virtual void write(string descP, string producer, int price, int PID, string DiscName, string singer) {
		Product::write(descP, producer, price, PID);
		this->DiscName = DiscName;
		this->singer = singer;
	}
	virtual void read() {
		Product::read();
		cout << "앨범 제목 : " << DiscName << endl << "가수 : " << singer << endl;
	}
};

class ConversationBook :public Book {
	string language;
public:
	virtual void write(string descP, string producer, int price, int PID, string Bname, string author, int ISBN, string language) {
		Book::write(descP, producer, price, PID, Bname, author, ISBN);
		this->language = language;
	}
	virtual void read() {
		Book::read();
		cout << "언어 : " << language << endl;
	}
};

int main() {
	int c, c2, pid = 0, ISBN, price;
	string descP, producer, Bname, author, language, DiscName, singer;
	Product *p[100];

	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
	
	while (1) {
		cout << "상품 추가 (1),  모든 상품 조회(2),  끝내기(3)  >>";
		cin >> c;
		switch (c) {
		case 1:
			cout << "상품 종류 : 책(1),  음악CD(2),  회화책(3)  >>";
			cin >> c2;
			switch (c2) {
			case 1:
				p[pid] = (Product*) new Book;
				cout << "상품 설명>>";
				cin.ignore();
				getline(cin, descP);
				cout << "생산자>>";
				cin >> producer;
				cout << "가격>>";
				cin >> price;
				cout << "책 제목>>";
				cin.ignore();
				getline(cin, Bname);
				cout << "저자>>";
				cin >> author;
				cout << "ISBN>>";
				cin >> ISBN;

				((Book*)p[pid++])->write(descP, producer, price, pid, Bname, author, ISBN);
				break;

			case 2:
				p[pid] = (Product*) new CompactDisc;
				cout << "상품 설명>>";
				cin.ignore();
				getline(cin, descP);
				cout << "생산자>>";
				cin >> producer;
				cout << "가격>>";
				cin >> price;
				cout << "앨범 제목>>";
				cin.ignore();
				getline(cin, DiscName);
				cout << "가수>>";
				cin >> singer;

				((CompactDisc*)p[pid++])->write(descP, producer, price, pid, DiscName, singer);
				break;

			case 3:
				p[pid] = (Product*) new ConversationBook;
				cout << "상품 설명>>";
				cin.ignore();
				getline(cin, descP);
				cout << "생산자>>";
				cin >> producer;
				cout << "가격>>";
				cin >> price;
				cout << "책 제목>>";
				cin.ignore();
				getline(cin, Bname);
				cout << "저자>>";
				cin >> author;
				cout << "ISBN>>";
				cin >> ISBN;
				cout << "언어>>";
				cin >> language;

				((ConversationBook*)p[pid++])->write(descP, producer, price, pid, Bname, author, ISBN, language);
				break;
			}
			break;
		case 2:
			for (int i = 0; i < pid; i++) {
				p[i]->read();
			}
			break;
		case 3:
			return 0;
		}
	}
}
```
```
출력&입력 :

***** 상품 관리 프로그램을 작동합니다 *****
상품 추가 (1),  모든 상품 조회(2),  끝내기(3)  >>1
상품 종류 : 책(1),  음악CD(2),  회화책(3)  >>3
상품 설명>>치믈리에
생산자>>치킨가게
가격>>15000
책 제목>>치믈리에 가이드
저자>>보리밥
ISBN>>110
언어>>한글
상품 추가 (1),  모든 상품 조회(2),  끝내기(3)  >>2
--- 상품ID : 1
상품설명 : 치믈리에
생산자 : 치킨가게
가격 : 15000
ISBN : 110
책 제목 : 치믈리에 가이드
저자 : 보리밥
언어 : 한글
상품 추가 (1),  모든 상품 조회(2),  끝내기(3)  >>3
```
### 내가 만든 문제
```c++
/*
대마고에는 8명의 학생이 있다. 공통과목은 국어, 수학이 있고 전공과목은 웹, 리눅스, 보안이 각각 있다.
개발과가 4명, 임베디드과가 2명, 보안과가 2명일 때
학생의 성적을 입력하거나 보여주는 프로그램을 만드시오.

// class 기본 틀

class Student {
int kor, math;
	string name;
public:
	Student();
	void show();
	void setName();
};

class Develop:public Student {
	int web;
public:
	Develop();
	void show();
};

class Embedded:public Student {
	int web;
public:
	Embedded();
	void show();
};

class Security:public Student {
	int web;
public:
	Security();
	void show();
};
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
	int kor, math;
	string name;
public:
	Student() {
		cout << "학생의 이름 >> ";
		cin.ignore();
		getline(cin, name);
		cout << "국어 성적 >> ";
		cin >> kor;
		cout << "수학 성적 >> ";
		cin >> math;
	}
	void show() {
		cout << endl << "학생의 이름 : " << name << endl << "국어 성적 : " << kor << endl << "수학 성적 : " << math << endl;
	}
	void setName(string name) {
		this->name = name;
	}
};

class Develop:public Student {
	int web;
public:
	Develop() {
		cout << "웹 성적 >> ";
		cin >> web;
	}

	void show() {
		Student::show();
		cout << "웹 성적 : " << web << endl << endl;
	}
};

class Embedded:public Student {
	int linux;
public:
	Embedded() {
		cout << "리눅스 성적 >> ";
		cin >> linux;
	}
	void show() {
		Student::show();
		cout << "리눅스 성적 : " << linux << endl << endl;
	}
};

class Security:public Student {
	int security;
public:
	Security() {
		cout << "보안 성적 >> ";
		cin >> security;
	}
	void show() {
		Student::show();
		cout << "보안 성적 : " << security << endl << endl;
	}
};

int main() {
	int n, n2, dc = 0, ec = 0, sc = 0;
	Develop *d[4];
	Embedded *e[2];
	Security *s[2];

	cout << "--- 성적 시스템 시작 ---" << endl;

	while (1) {
		cout << "학생 추가(1)   성적 확인(2)   끝내기(3) >>> ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "개발과(1)   임베디드과(2)   보안과(3) >>> ";
			cin >> n2;
			switch (n2) {
			case 1:
				d[dc] = new Develop();
				dc++;
				break;
			case 2:
				e[ec] = new Embedded();
				ec++;
				break;
			case 3:
				s[sc] = new Security();
				sc++;
				break;
			}
			break;
		case 2:
			cout << "개발과(1)   임베디드과(2)   보안과(3) >>> ";
			cin >> n2;
			switch (n2) {
			case 1:
				for (int i = 0; i < dc; i++)
					d[i]->show();
				break;
			case 2:
				for (int i = 0; i < ec; i++)
					e[i]->show();
				break;
			case 3:
				for (int i = 0; i < sc; i++)
					s[i]->show();
				break;
			}
			break;
		case 3:
			return 0;
		}
	}
}
```
```
출력&입력 :

--- 성적 시스템 시작 ---
학생 추가(1)   성적 확인(2)   끝내기(3) >>> 1
개발과(1)   임베디드과(2)   보안과(3) >>> 3
학생의 이름 >> 박보현
국어 성적 >> 100
수학 성적 >> 90
보안 성적 >> 80
학생 추가(1)   성적 확인(2)   끝내기(3) >>> 2
개발과(1)   임베디드과(2)   보안과(3) >>> 3

학생의 이름 : 박보현
국어 성적 : 100
수학 성적 : 90
보안 성적 : 80

학생 추가(1)   성적 확인(2)   끝내기(3) >>> 3
```