#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	//Circle() { radius = 1; }
	Circle(int r = 1) { radius = r; }
	double getArea() {
		return 3.14*radius*radius;
	}
};

int main() {
	Circle waffle(15);
	Circle circleArray[3];
}

// Circle circleArray[3] = { Circle(10), Circle(20), Circle() };