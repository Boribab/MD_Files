#include <iostream>
using namespace std;

class CoffeeMachine {
private:
	int water, coffee, sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();
};

CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	water = w;
	coffee = c;
	sugar = s;
}

void CoffeeMachine::drinkEspresso() {
	water -= 1;
	coffee -= 1;
}

void CoffeeMachine::drinkAmericano() {
	water -= 2;
	coffee -= 1;
}

void CoffeeMachine::drinkSugarCoffee() {
	water -= 2;
	coffee -= 1;
	sugar -= 1;
}

void CoffeeMachine::show() {
	cout << "커피머신 상태, 커피:" << coffee << " 물:" << water << " 설탕:" << sugar << endl;
}

void CoffeeMachine::fill() {
	water = 10;
	sugar = 10;
	coffee = 10;
}

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}