# 2018년 7월 24일 화요일 수업 일지
## 객체 배열이란?
+ 말 그대로 객체를 담은 배열

+ 자료형을 Class 이름으로 선언
### 객체 배열 선언
```c++
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r = 1) { radius = r; }
	double getArea() {
		return 3.14*radius*radius;
	}
};

int main() {
	Circle waffle(15);
	Circle circleArray[3];
}
```
+ Circle circleArray[3] = { Circle(10), Circle(20), Circle() }와 같이 생성과 동시에 초기화 가능
### 2차원 객체 배열을 통한 원의 면적
```c++
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circles[2][3] = { Circle(1), Circle(2) , Circle(3) , Circle(4) , Circle(5) , Circle(6) };

	/*
        circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);
    */

	for (int i = 0; i < 2 ; i++)
		for (int j = 0; j < 3; j++) {
			cout << "Circle [" << i << "," << j << "]의 면적은 ";
			cout << circles[i][j].getArea() << endl;
		}
}
```
```
출력 :
Circle [0,0]의 면적은 3.14
Circle [0,1]의 면적은 12.56
Circle [0,2]의 면적은 28.26
Circle [1,0]의 면적은 50.24
Circle [1,1]의 면적은 78.5
Circle [1,2]의 면적은 113.04
```

## 객체의 동적할당
+ c언어에서 malloc과 free가 있다면 C++에는 new와 delete가 있음

+ 자료형 *변수명 = new 자료형[크기]; 의 꼴로 선언

### 수를 입력받아 합과 평균 구해보기
```c++
#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	
	cin >> n;

	int *p = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		sum += p[i];
	}

	delete[] p;

	cout << "합 : " << sum << ", 평균 : " << sum/n << endl;
}
```
```
3
1 2 3

출력: 합 : 6, 평균 : 2
```
### 객체 배열과 동적 할당을 통한 가장 큰 수 찾는 프로그램
```c++
#include <iostream>
using namespace std;

class Sample {
	int *p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++)
		cin >> p[i];
}

void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << p[i] << " ";
}

int Sample::big() {
	int max = p[0];

	for (int i = 1; i < size; i++)
		if (p[i] > max) max = p[i];

	return max;
}

Sample::~Sample() {
	delete[] p;
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
}
```
```
3
1
5
3
7
8
3
5
1
124

출력:
3 1 5 3 7 8 3 5 1 124 가장 큰 수는 124
```
+ 소멸자 : 객체가 소멸할 때 실행되는 것
+ 생성자와는 다르게 중복 선언할 수 없음
+ ~ClassName();으로 선언

### 동적 할당과 생성자 소멸자를 통한 원 면적 구하기
```c++
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) {
		radius = r;
		cout << "생성자 실행 radius = " << radius << endl;
	}
	double getArea();
	~Circle() {
		cout << "소멸자 실행 radius = " << radius << endl;
	}
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	int n;

	while (1) {
		cout << "정수 반지름 입력(음수이면 종료)" << endl;
		cin >> n;
		if (n < 0) break;

		Circle *p = new Circle(n);

		cout << "원의 면적은 " << p->getArea() << endl;

		delete p;
	}
}
```
```
입력&출력 :

정수 반지름 입력(음수이면 종료)
3
생성자 실행 radius = 3
원의 면적은 28.26
소멸자 실행 radius = 3
정수 반지름 입력(음수이면 종료)
2
생성자 실행 radius = 2
원의 면적은 12.56
소멸자 실행 radius = 2
정수 반지름 입력(음수이면 종료)
5
생성자 실행 radius = 5
원의 면적은 78.5
소멸자 실행 radius = 5
정수 반지름 입력(음수이면 종료)
-1
```
+ 클래스의 참조 `.`
+ 포인터 변수의 참조 `->`
+ ex) p->getArea();

## this란?
+ 같은 이름의 변수가 존재할 때, 함수의 매개변수가 아닌 객체의 멤버 변수의 앞에 붙여주는 것
 
+ 평소에는 컴파일러가 알아서 붙여줌
+ 멤버 함수가 아닌 함수나 static에서는 사용 불가능

