#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v[0] = 10;
	int n = v[2];
	v.at(2) = 5;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

// 가변적 길이를 가진 배열
// size - 원소 개수, capacity 벡터 크기