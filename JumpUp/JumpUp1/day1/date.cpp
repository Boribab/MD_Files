#include <iostream>
using namespace std;

class Date {
public:
	int year, month, day;
	int getYear();
	int getMonth();
	int getDay();
};

int Date::getYear() {
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

int main() {
	Date birth;
	birth.year = 2014;
	birth.month = 3;
	birth.day = 20;
	cout << birth.getYear() << "." << birth.getMonth() << "." << birth.getDay() << endl;
}