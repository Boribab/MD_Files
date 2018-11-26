#include <iostream>
#include <string>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int &n) = 0;

	virtual int size() = 0;
};

class IntStack :public AbstractStack {
	int tos = -1, stack[100];
public:
	bool push(int n) {
		if (tos < 99) stack[++tos] = n;
		else return false;
	}
	bool pop(int &n) {
		if (tos >= 0) n = stack[tos--];
		else return false;
	}
	int size() {
		return tos + 1;
	}
};

int main() {
	IntStack ins;
	int n, n2;

	while (true) {
		cout << "push(1)  pop(2)  size(3)  exit(4) >>> ";
		cin >> n;
		n2 = 0;

		switch (n) {
		case 1:
			cout << "push value >> ";
			cin >> n2;

			if (ins.push(n2)) cout << "Sucess" << endl;
			else cout << "Stack full" << endl;
			break;
		case 2:
			if (ins.size() != 0) {
				ins.pop(n2);
				cout << "poped value : " << n2 << endl;
			}
			else cout << "Stack empty" << endl;
			break;
		case 3:
			cout << "Stack size : " << ins.size() << endl;
			break;
		case 4:
			return 0;
		}
	}
}