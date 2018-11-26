#include <iostream>
#include <string>
using namespace std;

class Product {
	string descP, producer;
	int price, PID;
public:
	Product(string descP="", string producer = "", int price = 0, int PID = 0) {
		this->descP = descP;
		this->producer = producer;
		this->price = price;
		this->PID = PID;
	}
	
	virtual void write(string descP, string producer, int price, int PID) {
		this->descP = descP;
		this->producer = producer;
		this->price = price;
		this->PID = PID;
	}

	virtual void read() {
		cout << "--- ��ǰID : " << PID << endl << "��ǰ���� : " << descP << endl << "������ : " << producer << endl << "���� : " << price << endl;
	}
};

class Book:public Product {
	string Bname, author;
	int ISBN;
public:
	Book(string descP = "", string producer = "", int price = 0, int PID = 0, string Bname = "", string author = "", int ISBN = 0) :Product(descP, producer, price, PID) {
		this->Bname = Bname;
		this->author = author;
		this->ISBN = ISBN;
	}
	
	virtual void write(string descP, string producer, int price, int PID, string Bname, string author, int ISBN) {
		Product::write(descP, producer, price, PID);
		this->Bname = Bname;
		this->author = author;
		this->ISBN = ISBN;
	}
	virtual void read() {
		Product::read();
		cout << "ISBN : " << ISBN << endl << "å ���� : " << Bname << endl << "���� : " << author << endl;
	}
};

class CompactDisc:public Product {
	string DiscName, singer;
public:
	CompactDisc(string descP = "", string producer = "", int price = 0, int PID = 0, string DiscName = "", string singer = "") :Product(descP, producer, price, PID) {
		this->DiscName = DiscName;
		this->singer = singer;
	}
	virtual void write(string descP, string producer, int price, int PID, string DiscName, string singer) {
		Product::write(descP, producer, price, PID);
		this->DiscName = DiscName;
		this->singer = singer;
	}
	virtual void read() {
		Product::read();
		cout << "�ٹ� ���� : " << DiscName << endl << "���� : " << singer << endl;
	}
};

class ConversationBook :public Book {
	string language;
public:
	virtual void write(string descP, string producer, int price, int PID, string Bname, string author, int ISBN, string language) {
		Book::write(descP, producer, price, PID, Bname, author, ISBN);
		this->language = language;
	}
	virtual void read() {
		Book::read();
		cout << "��� : " << language << endl;
	}
};

int main() {
	int c, c2, pid = 0, ISBN, price;
	string descP, producer, Bname, author, language, DiscName, singer;
	Product *p[100];

	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;
	
	while (1) {
		cout << "��ǰ �߰� (1),  ��� ��ǰ ��ȸ(2),  ������(3)  >>";
		cin >> c;
		switch (c) {
		case 1:
			cout << "��ǰ ���� : å(1),  ����CD(2),  ȸȭå(3)  >>";
			cin >> c2;
			switch (c2) {
			case 1:
				p[pid] = (Product*) new Book;
				cout << "��ǰ ����>>";
				cin.ignore();
				getline(cin, descP);
				cout << "������>>";
				cin >> producer;
				cout << "����>>";
				cin >> price;
				cout << "å ����>>";
				cin.ignore();
				getline(cin, Bname);
				cout << "����>>";
				cin >> author;
				cout << "ISBN>>";
				cin >> ISBN;

				((Book*)p[pid++])->write(descP, producer, price, pid, Bname, author, ISBN);
				break;

			case 2:
				p[pid] = (Product*) new CompactDisc;
				cout << "��ǰ ����>>";
				cin.ignore();
				getline(cin, descP);
				cout << "������>>";
				cin >> producer;
				cout << "����>>";
				cin >> price;
				cout << "�ٹ� ����>>";
				cin.ignore();
				getline(cin, DiscName);
				cout << "����>>";
				cin >> singer;

				((CompactDisc*)p[pid++])->write(descP, producer, price, pid, DiscName, singer);
				break;

			case 3:
				p[pid] = (Product*) new ConversationBook;
				cout << "��ǰ ����>>";
				cin.ignore();
				getline(cin, descP);
				cout << "������>>";
				cin >> producer;
				cout << "����>>";
				cin >> price;
				cout << "å ����>>";
				cin.ignore();
				getline(cin, Bname);
				cout << "����>>";
				cin >> author;
				cout << "ISBN>>";
				cin >> ISBN;
				cout << "���>>";
				cin >> language;

				((ConversationBook*)p[pid++])->write(descP, producer, price, pid, Bname, author, ISBN, language);
				break;
			}
			break;
		case 2:
			for (int i = 0; i < pid; i++) {
				p[i]->read();
			}
			break;
		case 3:
			return 0;
		}
	}
}