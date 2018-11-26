#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int len, i = 0, j;

	getline(cin, str);
	len = str.length();

	while (i < len) {
		for (j = 0; j <= i; j++) {
			cout << str[j];
		}
		cout << endl;
		i++;
	}
}