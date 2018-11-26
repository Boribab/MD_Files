#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

extern "C" {
	int s();
	int s2(const char* id, const char* pw);
	int s3();
	int IDPWcheck();
	int closeSocket();
}

void ReadAccount(map<string, string> &v, ifstream &fin) {
	string id, pw;
	while (true) {
		getline(fin, id);
		getline(fin, pw);
		v.emplace(id, pw);
		if (fin.eof()) break;
	}
}

int main() {
	map<string, string> accounts;
	int n;

	ifstream fin("c:\\temp\\Account.txt");

	if (!fin) {
		cout << "[!] Account.txt 파일을 열 수 없습니다." << endl;
		return 0;
	}

	ReadAccount(accounts, fin);

	fin.close();
	
	s();

	while (1) {
		IDPWcheck();

		for (auto it = accounts.begin(); it != accounts.end(); it++) {
			n = s2(it->first.c_str(), it->second.c_str());
			if (n == 1) break;
		}
		closeSocket();
	}
	s3();
}