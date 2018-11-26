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

	cout << "Circle a�� ��: " << a.getNum() << " Circle b�� �� : " << b.getNum() << endl;

	CircleChange(a, b);

	cout << "Circle a�� ��: " << a.getNum() << " Circle b�� �� : " << b.getNum() << endl;
}