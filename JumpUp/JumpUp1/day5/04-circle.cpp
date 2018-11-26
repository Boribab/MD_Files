#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14*radius*radius; }
	string getName() { return name; }
};

Circle* mCircle(string name, int radius) {
	return new Circle(radius, name);;
}	

int main() {
	vector<Circle*> c;
	vector<Circle*>::iterator it = c.begin();
	int n, radius;
	Circle* a;
	string name;

	cout << "원을 생성하고 삭제하는 프로그램입니다." << endl;
	
	while (1) {
		cout << "삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> ";
		cin >> n;
		
		switch (n) {
		case 1:
			cout << "생성하고자 하는 원의 반지름과 이름은? >> ";
			cin >> radius >> name;
			a = mCircle(name, radius);
			c.push_back(a);
			break;
		case 2:
			cout << "삭제하고자 하는 원의 이름은? >> ";
			cin >> name;
			for (auto it = c.begin(); it != c.end(); ) {
				if ((*it)->getName() == name) {
					it = c.erase(it);
				}
				else
					++it;
			}
			break;
		case 3:
			for (int i = 0; i < c.size(); i++) {
				cout << c[i]->getName() << endl;
			}
			break;
		case 4:
			return 0;
		}
	}
}