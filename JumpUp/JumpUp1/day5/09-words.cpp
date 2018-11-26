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
		cout << "words.txt 파일을 열 수 없습니다." << endl;
		return 0;
	}
	fileRead(wordVector, fin);
	cout << "words.txt 파일을 읽었습니다." << endl;
	fin.close();
	while (true) {
		cout << "검색할 단어를 입력하세요 >> ";
		string word;
		getline(cin, word);
		if (word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "프로그램을 종료합니다." << endl;
}