# 2018년 7월 26일 목요일 수업 일지
## 가상 함수란?
+ virtual 키워드가 앞에 붙어 있는 함수

+ 부모 클래스의 함수에 virtual이 정의되면 자식도 정의됨
+ 재정의 할 수 있는 함수

### 가상 함수 기본
```c++
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	virtual void f() { cout << "Derived:f() called" << endl; }
};

int main() {
	Derived d, *pDer;

	pDer = &d;
	pDer->f(); // Derived::f() 호출

	Base * pBase;
	pBase = pDer; // 업캐스팅
	pBase->f();  // 동적 바인딩 발생, Derived::f() 실행
}
```
```
출력 :

Derived:f() called
Derived:f() called
```

### 가상 함수 예시
```c++
//Shape.h

class Shape {
	Shape* next;
protected:
	virtual void draw();
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
};

//Shape.cpp

#include <iostream>
#include "Shape.h"
using namespace std;

void Shape::paint() {
	draw();
}

void Shape::draw() {
	cout << "--Shape--" << endl;
}

Shape* Shape::add(Shape *p) {
	this->next = p;
	return p;
}

//Circle.h

class Circle : public Shape{
protected:
	virtual void draw();
};

//Circle.cpp

#include <iostream>
#include "Shape.h"
#include "Circle.h"
using namespace std;

void Circle::draw() {
	cout << "Circle" << endl;
}

//Rect.h

class Rect : public Shape {
protected:
	virtual void draw();
};

//Rect.cpp#include <iostream>
#include "Shape.h"
#include "Rect.h"
using namespace std;

void Rect::draw() {
	cout << "Rectangle" << endl;
}

//Line.h

class Line:public Shape {
protected:
	virtual void draw();
};

//Line.cpp

#include <iostream>
#include "Shape.h"
#include "Line.h"
using namespace std;

void Line::draw() {
	cout << "Line" << endl;
}

//main.cpp

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
using namespace std;

int main() {
	Shape *pStart = NULL;
	Shape *pLast;

	pStart = new Circle();
	pLast = pStart;

	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Circle());
	pLast = pLast->add(new Line());
	pLast = pLast->add(new Rect());


	Shape* p = pStart;
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}
	p = pStart;
	while (p != NULL) {
		Shape*  q = p->getNext();
		delete p;
		p = q;
	}
}
```
```
출력 : 

Circle
Rectangle
Circle
Line
Rectangle
```
+ 순수 가상 함수란 함수의 선언만 있고 정의가 없는 것

+ 자식 클래스에서 반드시 재정의 해야함
+ = 0;을 붙여 선언

### 순수 가상 함수 예시
```c++
#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio = 0) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요 >> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	string src = "원", dest = "달러";
	int r;
public:
	WonToDollar(int r):Converter(r) {
		this->r = r;
	}
	double convert(double src) {
		double res;
		res = src / r;

		return res;
	}
	string getSourceString() {
		return src;
	}
	string getDestString() {
		return dest;
	}
};

class KmToMile : public Converter {
	string src = " km", dest = " mile";
	double r;
public:
	KmToMile(double r) :Converter(r) {
		this->r = r;
	}
	double convert(double src) {
		double res;
		res = src / r;

		return res;
	}
	string getSourceString() {
		return src;
	}
	string getDestString() {
		return dest;
	}
};

int main() {
	WonToDollar wd(1010);
	wd.run();

	KmToMile toMile(1.609344);
	toMile.run();
}
```
```
입력&출력:

원을 달러로 바꿉니다. 원을 입력하세요 >> 10000
변환 결과 : 9.90099달러
 km을  mile로 바꿉니다.  km을 입력하세요 >> 10
변환 결과 : 6.21371 mile
```

