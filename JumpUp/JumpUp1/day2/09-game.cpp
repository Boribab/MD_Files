#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
	string ans;
public:
	void setName(string n) {
		name = n;
	}
	void setAns(string a) {
		ans = a;
	}
	string getName() {
		return name;
	}
	string getAns() {
		return ans;
	}
};

class WordGame {
	int size, check = 0;
	string cmp = "아버지";
	Player *p;
public:
	WordGame(int size) {
		p = new Player[size];
		this->size = size;
	}
	void setName(string n, int arrn) {
		p[arrn].setName(n);
	}
	void setAns(string a, int arrn) {
		p[arrn].setAns(a);
	}
	string getName(int i) {
		return p[i].getName();
	}
	string getAns(int i) {
		return p[i].getAns();
	}
	void compare(int i) {
		if (p[i % 3].getAns()[0] == cmp[cmp.size() - 2] && p[i % 3].getAns()[1] == cmp[cmp.size() - 1]) cmp = p[i % 3].getAns();
		else {
			cout << "땡" << endl;
			check = 1;
		}
	}
	int ch() {
		return check;
	}
	~WordGame() {
		delete[] p;
	}
};

int main() {
	int n;
	string name, str;
	cout << "끝말잇기 시작" << endl << "몇명? : ";
	cin >> n;

	WordGame w(n);

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번 이름 : ";
		cin >> name;
		w.setName(name, i);
	}
	int i = 0;

	cout << "시작단어는 아버지" << endl;

	while (1) {
		if (w.ch() == 1) break;
		cout << w.getName(i % 3) << ">>";
		cin >> str;
		w.setAns(str, i % 3);
		w.compare(i % 3);
		i++;
	}
}