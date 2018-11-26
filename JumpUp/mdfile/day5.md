# 2018년 7월 27일 금요일 수업 일지
## vector란?
+ STL안에 있는 라이브러리

+ 가변적 길이를 가진 배열 
+ vector<자료형> 변수이름; 으로 선언
+ size - 원소의 개수
+ capacity - 벡터의 크기
+ begin - 원소의 시작 지점
+ end - 원소의 끝 지점
+ push_back - 끝에 값 푸쉬

### vector 기본 예제
```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v[0] = 10;
	int n = v[2];
	v.at(2) = 5;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
```
```
출력 :

1 2 3
10 2 5
```

## iterator란?
+ vector의 반복자

### vector의 iterator 예제
```c++
#include <iostream>
#include <vector>
#include <array>
using namespace std;
using MyVector = vector<int>;

void VectorIterators(MyVector myVector);
void FindInVector(MyVector myVector);
bool VDescending(int first, int second);

int main(int argc, char* argv[]) {
	MyVector myVector = { 0,1,2 };
	myVector.push_back(3);
	myVector.push_back(4);
	MyVector::const_iterator iter = myVector.cbegin() + 1;
	myVector.insert(iter, 5);
	MyVector::iterator it = myVector.begin();
	myVector.erase(it);
	sort(myVector.begin(), myVector.end(), VDescending);
	sort(myVector.begin(), myVector.end());
	VectorIterators(myVector);
	FindInVector(myVector);
	return 0;
}

void VectorIterators(MyVector myVector) {
	for (MyVector::iterator iter = myVector.begin(); iter != myVector.end(); iter++) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::iterator iter = myVector.end() - 1; iter != myVector.begin(); --iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::reverse_iterator iter = myVector.rbegin(); iter != myVector.rend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::const_iterator iter = myVector.cbegin(); iter != myVector.cend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::const_reverse_iterator iter = myVector.crbegin(); iter != myVector.crend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (auto iter = myVector.begin(); iter != myVector.end(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (auto iter = myVector.cbegin(); iter != myVector.cend(); ++iter) {
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::iterator iter = myVector.begin(); iter != myVector.end(); ++iter) {
		*iter = 5;
		cout << *iter << endl;
	}
	cout << endl << endl;

	for (MyVector::const_iterator iter = myVector.cbegin(); iter != myVector.cend(); ++iter) {
		//*iter = 5;
		cout << *iter << endl;
	}
	cout << endl << endl;
}

void FindInVector(MyVector myVector) {
	for (unsigned int i = 0; i < myVector.size(); ++i) {
		if (myVector[i] == 2) {
			cout << "Found : " << myVector[i] << " at position : " << i << endl;
		}
	}

	for (auto iter = myVector.begin(); iter != myVector.end(); ++iter) {
		if (*iter == 2) {
			cout << "Found : " << *iter << endl;
		}
	}

	for (auto& number : myVector) {
		if (number == 2) {
			cout << "Found : " << number << endl;
		}
	}

	MyVector::iterator found = find(myVector.begin(), myVector.end(), 2);
	if (found != myVector.end()) {
		cout << "Found : " << *found << endl;
	}
}

bool VDescending(int first, int second) {
	return first > second;
}
```
```
출력 :

1
2
3
4
5


5
4
3
2


5
4
3
2
1


1
2
3
4
5


5
4
3
2
1


1
2
3
4
5


1
2
3
4
5


5
5
5
5
5


5
5
5
5
5


Found : 2 at position : 1
Found : 2
Found : 2
Found : 2
```
### vector를 이용한 나라 맞추기 게임
```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Nation {
	string nation, capital;
public:
	void set(string na, string ca) {
		nation = na;
		capital = ca;
	}
	int quiz() {
		string ans;

		cout << nation << "의 수도는? >>> ";
		cin >> ans;

		if (ans == "exit") return -1;

		if (ans == capital) return 1;
		else return 0;
	}
};

int main() {
	vector<Nation> v;
	int n, c;
	string ans, na, ca;
	Nation a;

	cout << "***** 나라의 수도 맞추기 게임 시작 *****" << endl;

	while (1) {
		cout << "정보 입력(1)   퀴즈(2)   종료(3) >>> ";
		cin >> n;

		switch (n) {
		case 1:
			cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl << "나라와 수도를 입력하세요 (no no 이면 입력 끝)" << endl;	
			while (1) {
				cout << v.size() << "번째 나라 입력 >> ";
				cin >> na >> ca;
				if (na == "no" && ca == "no") break;
				else {
					a.set(na, ca);
					v.push_back(a);
				}
			}
			break;
		case 2:
			for (int i = 0; i < v.size(); i++) {
				c = v[i].quiz();
				if (c == 1) {
					cout << "Correct!!" << endl;
				}
				else if (c == 0)	cout << "No!!" << endl;
				else break;
			}
			break;
		case 3:
			return 0;
		}
	}
}
```
```
입력&출력 :

***** 나라의 수도 맞추기 게임 시작 *****
정보 입력(1)   퀴즈(2)   종료(3) >>> 1
현재 0개의 나라가 입력되어 있습니다.
나라와 수도를 입력하세요 (no no 이면 입력 끝)
0번째 나라 입력 >> 한국 서울
1번째 나라 입력 >> 일본 도쿄
2번째 나라 입력 >> no no
정보 입력(1)   퀴즈(2)   종료(3) >>> 2
한국의 수도는? >>> 서울
Correct!!
일본의 수도는? >>> 도쿄
Correct!!
정보 입력(1)   퀴즈(2)   종료(3) >>> 3
```

