#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

using namespace std;

int main() {
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(15);
	vec.push_back(12);
	vec.push_back(100);
	vec.push_back(0);

	std::sort(vec.begin(), vec.end(), greater<int>());

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) { // auto iter = vec.begin()  // for (auto n : vec)
		cout << (*iter) << " "; 
	}

	cout << endl;
}