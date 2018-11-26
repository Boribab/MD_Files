#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h> // �õ� �� ����

using namespace std;

void fileRead(vector<string> &v, ifstream &fin) { // ���� �ȿ� �ִ� �ܾ���� vector ������ ����
	string line;
	while (true) {
		getline(fin, line);
		if (fin.eof()) break;
		v.push_back(line);
	}
}

int main() {
	vector<string> word; // �ܾ��� ���
	int hp, chk; // 5���� ��ȸ, ���߾����� üũ
	char ans, next; // �Է¹��� �ܾ�, �Ѿ�� üũ
	string w; // �ܾ��忡�� �� �ܾ� ����
	srand((unsigned)time(0)); // random�� ��¥ random����

	ifstream fin("c:\\temp\\words.txt"); // �ܾ��� �ҷ�����
	if (!fin) {
		cout << "words.txt ������ �� �� �����ϴ�." << endl;
		return 0;
	}

	fileRead(word, fin);

	fin.close(); // �ʿ���� ���� �ݱ�

	cout << "----- ���ݺ��� ��� ������ �����մϴ� -----" << endl;

	while (true) { //���� ����
		hp = 5; // ���ο� �ܾ �� ������ 5�� �ʱ�ȭ
		chk = 0; // 0�� �����, 1�� �������
		int n = rand() % word.size(); // �迭 �ε��� ���� ����
		w = word[n]; // w�� ���
		int n2 = rand() % w.length(); // ���° �ܾ ���� ������ ����
		int n3 = rand() % w.length(); // ���� ����
		char a = w[n2], b = w[n3];

		if (a == b) continue; // ���� �ܾ ��ġ�� �ٽ� ����

		while (true) { // 5���� ��ȸ�� �ܾ� ���߱�
			if (hp == 0) { // hp�� 0�� �� ����
				cout << "End" << endl << w << endl << "Next(y/n)? ";
				cin >> next; // ��� �Ұ��� ����
				if (next == 'y') break; // y�� �ٸ� �ܾ�� �ٽ� ����
				else return 0; // ���α׷� ����
			}

			if (n2 == -1 && n3 == -1) { // ������ ��
				cout << endl << w << endl << "Next(y/n)? ";
				cin >> next;
				if (next == 'y') break;
				else return 0;
			}

			for (int i = 0; i < w.length(); i++) { // �ܾ� ������ ���
				if (w[i] != a && w[i] != b) {
					cout << w[i];
				}
				else cout << "-";
			}
			cout << endl << ">>";
			cin >> ans; // �����ִ� ���� �Է�

			if (n2 != -1) { // ���� ù��° �ܾ �������� ��
				if (a == ans) { // �Է°��� ��
					n2 = -1;
					chk = 0;
					a = 0;
				}
				else
					chk = 1;
			}

			if (n3 != -1) { // �ι�° �ܾ �������� ��
				if (b == ans) {
					n3 = -1;
					chk = 0;
					b = 0;
				}
				else
					chk = 1;
			}
			if (chk == 1) // �ƹ��͵� �������� ��
				hp -= 1;
		}
	}
}