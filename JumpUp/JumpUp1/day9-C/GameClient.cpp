#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Hangman.hpp"

using namespace std;

#pragma comment(lib, "ws2_32.lib")

#define MAXBUF 1024
#define MAXLINE 1024

extern "C" int c();

int main() {
	int n, ch = 3;
	n = c();

	if (n == 0) {
		cout << "Choose Game ->  Hangman(1)    Dungeon(2) >> ";
		cin >> ch;
	}

	if (ch == 1) Hangman();
	else if (ch == 2) Game g;
}