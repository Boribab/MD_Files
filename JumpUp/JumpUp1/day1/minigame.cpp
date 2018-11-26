#include <iostream>
using namespace std;

class Critter {
private:
	int m_Hunger = 0, m_Boredom = 0;
	void getMood();
	void passTime();
public:
	void talk();
	void eat();
	void play();
};

void Critter::getMood() {
	cout << "Feeling : " << m_Boredom << endl;
}

void Critter::passTime() {
	m_Hunger += 1;
	m_Boredom += 1;
}

void Critter::talk() {
	if (m_Hunger < 5 && m_Boredom < 5) cout << "I'm good" << endl;
	else if (m_Hunger < 10 && m_Boredom < 10) cout << "Not bad" << endl;
	else if (m_Hunger < 15 && m_Boredom < 15) cout << "Not good" << endl;
	else cout << "GRRRR" << endl;

	getMood();
	passTime();
}

void Critter::eat() {
	m_Hunger -= 2;
	getMood();
	passTime();
}

void Critter::play() {
	m_Boredom -= 2;
	getMood();
	passTime();
}

int main() {
	int n;

	Critter pet;

	cout << "Critter Caretaker" << endl << endl;

	while (1) {
		cout << endl << "0 - Quit" << endl << "1 - Talk with your Critter" << endl << "2 - Feed your Critter" << endl << "3 - Play with your Critter" << endl << endl;

		cin >> n;

		if (n == 0) break;

		switch (n) {
		case 1:
			pet.talk();
			break;
		case 2:
			pet.eat();
			break;
		case 3:
			pet.play();
		}
	}
}