#include <iostream>
using namespace std;

class A {
public:
	A(int x = 0) {
		cout << "�Ű����� ������ A" << x << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "������ B" << endl;
	}
	B(int x):A(x + 3) {
		cout << "�Ű����� ������ B" << endl;
	}
};

int main() {
	B b;
}

// default �Ű����� or �⺻ ������ or �Ű����� ���� ����