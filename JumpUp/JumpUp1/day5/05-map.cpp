#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> m;
	map<string, string>::iterator it = m.begin();
	int n;
	string id, pw, in;
	
	cout << "***** ��ȣ ���� ���α׷� WHO�� �����մϴ� *****" << endl;

	while (true) {
		id = "", pw = "", in = "";
		cout << "����(1)   �˻�(2)   ����(3) >> ";
		cin >> n;
		
		switch (n) {
		case 1:
			cout << "�̸� ��ȣ �Է� >> ";
			cin >> id >> pw;
			m.emplace(id, pw);
			break;
		case 2:
			cout << "�̸� >> ";
			cin >> id;
			
			for (it = m.begin(); it != m.end(); it++) {
				if (it->first == id) {
					pw = it->second;
					break;
				}
			}
			while (1) {
				cout << "��ȣ >> ";
				cin >> in;
				if (in == pw) {
					cout << "���" << endl;
					break;
				}
				else {
					cout << "����" << endl;
				}
			}
			break;
		case 3:
			return 0;
		}
	}
}