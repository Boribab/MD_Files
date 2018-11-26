#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator+ (Power op2);
	bool operator== (Power op2);
	Power operator+= (Power op2);
};

void Power::show() {
	cout << "kick = " << kick << "," << " punch = " << punch << endl;
}

Power Power::operator+(Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power op2) {
	if (kick == op2.kick && punch == op2.punch) return true;
	else return false;
}

Power Power::operator+= (Power op2) {
	kick = kick + op2.kick;
	punch = punch + op2.punch;

	return *this;
}

int main() {
	Power a(3, 5), b(4, 6), c;
	c = a += b;
	a.show();
	b.show();
	c.show();
}

// c = a + b => c = + ( a, b ) 컴파일러


// 연산자 함수 형식 - 리턴타입 operator연산자(매개변수리스트);