### vector를 이용한 원 생성 삭제 프로그램

+ erase 함수를 사용하여 삭제

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14*radius*radius; }
	string getName() { return name; }
};

Circle* mCircle(string name, int radius) {
	return new Circle(radius, name);;
}	

int main() {
	vector<Circle*> c;
	vector<Circle*>::iterator it = c.begin();
	int n, radius;
	Circle* a;
	string name;

	cout << "원을 생성하고 삭제하는 프로그램입니다." << endl;
	
	while (1) {
		cout << "삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> ";
		cin >> n;
		
		switch (n) {
		case 1:
			cout << "생성하고자 하는 원의 반지름과 이름은? >> ";
			cin >> radius >> name;
			a = mCircle(name, radius);
			c.push_back(a);
			break;
		case 2:
			cout << "삭제하고자 하는 원의 이름은? >> ";
			cin >> name;
			for (auto it = c.begin(); it != c.end(); ) {
				if ((*it)->getName() == name) {
					it = c.erase(it);
				}
				else
					++it;
			}
			break;
		case 3:
			for (int i = 0; i < c.size(); i++) {
				cout << c[i]->getName() << endl;
			}
			break;
		case 4:
			return 0;
		}
	}
}
```
```
입력&출력 :

원을 생성하고 삭제하는 프로그램입니다.
삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> 1
생성하고자 하는 원의 반지름과 이름은? >> 4 감자
삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> 1
생성하고자 하는 원의 반지름과 이름은? >> 3 도넛
삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> 1
생성하고자 하는 원의 반지름과 이름은? >> 5 감자
삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> 3
감자
도넛
감자
삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> 2
삭제하고자 하는 원의 이름은? >> 감자
삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> 3
도넛
삽입(1)   삭제(2)   모두 보기(3)   종료(4) >>> 4
```
## map이란?
+ vector같은 가변적 배열

+ map<first, second>의 구조
+ map<자료형, 자료형> 변수이름; 으로 선언

### map을 이용한 암호 관리 프로그램
```c++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> m;
	map<string, string>::iterator it = m.begin();
	int n;
	string id, pw, in;
	
	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;

	while (true) {
		id = "", pw = "", in = "";
		cout << "삽입(1)   검사(2)   종료(3) >> ";
		cin >> n;
		
		switch (n) {
		case 1:
			cout << "이름 암호 입력 >> ";
			cin >> id >> pw;
			m.emplace(id, pw);
			break;
		case 2:
			cout << "이름 >> ";
			cin >> id;
			
			for (it = m.begin(); it != m.end(); it++) {
				if (it->first == id) {
					pw = it->second;
					break;
				}
			}
			while (1) {
				cout << "암호 >> ";
				cin >> in;
				if (in == pw) {
					cout << "통과" << endl;
					break;
				}
				else {
					cout << "실패" << endl;
				}
			}
			break;
		case 3:
			return 0;
		}
	}
}
```
```
입력&출력 :

***** 암호 관리 프로그램 WHO를 시작합니다 *****
삽입(1)   검사(2)   종료(3) >> 1
이름 암호 입력 >> park c++
삽입(1)   검사(2)   종료(3) >> 1
이름 암호 입력 >> lee java
삽입(1)   검사(2)   종료(3) >> 2
이름 >> park
암호 >> java
실패
암호 >> c#
실패
암호 >> c++
통과
삽입(1)   검사(2)   종료(3) >> 3
```

## 파일 입출력
+ fstream 라이브러리 사용

+ ofstream을 사용해서 쓰기 위해 파일 열기
+ ifstream을 사용해서 읽기 위해 파일 열기

### ofstream으로 파일 열기 예제
```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;

	cout << "이름 >> ";
	cin >> name;
	cout << "학번 >> ";
	cin >> sid;
	cout << "학과 >> ";
	cin >> dept;

	ofstream f("C:\\temp\\student.txt");
	if (!f) {
		cout << "student 파일을 열 수 없다" << endl;
		return 0;
	}

	f << name << endl;
	f << sid << endl;
	f << dept << endl;

	f.close();
}
```
```
입력 :