### this를 사용한 100보다 크고 200보다 작은 원의 면적 개수 구하는 프로그램
```c++
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void read() {
		cin >> radius;
	}
	int check() {
		if (getArea() >= 100 && getArea() <= 200) return 1;
		else return 0;
	}
	void write() {
		cout << getArea() << " ";
	}
	double getArea() {
		return 3.14*radius*radius;
	}
};

int main() {
	int n, count = 0;
	cout << "원개수 : ";
	cin >> n;

	Circle *c = new Circle[n];

	for (int i = 0; i < n; i++) {
		cout << "원" << i + 1 << ":";
		c[i].read();
		count += c[i].check();
	}

	for (int i = 0; i < n; i++) {
		c[i].write();
	}
	cout << endl << "개수 : " << count << endl;

	delete[] c;
}
```
```
원개수 : 3
원1:5
원2:6
원3:7

출력 :

78.5 113.04 153.86
개수 : 2
```
### Class와 this 연산자를 사용한 가족 이름 나타내는 프로그램
```c++
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person(string name = "") { this->name = name; }
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};

class Family {
	Person *p;
	int size;
public:
	Family(string name, int size) : size(size) {
		cout << name << " 가족은 다음과 같이 " << size << "명 입니다." << endl;
		p = new Person[size];
	}
	void show();
	void setName(int n, string name) {
		p[n].setName(name);
	}
	~Family() {
		delete[] p;
	}
};

void Family::show() {
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << " ";
	}
}

int main() {
	Family *simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	cout << endl;
	delete simpson;
}
```
```
출력 :
Simpson 가족은 다음과 같이 3명 입니다.
Mr. Simpson Mrs. Simpson Bart Simpson
```
### 원의 이름과 반지름을 받고 검색하는 프로그램
```c++
#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) {
		this->name = name;
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
	string getName() {
		return name;
	}
};

class CircleManager {
	Circle *p;
	int size;
public:
	CircleManager(int size) {
		p = new Circle[size];
		this->size = size;
	}
	~CircleManager() {
		delete[] p;
	}
	void setCircle(string name, int arrn, int a) {
		p[a].setCircle(name, arrn);
	}
	void searchByName(string name) {
		for (int i = 0; i < size; i++) {
			if (p[i].getName() == name) cout << p[i].getArea()<< endl;
		}
	}
	void searchByArea(double arrn) {
		for (int i = 0; i < size; i++) {
			if (p[i].getArea() >= arrn) cout << p[i].getName()<< "의 면적은 "<< p[i].getArea() << ", ";
		}
	}
};

int main() {
	int n, arrn;
	string name;
	cout << "원의 개수 >> ";
	cin >> n;

	CircleManager c(n);

	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 : ";
		cin >> name >> arrn;
		c.setCircle(name, arrn, i);
	}

	cout << "원의 이름 : ";
	cin >> name;
	c.searchByName(name);

	cout << "원의 넓이 : ";
	cin >> arrn;
	c.searchByArea(arrn);
}
```
```
출력 :

원의 개수 >> 3
원 1의 이름과 반지름 : 도넛 10
원 2의 이름과 반지름 : 피자 20
원 3의 이름과 반지름 : 맨홀 30
원의 이름 : 맨홀
2826
원의 넓이 : 20
도넛의 면적은 314, 피자의 면적은 1256, 맨홀의 면적은 2826,
```
### 끝말잇기 게임
```c++
#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
	string ans;
public:
	void setName(string n) {
		name = n;
	}
	void setAns(string a) {
		ans = a;
	}
	string getName() {
		return name;
	}
	string getAns() {
		return ans;
	}
};

class WordGame {
	int size, check = 0;
	string cmp = "아버지";
	Player *p;
public:
	WordGame(int size) {
		p = new Player[size];
		this->size = size;
	}
	void setName(string n, int arrn) {
		p[arrn].setName(n);
	}
	void setAns(string a, int arrn) {
		p[arrn].setAns(a);
	}
	string getName(int i) {
		return p[i].getName();
	}
	string getAns(int i) {
		return p[i].getAns();
	}
	void compare(int i) {
		if (p[i % 3].getAns()[0] == cmp[cmp.size() - 2] && p[i % 3].getAns()[1] == cmp[cmp.size() - 1]) cmp = p[i % 3].getAns();
		else {
			cout << "땡" << endl;
			check = 1;
		}
	}
	int ch() {
		return check;
	}
	~WordGame() {
		delete[] p;
	}
};

int main() {
	int n;
	string name, str;
	cout << "끝말잇기 시작" << endl << "몇명? : ";
	cin >> n;

	WordGame w(n);

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번 이름 : ";
		cin >> name;
		w.setName(name, i);
	}
	int i = 0;

	cout << "시작단어는 아버지" << endl;

	while (1) {
		if (w.ch() == 1) break;
		cout << w.getName(i % 3) << ">>";
		cin >> str;
		w.setAns(str, i % 3);
		w.compare(i % 3);
		i++;
	}
}
```
```
출력&입력 :

끝말잇기 시작
몇명? : 3
1번 이름 : 김개똥
2번 이름 : 김갑순
3번 이름 : 레오릭
시작단어는 아버지
김개똥>>지분
김갑순>>분가
레오릭>>가롯
김개똥>>모르겠다
땡
```
## Call by value & reference
+ call by value - 인자 값을 복사해서 오는 것

+ call by reference - 값의 주소를 가져오는 것
+ value는 값에 직접 영향을 주지 않음
+ reference는 변경 가능

### call by reference의 예
```c++
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int m = 2, n = 9;
	swap(m, n);
	cout << m << " " << n;
}
```
```
출력 : 9    2
```

