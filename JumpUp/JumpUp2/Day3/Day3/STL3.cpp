#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

int main() {
	unordered_map<string, int> people;

	people.insert(pair<string, int>("bori", 100));
	people.insert(pair<string, int>("bab", 50));

	for (auto iter = people.begin(); iter != people.end(); iter++) {
		cout << iter->first << "'s age : " << iter->second << endl;
	}
}