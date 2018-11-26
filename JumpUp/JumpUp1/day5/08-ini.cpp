#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char* firstFile = "c:\\temp\\student.txt";
	char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);
	if (!fout) {
		cout << firstFile << " ���� ����" << endl;
		return 0;
	}
	fstream fin(secondFile, ios::in);
	if (!fin) {
		cout << secondFile << " ���� ����" << endl;
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c);
	}

	fin.close();
	fout.close();
}