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