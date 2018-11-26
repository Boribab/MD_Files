#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h> // 시드 값 설정

using namespace std;

void fileRead(vector<string> &v, ifstream &fin) { // 파일 안에 있는 단어들을 vector 변수에 저장
	string line;
	while (true) {
		getline(fin, line);
		if (fin.eof()) break;
		v.push_back(line);
	}
}

int main() {
	vector<string> word; // 단어장 목록
	int hp, chk; // 5번의 기회, 맞추었는지 체크
	char ans, next; // 입력받을 단어, 넘어갈지 체크
	string w; // 단어장에서 한 단어 선택
	srand((unsigned)time(0)); // random을 진짜 random으로

	ifstream fin("c:\\temp\\words.txt"); // 단어장 불러오기
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다." << endl;
		return 0;
	}

	fileRead(word, fin);

	fin.close(); // 필요없는 파일 닫기

	cout << "----- 지금부터 행맨 게임을 시작합니다 -----" << endl;

	while (true) { //게임 시작
		hp = 5; // 새로운 단어가 될 때마다 5로 초기화
		chk = 0; // 0은 맞춘거, 1은 못맞춘거
		int n = rand() % word.size(); // 배열 인덱스 랜덤 선택
		w = word[n]; // w에 담기
		int n2 = rand() % w.length(); // 몇번째 단어를 가릴 것인지 선택
		int n3 = rand() % w.length(); // 위와 동일
		char a = w[n2], b = w[n3];

		if (a == b) continue; // 가릴 단어가 겹치면 다시 시작

		while (true) { // 5번의 기회로 단어 맞추기
			if (hp == 0) { // hp가 0일 때 선택
				cout << "End" << endl << w << endl << "Next(y/n)? ";
				cin >> next; // 계속 할건지 선택
				if (next == 'y') break; // y는 다른 단어로 다시 시작
				else return 0; // 프로그램 종료
			}

			if (n2 == -1 && n3 == -1) { // 맞췄을 시
				cout << endl << w << endl << "Next(y/n)? ";
				cin >> next;
				if (next == 'y') break;
				else return 0;
			}

			for (int i = 0; i < w.length(); i++) { // 단어 가려서 출력
				if (w[i] != a && w[i] != b) {
					cout << w[i];
				}
				else cout << "-";
			}
			cout << endl << ">>";
			cin >> ans; // 가려있는 글자 입력

			if (n2 != -1) { // 아직 첫번째 단어를 못맞췄을 시
				if (a == ans) { // 입력값과 비교
					n2 = -1;
					chk = 0;
					a = 0;
				}
				else
					chk = 1;
			}

			if (n3 != -1) { // 두번째 단어를 못맞췄을 시
				if (b == ans) {
					n3 = -1;
					chk = 0;
					b = 0;
				}
				else
					chk = 1;
			}
			if (chk == 1) // 아무것도 못맞췄을 시
				hp -= 1;
		}
	}
}