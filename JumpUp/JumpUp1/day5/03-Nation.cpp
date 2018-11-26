#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
class Nation {
	string nation, capital;
public:
	void write(string nation, string capital) {
		this->nation = nation;
		this->capital = capital;
	}
	int quiz() {
		string ans;

		cout << nation << "�� ������? >>> ";
		cin >> ans;

		if (ans == "exit") return -1;

		if (ans == capital) return 1;
		else return 0;
	}
};

using V = vector<Nation>;

int main() {
	V v;
	int n;
	string na, ca;

	cout << "***** ������ ���� ���߱� ���� ���� *****" << endl;

	while (1) {
		cout << "���� �Է�(1)   ����(2)   ����(3) >>> ";
		cin >> n;
		
		switch (n) {
		case 1:
			cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl << "����� ������ �Է��ϼ��� (no no �̸� �Է� ��)" << endl;

			while (1) {
				cin >> na >> ca;
				if (na == "no" && ca == "no") break;
				else {
					V::iterator iter = v.end();
					iter->write(na, ca);
				}
			}
			break;
		case 2:
			int c;
			for (V::iterator iter = v.begin(); iter != v.end(); ++iter) {
				c = iter->quiz();
				if (c == 1) {
					cout << "Correct!!" << endl;
				}
				else if(c == 0)	cout << "No!!" << endl;
				else break;
			}
			break;
		case 3:
			return 0;
		}
	}
}
*/

class Nation {
	string nation, capital;
public:
	void set(string na, string ca) {
		nation = na;
		capital = ca;
	}
	int quiz() {
		string ans;

		cout << nation << "�� ������? >>> ";
		cin >> ans;

		if (ans == "exit") return -1;

		if (ans == capital) return 1;
		else return 0;
	}
};

int main() {
	vector<Nation> v;
	int n, c;
	string ans, na, ca;
	Nation a;

	cout << "***** ������ ���� ���߱� ���� ���� *****" << endl;

	while (1) {
		cout << "���� �Է�(1)   ����(2)   ����(3) >>> ";
		cin >> n;

		switch (n) {
		case 1:
			cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl << "����� ������ �Է��ϼ��� (no no �̸� �Է� ��)" << endl;	
			while (1) {
				cout << v.size() << "��° ���� �Է� >> ";
				cin >> na >> ca;
				if (na == "no" && ca == "no") break;
				else {
					a.set(na, ca);
					v.push_back(a);
				}
			}
			break;
		case 2:
			for (int i = 0; i < v.size(); i++) {
				c = v[i].quiz();
				if (c == 1) {
					cout << "Correct!!" << endl;
				}
				else if (c == 0)	cout << "No!!" << endl;
				else break;
			}
			break;
		case 3:
			return 0;
		}
	}
}