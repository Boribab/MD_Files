#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void fileRead(vector<string> &v, ifstream &fin) {
	string line;
	while (true) {
		getline(fin, line);
		if (fin.eof()) break;
		v.push_back(line);
	}
}

void search(vector<string> &v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);
		if (index != -1)
			cout << v[i] << endl;
	}
}

int main() {
	vector<string> wordVector;
	
	ifstream fin("c:\\temp\\words.txt");
	if (!fin) {
		cout << "words.txt ������ �� �� �����ϴ�." << endl;
		return 0;
	}
	fileRead(wordVector, fin);
	cout << "words.txt ������ �о����ϴ�." << endl;
	fin.close();
	while (true) {
		cout << "�˻��� �ܾ �Է��ϼ��� >> ";
		string word;
		getline(cin, word);
		if (word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "���α׷��� �����մϴ�." << endl;
}