#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> m;
	map<string, string>::iterator it = m.begin();
	int n;
	string id, pw, in;
	
	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;

	while (true) {
		id = "", pw = "", in = "";
		cout << "삽입(1)   검사(2)   종료(3) >> ";
		cin >> n;
		
		switch (n) {
		case 1:
			cout << "이름 암호 입력 >> ";
			cin >> id >> pw;
			m.emplace(id, pw);
			break;
		case 2:
			cout << "이름 >> ";
			cin >> id;
			
			for (it = m.begin(); it != m.end(); it++) {
				if (it->first == id) {
					pw = it->second;
					break;
				}
			}
			while (1) {
				cout << "암호 >> ";
				cin >> in;
				if (in == pw) {
					cout << "통과" << endl;
					break;
				}
				else {
					cout << "실패" << endl;
				}
			}
			break;
		case 3:
			return 0;
		}
	}
}