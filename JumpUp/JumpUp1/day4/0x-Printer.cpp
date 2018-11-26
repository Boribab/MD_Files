// ¹Ì¿Ï

#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model, manu;
	int PC, AC;
public:
	Printer(string model, string manu, int PC, int AC) {
		this->model = model;
		this->manu = manu;
		this->PC = PC;
		this->AC = AC;
	}
	virtual void print(int pages) {};
	virtual void show() {};
	int getAC() { return AC; }
	void discount(int n) { AC -= n; PC -= n; }
};

class InkPrinter :public Printer {
	int AI;
public:
	InkPrinter(string model, string manu, int PC, int AC, int AI) :Printer(model, manu, PC, AC) {
		this->AI = AI;
	}
	void print(int pages) {
		if (pages > getAC() || pages > AI)
			return;
		else discount(pages);
	}
	void show() {
		cout << "À×Å©Á¬ : "<< 
	}
};