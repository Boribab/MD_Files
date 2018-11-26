#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) {
		radius = r;
		cout << "������ ���� radius = " << radius << endl;
	}
	double getArea();
	~Circle() {
		cout << "�Ҹ��� ���� radius = " << radius << endl;
	}
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	int n;

	while (1) {
		cout << "���� ������ �Է�(�����̸� ����)" << endl;
		cin >> n;
		if (n < 0) break;

		Circle *p = new Circle(n);

		cout << "���� ������ " << p->getArea() << endl;

		delete p;
	}
}