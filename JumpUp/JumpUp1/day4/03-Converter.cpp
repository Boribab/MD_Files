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
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ��� >> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	string src = "��", dest = "�޷�";
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