박보현
20406
정보보안과

출력 :

student.txt
->
박보현
20406
정보보안과
```

### ifstream으로 파일 열기 예제
```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("C:\\temp\\student.txt");
	if (!fin) {
		cout << "파일을 열 수 없다";
		return 0;
	}

	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;
	
	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();
}
```
```
출력:

박보현
20406
정보보안과
```

## fstream 모드
+ ios::in - 읽기만 가능

+ ios::out - 쓰기만 가능
+ ios::app - 원래 있던 정보 뒤에 쓰기

### 예시
```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char* firstFile = "c:\\temp\\student.txt";
	char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);
	if (!fout) {
		cout << firstFile << " 열기 오류" << endl;
		return 0;
	}
	fstream fin(secondFile, ios::in);
	if (!fin) {
		cout << secondFile << " 열기 오류" << endl;
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c);
	}

	fin.close();
	fout.close();
}
```
```
결과 :

student.txt
->
박보현
20406
정보보안과
; for 16-bit app support
[386Enh]
woafont=dosapp.fon
EGA80WOA.FON=EGA80WOA.FON
EGA40WOA.FON=EGA40WOA.FON
CGA80WOA.FON=CGA80WOA.FON
CGA40WOA.FON=CGA40WOA.FON

[drivers]
wave=mmdrv.dll
timer=timer.drv

[mci]
```
### 파일 입출력을 이용한 단어장 예제
```c++
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void fileRead(vector<string> &v, ifstream &fin) {
	string line;
	while (true) {
		getline(fin, line);
		if (fin.eof()) break;
		v.push_back(line);
	}
}

void search(vector<string> &v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);
		if (index != -1)
			cout << v[i] << endl;
	}
}

int main() {
	vector<string> wordVector;
	
	ifstream fin("c:\\temp\\words.txt");
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다." << endl;
		return 0;
	}
	fileRead(wordVector, fin);
	cout << "words.txt 파일을 읽었습니다." << endl;
	fin.close();
	while (true) {
		cout << "검색할 단어를 입력하세요 >> ";
		string word;
		getline(cin, word);
		if (word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "프로그램을 종료합니다." << endl;
}
```
```
입력&출력 :

words.txt 파일을 읽었습니다.
검색할 단어를 입력하세요 >> love
belove
clove
cloven
foxglove
gloves
love
lovebird
lovelorn
plover
pullover
sloven
검색할 단어를 입력하세요 >> exit
프로그램을 종료합니다.
```
### 단어장을 이용한 행맨 게임
```c++
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

void fileRead(vector<string> &v, ifstream &fin) {
	string line;
	while (true) {
		getline(fin, line);
		if (fin.eof()) break;
		v.push_back(line);
	}
}

int main() {
	vector<string> word;
	int hp = 5, chk;
	char ans, next;
	string w;
	srand((unsigned)time(0));

	ifstream fin("c:\\temp\\words.txt");
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다." << endl;
		return 0;
	}

	fileRead(word, fin);

	fin.close();

	cout << "----- 지금부터 행맨 게임을 시작합니다 -----" << endl;

	while (true) {
		hp = 5;
		chk = 0;
		int n = rand() % word.size();
		w = word[n];
		int n2 = rand() % w.length();
		int n3 = rand() % w.length();


		if (n2 == n3) continue;

		while (true) {
			if (hp == 0) {
				cout << "End" << endl << w << endl << "Next(y/n)? ";
				cin >> next;
				if (next == 'y') break;
				else return 0;
			}

			if (n2 == -1 && n3 == -1) {
				cout << endl << "Next(y/n)? ";
				cin >> next;
				if (next == 'y') break;
				else return 0;
			}

			for (int i = 0; i < w.length(); i++) {
				if (i != n2 && i != n3) {
					cout << w[i];
				}
				else cout << "-";
			}
			cout << endl << ">>";
			cin >> ans;

			if (n2 != -1) {
				if (w[n2] == ans) {
					n2 = -1;
					chk = 0;
				}
				else
					chk = 1;
			}

			if (n3 != -1) {
				if (w[n3] == ans) {
					n3 = -1;
					chk = 0;
				}
				else
					chk = 1;
			}
			if (chk == 1)
				hp -= 1;
		}
	}
}
```
```
입력&출력 :

----- 지금부터 행맨 게임을 시작합니다 -----
glov--
>>s
glov-s
>>e

Next(y/n)? y
-ov-bird
>>a
-ov-bird
>>b
-ov-bird
>>c
-ov-bird
>>d
-ov-bird
>>e
-ovebird
>>e
End
lovebird
Next(y/n)? n
```