#pragma once

#define MAX_QUEUE_SIZE 2147483646

template <class T>
class queue {
	int size = -1;
	int begin;
	int end;
	int elem_counter;

	T *pQueue;
public:
	queue(int size) {
		if (size < 0 || size > MAX_QUEUE_SIZE)
			throw "Queue size error";

		this->size = size;
		pQueue = new T[size];
		begin = end = elem_counter = 0;
	}
	~queue() {
		delete[] pQueue;
	}

	bool full() {
		return elem_counter == size;
	}

	bool empty() {
		return elem_counter == 0;
	}

	void push(const T &elem) {
		if (full())
			throw "Queue is full";

		pQueue[end] = elem;

		++elem_counter;
		++end %= size;
	}

	T pop() {
		if (empty())
			throw "Queue is empty";

		T result = pQueue[begin];

		--elem_counter;
		++begin %= size;

		return result;
	}
};

