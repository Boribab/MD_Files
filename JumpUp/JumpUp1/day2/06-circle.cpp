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
	cout << "������ : ";
	cin >> n;

	Circle *c = new Circle[n];

	for (int i = 0; i < n; i++) {
		cout << "��" << i + 1 << ":";
		c[i].read();
		count += c[i].check();
	}

	for (int i = 0; i < n; i++) {
		c[i].write();
	}
	cout << endl << "���� : " << count << endl;

	delete[] c;
}

//this - �����Ϸ��� �˾Ƽ� �ٿ���, �Ű����� x ��ü�� �������
// ��� �Լ��� �ƴ� �Լ� x static x