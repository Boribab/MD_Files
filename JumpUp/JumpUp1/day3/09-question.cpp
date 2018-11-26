/*
대마고에는 8명의 학생이 있다. 공통과목은 국어, 수학이 있고 전공과목은 웹, 리눅스, 보안이 각각 있다.
개발과가 4명, 임베디드과가 2명, 보안과가 2명일 때
학생의 성적을 입력하거나 보여주는 프로그램을 만드시오.

// class 기본 틀

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
		cout << "학생의 이름 >> ";
		cin.ignore();
		getline(cin, name);
		cout << "국어 성적 >> ";
		cin >> kor;
		cout << "수학 성적 >> ";
		cin >> math;
	}
	void show() {
		cout << endl << "학생의 이름 : " << name << endl << "국어 성적 : " << kor << endl << "수학 성적 : " << math << endl;
	}
	void setName(string name) {
		this->name = name;
	}
};

class Develop:public Student {
	int web;
public:
	Develop() {
		cout << "웹 성적 >> ";
		cin >> web;
	}

	void show() {
		Student::show();
		cout << "웹 성적 : " << web << endl << endl;
	}
};

class Embedded:public Student {
	int linux;
public:
	Embedded() {
		cout << "리눅스 성적 >> ";
		cin >> linux;
	}
	void show() {
		Student::show();
		cout << "리눅스 성적 : " << linux << endl << endl;
	}
};

class Security:public Student {
	int security;
public:
	Security() {
		cout << "보안 성적 >> ";
		cin >> security;
	}
	void show() {
		Student::show();
		cout << "보안 성적 : " << security << endl << endl;
	}
};

int main() {
	int n, n2, dc = 0, ec = 0, sc = 0;
	Develop *d[4];
	Embedded *e[2];
	Security *s[2];

	cout << "--- 성적 시스템 시작 ---" << endl;

	while (1) {
		cout << "학생 추가(1)   성적 확인(2)   끝내기(3) >>> ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "개발과(1)   임베디드과(2)   보안과(3) >>> ";
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
			cout << "개발과(1)   임베디드과(2)   보안과(3) >>> ";
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