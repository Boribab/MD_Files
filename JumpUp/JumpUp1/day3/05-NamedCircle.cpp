#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

class NamedCircle : public Circle {
	string cName;
public:
	void setName(string name) {
		cName = name;
	}
	string getName() {
		return cName;
	}
};

int main() {
	NamedCircle pizza[5];

	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++) {
		int radius;
		string name;
		cout << i + 1 << ">> ";
		cin >> radius >> name;
		pizza[i].setRadius(radius);
		pizza[i].setName(name);
	}

	string max = pizza[0].getName();
	int radius = 0;

	for (int i = 1; i < 5; i++) {
		if (pizza[i].getArea() > radius*radius*3.14) {
			radius = pizza[i].getRadius();
			max = pizza[i].getName();
		}
	}

	cout << "���� ������ ū ���ڴ� " << max << "�Դϴ�" << endl;
}