#include <cstdio>
#include <thread>

using namespace std;

class Counter {
public:
	Counter(int id, int length) {
		mId = id;
		mLength = length;
	}
	void loop() const {
		for (int i = 1; i <= mLength; i++) {
			printf("counter[%d] : %d\n", mId, i);
		}
	}
private:
	int mId;
	int mLength;
};

int main() {
	Counter c1(1, 7);
	Counter c2(2, 7);

	thread t1{ &Counter::loop, &c1 };
	thread t2{ &Counter::loop, &c2 };

	t1.join();
	t2.join();

	return 0;
}