#include <iostream>
#include <cstring>
using namespace std;

class BaseMemory {
	char *mem;
protected:
	BaseMemory(int size = 1024) { mem = new char[size]; }
	~BaseMemory() { delete[] mem; }
	void burn(char arr[],int n) {
		strncpy(mem, arr, n);
	}
	char read(int i) { return mem[i]; }
	void write(int n, char c) { mem[n] = c; }
};

class ROM : public BaseMemory {
public:
	ROM(int size, char arr[],int arrs):BaseMemory(size) {
		burn(arr, arrs);
	}
	char read(int i) { return BaseMemory::read(i); }
};

class RAM : public BaseMemory {
public:
	RAM(int size) :BaseMemory(size) {}
	void write(int i, char c) { BaseMemory::write(i, c); }
	char read(int i) { return BaseMemory::read(i); }
};

int main() {
	char x[5] = { 'h', 'e', 'l', 'l', 'o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}