## 연습문제
### LoopAdder
```c++
#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") {
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << "입니다." << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class ForLoopAdder :public LoopAdder {
public:
	ForLoopAdder(string name) :LoopAdder(name) {}
	int calculate() {
		int sum = 0;
		for (int i = getX(); i <= getY(); i++)
			sum += i;

		return sum;
	}
};

class WhileLoopAdder :public LoopAdder {
public:
	WhileLoopAdder(string name) :LoopAdder(name) {}
	int calculate() {
		int sum = 0, i = getX();
		while (i <= getY()) {
			sum += i;
			i++;
		}
		return sum;
	}
};

class DoWhileLoopAdder :public LoopAdder {
public:
	DoWhileLoopAdder(string name) :LoopAdder(name) {}
	int calculate() {
		int sum = 0, i = getX();
		do {
			sum += i;
			i++;
		} while (i <= getY());

		return sum;
	}
};

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder dowhileLoop("Do While Loop");

	whileLoop.run();
	dowhileLoop.run();
}
```
```
입력&출력:

For Loop:
처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> 3 10
3에서 10까지의 합 = 52입니다.
While Loop:
처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> 2 5
2에서 5까지의 합 = 14입니다.
Do While Loop:
처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> 5 7
5에서 7까지의 합 = 18입니다.
```
### AbstractGate
```c++
#include <iostream>
#include <string>
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	bool operation() {
		if (x && y) return true;
		else return false;
	}
};

class ORGate : public AbstractGate {
public:
	bool operation() {
		if (x || y) return true;
		else return false;
	}
};

class XORGate : public AbstractGate {
public:
	bool operation() {
		if (x ^ y) return true;
		else return false;
	}
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);

	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}
```
```
출력:

false
true
true
```
### AbstractStack
```c++
#include <iostream>
#include <string>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int &n) = 0;

	virtual int size() = 0;
};

class IntStack :public AbstractStack {
	int tos = -1, stack[100];
public:
	bool push(int n) {
		if (tos < 99) stack[++tos] = n;
		else return false;
	}
	bool pop(int &n) {
		if (tos >= 0) n = stack[tos--];
		else return false;
	}
	int size() {
		return tos + 1;
	}
};

int main() {
	IntStack ins;
	int n, n2;

	while (true) {
		cout << "push(1)  pop(2)  size(3)  exit(4) >>> ";
		cin >> n;
		n2 = 0;

		switch (n) {
		case 1:
			cout << "push value >> ";
			cin >> n2;

			if (ins.push(n2)) cout << "Sucess" << endl;
			else cout << "Stack full" << endl;
			break;
		case 2:
			if (ins.size() != 0) {
				ins.pop(n2);
				cout << "poped value : " << n2 << endl;
			}
			else cout << "Stack empty" << endl;
			break;
		case 3:
			cout << "Stack size : " << ins.size() << endl;
			break;
		case 4:
			return 0;
		}
	}
}
```
```
입력&출력:

push(1)  pop(2)  size(3)  exit(4) >>> 1
push value >> 4
Sucess
push(1)  pop(2)  size(3)  exit(4) >>> 1
push value >> 2
Sucess
push(1)  pop(2)  size(3)  exit(4) >>> 3
Stack size : 2
push(1)  pop(2)  size(3)  exit(4) >>> 2
poped value : 2
push(1)  pop(2)  size(3)  exit(4) >>> 2
poped value : 4
push(1)  pop(2)  size(3)  exit(4) >>> 2
Stack empty
push(1)  pop(2)  size(3)  exit(4) >>> 4
```
### Shape
```c++
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() { return 0; }
	string getName() { return name; }
};

class Oval :public Shape {
	int w, h;
public:
	Oval(string n = "", int w = 0, int h = 0) :Shape(n, w, h) { this->w = w / 2; this->h = h / 2; }
	double getArea() {
		return 3.14*w*h;
	}
};

class Rect :public Shape {
	int w, h;
public:
	Rect(string n = "", int w = 0, int h = 0) :Shape(n, w, h) { this->w = w; this->h = h; }
	double getArea() {
		return w*h;
	}
};

class Triangular :public Shape {
	int w, h;
public:
	Triangular(string n = "", int w = 0, int h = 0) :Shape(n, w, h) { this->w = w; this->h = h; }
	double getArea() {
		return (w*h) / 2;
	}
};

int main() {
	Shape *p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);
	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}
```
```
출력:

빈대떡 넓이는 157
찰떡 넓이는 1200
토스트 넓이는 600
```
## Template 이란?
+ 자료형을 컴파일러가 알아서 지정해주는 것

+ 생산성이 늘어나지만 호환이 안되는 경우도 있음
### template 기본
```c++
#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n) {
	for (int i = 0; i < n; i++)
		dest[i] = (T2)src[i];
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5];
	char c[5] = { 'H','E','L','L','O' }, e[5];

	mcopy(x, d, 5);
	mcopy(c, e, 5);

	for (int i = 0; i < 5; i++) cout << d[i] << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++) cout << e[i] << ' ';
	cout << endl;
}
```
```
출력 :

1 2 3 4 5
H E L L O
```

+ char형은 아스키 문자로 나오기 때문에 중복 함수를 만들어 줘야함

### charPrint
```c++
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}

void print(char array[], int n) { // 중복 함수 생성
	for (int i = 0; i < n; i++)
		cout << (int)array[i] << '\t';
	cout << endl;
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5] = { 1.1,2.2,3.3,4.4,5.5 };
	print(x, 5);
	print(d, 5);

	char c[5] = { 1,2,3,4,5 };
	print(c, 5);
}
```
```
출력 :

1 2 3 4 5
1.1 2.2 3.3 4.4 5.5
1 2 3 4 5
```

### Class Template
```c++
#include <iostream>
using namespace std;

template <class T>
class MyStack {
	int tos;
	T data[100];
public:
	MyStack();
	void push(T element);
	T pop();
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full";
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T> 
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack empty";
		return 0;
	}
	retData = data[tos--];
	return retData;
}

int main() {
	MyStack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<char> *p = new MyStack<char>();
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}
```
```
출력 :

3
3.5
a
```

### 순수 가상 연산자 함수를 사용한 템플릿
```c++
#include <iostream>
using namespace std;

class Comparable {
public:
	virtual bool operator>(Comparable& op2) = 0;
	virtual bool operator<(Comparable& op2) = 0;
	virtual bool operator==(Comparable& op2) = 0;
};

class Circle : public Comparable {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator>(Comparable& op2);
	bool operator<(Comparable& op2);
	bool operator==(Comparable& op2);
};

bool Circle::operator>(Comparable& op2) {
	if (this->getRadius() > ((Circle&)op2).getRadius()) return true;
	else return false;
}

bool Circle::operator<(Comparable& op2) {
	if (this->getRadius() < ((Circle&)op2).getRadius()) return true;
	else return false;
}

bool Circle::operator==(Comparable& op2) {
	if (this->getRadius() == ((Circle&)op2).getRadius()) return true;
	else return false;
}

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}

/*
Circle bigger(Circle a, Circle b) {
	if (a.getRadius() > b.getRadius()) return a;
	else return b;
}
*/

int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}
```
```
출력 :

20과 50중 큰 값은 50
waffle과 pizza 중 큰 것의 반지름은 20
```