#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	virtual void f() { cout << "Derived:f() called" << endl; }
};

int main() {
	Derived d, *pDer;

	pDer = &d;
	pDer->f(); // Derived::f() 호출

	Base * pBase;
	pBase = pDer; // 업캐스팅
	pBase->f();  // 동적 바인딩 발생, Derived::f() 실행
}

// 순수 가상 함수 - 선언만 있는 것 (코드 x)
// =0; 

// virtual은 base class에서만 있어도 됨