/*
�븶���� 8���� �л��� �ִ�. ��������� ����, ������ �ְ� ���������� ��, ������, ������ ���� �ִ�.
���߰��� 4��, �Ӻ������� 2��, ���Ȱ��� 2���� ��
�л��� ������ �Է��ϰų� �����ִ� ���α׷��� ����ÿ�.

// class �⺻ Ʋ

class Student {
int kor, math;
	string name;
public:
	Student();
	void show();
	void setName();
};

class Develop:public Student {
	int web;
public:
	Develop();
	void show();
};

class Embedded:public Student {
	int web;
public:
	Embedded();
	void show();
};

class Security:public Student {
	int web;
public:
	Security();
	void show();
};
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
	int kor, math;
	string name;
public:
	Student() {
		cout << "�л��� �̸� >> ";
		cin.ignore();
		getline(cin, name);
		cout << "���� ���� >> ";
		cin >> kor;
		cout << "���� ���� >> ";
		cin >> math;
	}
	void show() {
		cout << endl << "�л��� �̸� : " << name << endl << "���� ���� : " << kor << endl << "���� ���� : " << math << endl;
	}
	void setName(string name) {
		this->name = name;
	}
};

class Develop:public Student {
	int web;
public:
	Develop() {
		cout << "�� ���� >> ";
		cin >> web;
	}

	void show() {
		Student::show();
		cout << "�� ���� : " << web << endl << endl;
	}
};

class Embedded:public Student {
	int linux;
public:
	Embedded() {
		cout << "������ ���� >> ";
		cin >> linux;
	}
	void show() {
		Student::show();
		cout << "������ ���� : " << linux << endl << endl;
	}
};

class Security:public Student {
	int security;
public:
	Security() {
		cout << "���� ���� >> ";
		cin >> security;
	}
	void show() {
		Student::show();
		cout << "���� ���� : " << security << endl << endl;
	}
};

int main() {
	int n, n2, dc = 0, ec = 0, sc = 0;
	Develop *d[4];
	Embedded *e[2];
	Security *s[2];

	cout << "--- ���� �ý��� ���� ---" << endl;

	while (1) {
		cout << "�л� �߰�(1)   ���� Ȯ��(2)   ������(3) >>> ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "���߰�(1)   �Ӻ�����(2)   ���Ȱ�(3) >>> ";
			cin >> n2;
			switch (n2) {
			case 1:
				d[dc] = new Develop();
				dc++;
				break;
			case 2:
				e[ec] = new Embedded();
				ec++;
				break;
			case 3:
				s[sc] = new Security();
				sc++;
				break;
			}
			break;
		case 2:
			cout << "���߰�(1)   �Ӻ�����(2)   ���Ȱ�(3) >>> ";
			cin >> n2;
			switch (n2) {
			case 1:
				for (int i = 0; i < dc; i++)
					d[i]->show();
				break;
			case 2:
				for (int i = 0; i < ec; i++)
					e[i]->show();
				break;
			case 3:
				for (int i = 0; i < sc; i++)
					s[i]->show();
				break;
			}
			break;
		case 3:
			return 0;
		}
	}
}