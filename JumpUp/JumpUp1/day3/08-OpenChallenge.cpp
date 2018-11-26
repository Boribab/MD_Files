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
		cout << "--- 상품ID : " << PID << endl << "상품설명 : " << descP << endl << "생산자 : " << producer << endl << "가격 : " << price << endl;
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
		cout << "ISBN : " << ISBN << endl << "책 제목 : " << Bname << endl << "저자 : " << author << endl;
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
		cout << "앨범 제목 : " << DiscName << endl << "가수 : " << singer << endl;
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
		cout << "언어 : " << language << endl;
	}
};

int main() {
	int c, c2, pid = 0, ISBN, price;
	string descP, producer, Bname, author, language, DiscName, singer;
	Product *p[100];

	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
	
	while (1) {
		cout << "상품 추가 (1),  모든 상품 조회(2),  끝내기(3)  >>";
		cin >> c;
		switch (c) {
		case 1:
			cout << "상품 종류 : 책(1),  음악CD(2),  회화책(3)  >>";
			cin >> c2;
			switch (c2) {
			case 1:
				p[pid] = (Product*) new Book;
				cout << "상품 설명>>";
				cin.ignore();
				getline(cin, descP);
				cout << "생산자>>";
				cin >> producer;
				cout << "가격>>";
				cin >> price;
				cout << "책 제목>>";
				cin.ignore();
				getline(cin, Bname);
				cout << "저자>>";
				cin >> author;
				cout << "ISBN>>";
				cin >> ISBN;

				((Book*)p[pid++])->write(descP, producer, price, pid, Bname, author, ISBN);
				break;

			case 2:
				p[pid] = (Product*) new CompactDisc;
				cout << "상품 설명>>";
				cin.ignore();
				getline(cin, descP);
				cout << "생산자>>";
				cin >> producer;
				cout << "가격>>";
				cin >> price;
				cout << "앨범 제목>>";
				cin.ignore();
				getline(cin, DiscName);
				cout << "가수>>";
				cin >> singer;

				((CompactDisc*)p[pid++])->write(descP, producer, price, pid, DiscName, singer);
				break;

			case 3:
				p[pid] = (Product*) new ConversationBook;
				cout << "상품 설명>>";
				cin.ignore();
				getline(cin, descP);
				cout << "생산자>>";
				cin >> producer;
				cout << "가격>>";
				cin >> price;
				cout << "책 제목>>";
				cin.ignore();
				getline(cin, Bname);
				cout << "저자>>";
				cin >> author;
				cout << "ISBN>>";
				cin >> ISBN;
				cout << "언어>>";
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