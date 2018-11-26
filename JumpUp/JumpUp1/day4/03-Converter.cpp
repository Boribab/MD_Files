#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio = 0) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요 >> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	string src = "원", dest = "달러";
	int r;
public:
	WonToDollar(int r):Converter(r) {
		this->r = r;
	}
	double convert(double src) {
		double res;
		res = src / r;

		return res;
	}
	string getSourceString() {
		return src;
	}
	string getDestString() {
		return dest;
	}
};

class KmToMile : public Converter {
	string src = " km", dest = " mile";
	double r;
public:
	KmToMile(double r) :Converter(r) {
		this->r = r;
	}
	double convert(double src) {
		double res;
		res = src / r;

		return res;
	}
	string getSourceString() {
		return src;
	}
	string getDestString() {
		return dest;
	}
};

int main() {
	WonToDollar wd(1010);
	wd.run();

	KmToMile toMile(1.609344);
	toMile.run();
}