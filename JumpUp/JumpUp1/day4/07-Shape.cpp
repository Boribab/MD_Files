#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() { return 0; }
	string getName() { return name; }
};

class Oval :public Shape {
	int w, h;
public:
	Oval(string n = "", int w = 0, int h = 0) :Shape(n, w, h) { this->w = w / 2; this->h = h / 2; }
	double getArea() {
		return 3.14*w*h;
	}
};

class Rect :public Shape {
	int w, h;
public:
	Rect(string n = "", int w = 0, int h = 0) :Shape(n, w, h) { this->w = w; this->h = h; }
	double getArea() {
		return w*h;
	}
};

class Triangular :public Shape {
	int w, h;
public:
	Triangular(string n = "", int w = 0, int h = 0) :Shape(n, w, h) { this->w = w; this->h = h; }
	double getArea() {
		return (w*h) / 2;
	}
};

int main() {
	Shape *p[3];
	p[0] = new Oval("ºó´ë¶±", 10, 20);
	p[1] = new Rect("Âû¶±", 30, 40);
	p[2] = new Triangular("Åä½ºÆ®", 30, 40);
	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " ³ÐÀÌ´Â " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}