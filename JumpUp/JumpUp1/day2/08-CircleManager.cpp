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
			if (p[i].getArea() >= arrn) cout << p[i].getName()<< "�� ������ "<< p[i].getArea() << ", ";
		}
	}
};

int main() {
	int n, arrn;
	string name;
	cout << "���� ���� >> ";
	cin >> n;

	CircleManager c(n);

	for (int i = 0; i < n; i++) {
		cout << "�� " << i + 1 << "�� �̸��� ������ : ";
		cin >> name >> arrn;
		c.setCircle(name, arrn, i);
	}

	cout << "���� �̸� : ";
	cin >> name;
	c.searchByName(name);

	cout << "���� ���� : ";
	cin >> arrn;
	c.searchByArea(arrn);
}