#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;

	cout << "�̸� >> ";
	cin >> name;
	cout << "�й� >> ";
	cin >> sid;
	cout << "�а� >> ";
	cin >> dept;

	ofstream f("C:\\temp\\student.txt");
	if (!f) {
		cout << "student ������ �� �� ����" << endl;
		return 0;
	}

	f << name << endl;
	f << sid << endl;
	f << dept << endl;

	f.close();
}