### call by reference로 평균 구하기
```c++
#include <iostream>
using namespace std;

bool average(int a[], int size, int &avg) {
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = sum / size;
	return true;
}

int main() {
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -2, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;
}
```
```
출력:

평균은 2
매개 변수 오류
```

### 객체를 call by reference로 변경하는 프로그램
```c++
#include <iostream>
using namespace std;

class Circle {
	int n;
public:
	Circle(int n = 1) {
		this->n = n;
	}
	int getNum() {
		return n;
	}
};

void CircleChange(Circle& a, Circle& b) {
	Circle temp;

	temp = a;
	a = b;
	b = temp;
}

int main() {
	Circle a(10), b(20);

	cout << "Circle a의 값: " << a.getNum() << " Circle b의 값 : " << b.getNum() << endl;

	CircleChange(a, b);

	cout << "Circle a의 값: " << a.getNum() << " Circle b의 값 : " << b.getNum() << endl;
}
```
```
출력 :

Circle a의 값: 10 Circle b의 값 : 20
Circle a의 값: 20 Circle b의 값 : 10
```

## 객체의 복사
+ 복사는 컴파일러가 기본적으로 제공하는 얕은 복사와 사용자가 해줘야하는 깊은 복사가 있음

+ 얕은 복사의 문제점은 소멸자의 중복 처리로 인한 메모리 충돌로 런타임 에러가 발생함

### 깊은 복사를 통한 이름 복사후 변경
```c++
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Person {
	char* name;
	int id = 0;
public:
	Person(int id, char* name);
	Person(Person& person);
	~Person();
	void changeName(char *name);
	void show() { cout << id << "." << name << endl; }
};

Person::Person(int id, char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

Person::Person(Person& person) { // 깊은 복사
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체의 이름 : " << this->name << endl;
}


Person::~Person() {
	if (name)
		delete[] name;
}

void Person::changeName(char* name) {
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main() {
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter 객체 생성 직후 " << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter 이름을 Grace로 변경한 후" << endl;
	father.show();
	daughter.show();

	return 0;
}
```
```
출력 :

Circle a의 값: 10 Circle b의 값 : 20
Circle a의 값: 20 Circle b의 값 : 10
```

## 연습문제
### 1번 스택문제
```c++
#include <iostream>
#include <string>
using namespace std;

class MyIntStack {
	int *p;
	int size;
	int tos = -1;
public:
	MyIntStack() {
		cout << "스택 크기 없음" << endl;
	}
	MyIntStack(int size) {
		p = new int[size];
		this->size = size;
	}
	MyIntStack(MyIntStack& s) {
		this->size = s.size;
		this->tos = s.tos;
		this->p = new int[s.size];
		for (int i = 0; i < s.size; i++)
			this->p[i] = s.p[i];
	}
	~MyIntStack() {
		delete[] p;
	}
	bool push(int n) {
		if (tos >= size - 1) return false;
		else {
			p[++tos] = n;
			return true;
		}
	}
	bool pop(int &n) {
		if (tos <= -1) return false;
		else {
			n = p[tos--];
			return true;
		}
	}
};

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}
```
```
출력 :

스택 a에서 팝한 값 20
스택 b에서 팝한 값 30
```

### 2번 도서 문제
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char *title;
	int price;
public:
	Book(const char* title, int price) {
		this->price = price;
		int len = strlen(title);
		this->title = new char[len + 1];
		strcpy(this->title, title);
	}
	
	Book(Book& b) {
		this->price = b.price;
		int len = strlen(b.title);
		this->title = new char[len + 1];
		for (int i = 0; i <= len; i++)
			this->title[i] = b.title[i];
	}

	~Book() {
		delete[] this->title;
	}

	void set(char* title, int price) {
		int len = strlen(title);
		if (len > strlen(this->title)) {
			delete[] this->title;
			this->title = new char[len + 1];
		}
		for (int i = 0; i <= len; i++)
			this->title[i] = title[i];

		this->price = price;
	}
	
	void show() { cout << title << " " << price << "원" << endl; }
};

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}
```
```
출력 :

명품C++ 10000원
명품자바 12000원
```

### 3번 60점 넘는 학생 수 문제
```c++
#include <iostream>
using namespace std;

class Dept {
	int size;
	int * scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(Dept& dept) {
		this->size = dept.size;
		this->scores = new int[size];
		for (int i = 0; i < size; i++)
			this->scores[i] = dept.scores[i];
	}
	~Dept() {
		delete[] scores;
	}
	int getSize() { return size; }
	void read() {
		for (int i = 0; i < size; i++)
			cin >> scores[i];
	}
	bool isOver60(int index) {
		return scores[index] >= 60 ? true : false;
	}
};

int countPass(Dept dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명" << endl;
}
```
```
10 20 30 40 50 60 70 80 90 100

출력:

60점 이상은 5명
```