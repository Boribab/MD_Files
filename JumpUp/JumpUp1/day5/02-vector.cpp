#include <iostream>
#include <vector>
#include <array>
using namespace std;
using MyVector = vector<int>;

void VectorIterators(MyVector myVector);
void FindInVector(MyVector myVector);
bool VDescending(int first, int second);

int main(int argc, char* argv[]) {
	MyVector myVector = { 0,1,2 };
	myVector.push_back(3);
	myVector.push_back(4);
	MyVector::const_iterator iter = myVector.cbegin() + 1;
	myVector.insert(iter, 5);
	MyVector::iterator it = myVector.begin();
	myVector.erase(it);
	sort(myVector.begin(), myVector.end(), VDescending);
	sort(myVector.begin(), myVector.end());
	VectorIterators(myVector);
	FindInVector(myVector);
	return 0;
}

void VectorIterators(MyVector myVector) {
	for (MyVector::iterator iter = myVector.begin(); iter != myVector.end(); iter++) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::iterator iter = myVector.end() - 1; iter != myVector.begin(); --iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::reverse_iterator iter = myVector.rbegin(); iter != myVector.rend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::const_iterator iter = myVector.cbegin(); iter != myVector.cend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::const_reverse_iterator iter = myVector.crbegin(); iter != myVector.crend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (auto iter = myVector.begin(); iter != myVector.end(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (auto iter = myVector.cbegin(); iter != myVector.cend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::iterator iter = myVector.begin(); iter != myVector.end(); ++iter) {
		*iter = 5;
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::const_iterator iter = myVector.cbegin(); iter != myVector.cend(); ++iter) {
		//*iter = 5;
		cout << *iter << endl;
	}
	cout << endl << endl;
}

void FindInVector(MyVector myVector) {
	for (unsigned int i = 0; i < myVector.size(); ++i) {
		if (myVector[i] == 2) {
			cout << "Found : " << myVector[i] << " at position : " << i << endl;
		}
	}

	for (auto iter = myVector.begin(); iter != myVector.end(); ++iter) {
		if (*iter == 2) {
			cout << "Found : " << *iter << endl;
		}
	}

	for (auto& number : myVector) {
		if (number == 2) {
			cout << "Found : " << number << endl;
		}
	}

	MyVector::iterator found = find(myVector.begin(), myVector.end(), 2);
	if (found != myVector.end()) {
		cout << "Found : " << *found << endl;
	}
}

bool VDescending(int first, int second) {
	return first > second;
}