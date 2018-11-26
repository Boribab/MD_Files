#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;

	cout << "이름 >> ";
	cin >> name;
	cout << "학번 >> ";
	cin >> sid;
	cout << "학과 >> ";
	cin >> dept;

	ofstream f("C:\\temp\\student.txt");
	if (!f) {
		cout << "student 파일을 열 수 없다" << endl;
		return 0;
	}

	f << name << endl;
	f << sid << endl;
	f << dept << endl;

	f.close();
}