#include <iostream>

using namespace std;

class Stack {
private:
	int top = -1, x, * arr;
public:
	Stack() {
		arr = new int[100];
	}
	Stack(int x) {
		arr = new int[x];
	}
	~Stack() {
		delete[] arr;
	}
	bool isEmpty() {
		if (top < 0) return true;
		else return false;
		//return (top == -1);
	}
	/*int pop() {
		return arr[top--];
	}*/
	int pop() {
		if(isEmpty()) {
			return -1;
		}
		else {
			return arr[top--];
		}
	}
	void push(int s) {
		if (top >= x - 1) {
			cout << "Stack is full!\n" << endl;
		}
		else {
			arr[++top] = s;
			printf("Stack elements : %d\n", top + 1);
		}
	}
};

int main() {
	int n, x;

	cout << "Stack size : ";
	cin >> x;

	Stack *st = new Stack(x);

	while (1) {
		
		cout << "Push : 0, Pop : 1\n";
		cin >> n;

		if (n == 0) {
			cin >> n;
			st->push(n);
			continue;
		}
		else if (n == 1) {
			/*if (!(st->isEmpty())) {
				cout << "Pop : " << st->pop() << endl;
			}
			else {
				cout << "Stack is Empty!\n" << endl;
			}*/
			x = st->pop();
			if (x == -1) {
				cout << "Stack is empty!\n";
			}
			else {
				cout << "Pop : " << x << endl;
			}
 		}
		else if (n == 2) {
			break;
		}
		else {
			continue;
		}
	}
}