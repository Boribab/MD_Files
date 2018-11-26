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

// default 매개변수 or 기본 생성자 or 매개변수 직접 지정