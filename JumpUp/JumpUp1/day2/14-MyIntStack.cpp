#include <iostream>
#include <string>
using namespace std;

class MyIntStack {
	int *p;
	int size;
	int tos = -1;
public:
	MyIntStack() {
		cout << "스택 크기 없음" << endl;
	}
	MyIntStack(int size) {
		p = new int[size];
		this->size = size;
	}
	MyIntStack(MyIntStack& s) {
		this->size = s.size;
		this->tos = s.tos;
		this->p = new int[s.size];
		for (int i = 0; i < s.size; i++)
			this->p[i] = s.p[i];
	}
	~MyIntStack() {
		delete[] p;
	}
	bool push(int n) {
		if (tos >= size - 1) return false;
		else {
			p[++tos] = n;
			return true;
		}
	}
	bool pop(int &n) {
		if (tos <= -1) return false;
		else {
			n = p[tos--];
			return true;
		}
	}
};

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}