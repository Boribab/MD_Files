#include "safe_queue.h"
#include <iostream>
#include <thread>

using namespace std;

SafeQueue<int> *q = new SafeQueue<int>();

void printfQueue() {
	while (1) {
		cout << q->dequeue() << endl;
	}
}

void addQueue() {
	for (int i = 0; i < 100; i++)
		q->enqueue(i);
}

int main() {
	thread t1 = thread(printfQueue);
	thread t2 = thread(addQueue);

	t1.join();
	t2.join();

	return 0;
}