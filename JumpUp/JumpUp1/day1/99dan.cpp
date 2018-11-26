#include<iostream>

int main() {
	int i, j;

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			std::cout << j << " * " << i << " = " << i*j << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}