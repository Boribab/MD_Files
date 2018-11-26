#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
	class SafeQueue {
	public:
		SafeQueue() = default;
		virtual ~SafeQueue() {}
		void enqueue(T& data);
		T& dequeue();

	private:
		std::queue<T> q;
		mutable std::mutex m;
		mutable std::condition_variable c;
	};

template <typename T>
void SafeQueue<T>::enqueue(T& data) {
	std::lock_guard<std::mutex> lock(m);
	q.push(data);
	c.notify_one();
}

template <typename T>
T& SafeQueue<T>::dequeue() {
	std::unique_lock<std::mutex> lock(m);
	c.wait(lock, [&] {return !q.empty(); });
	T &val = q.front();
	q.pop();
	return val;
}