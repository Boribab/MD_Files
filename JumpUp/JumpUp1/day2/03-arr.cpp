#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	
	cin >> n;

	int *p = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		sum += p[i];
	}

	delete[] p;

	cout << "Че : " << sum << ", ЦђБе : " << sum/n << endl;
}