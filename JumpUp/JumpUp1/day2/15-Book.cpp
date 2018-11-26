#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char *title;
	int price;
public:
	Book(const char* title, int price) {
		this->price = price;
		int len = strlen(title);
		this->title = new char[len + 1];
		strcpy(this->title, title);
	}
	
	Book(Book& b) {
		this->price = b.price;
		int len = strlen(b.title);
		this->title = new char[len + 1];
		for (int i = 0; i <= len; i++)
			this->title[i] = b.title[i];
	}

	~Book() {
		delete[] this->title;
	}

	void set(char* title, int price) {
		int len = strlen(title);
		if (len > strlen(this->title)) {
			delete[] this->title;
			this->title = new char[len + 1];
		}
		for (int i = 0; i <= len; i++)
			this->title[i] = title[i];

		this->price = price;
	}
	
	void show() { cout << title << " " << price << "원" << endl; }
};

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}