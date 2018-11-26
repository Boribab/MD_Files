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
	cout << "원개수 : ";
	cin >> n;

	Circle *c = new Circle[n];

	for (int i = 0; i < n; i++) {
		cout << "원" << i + 1 << ":";
		c[i].read();
		count += c[i].check();
	}

	for (int i = 0; i < n; i++) {
		c[i].write();
	}
	cout << endl << "개수 : " << count << endl;

	delete[] c;
}

//this - 컴파일러가 알아서 붙여줌, 매개변수 x 객체꺼 멤버변수
// 멤버 함수가 아닌 함수 x static x