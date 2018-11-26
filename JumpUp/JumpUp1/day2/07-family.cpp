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