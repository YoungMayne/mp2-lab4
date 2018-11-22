#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include "queue.h"

#define RAND_MAX 32767.00
#define DRAND (rand() / RAND_MAX)
#define print(expression1, expression2) (std::cout << expression1 << expression2 << std::endl)

//
class JobStream {
	class Task {
		double limit;
		bool r = true;
	public:
		Task(double limit) {
			this->limit = limit;
		}
		void add() {
			r = false;
		}
		bool done() {
			return r = DRAND < limit;
		}
		bool ready() {
			return r;
		}
	};

	struct Stats {
		int number_of_cores = 0;
		int total_ticks = 0;
		int lost_tasks = 0;
		int finished_tasks = 0;
	}stats;

	std::vector<Task> cArray;
	queue<int> *tList;

	double limit;
public:
	JobStream(double limit, double taskLimit, int cores, int ticks, int size) {
		srand(time(NULL));
		this->limit = limit;

		stats.number_of_cores = cores;
		stats.total_ticks = ticks;

		tList = new queue<int>(size);
		for (int i = 0; i < stats.number_of_cores; ++i)
			cArray.push_back(Task(taskLimit));

	}

	void Start() {
		int ticks = stats.total_ticks;
		while (ticks--) {
			if (DRAND < limit)
				if (!tList->full())
					tList->push(NULL);
				else
					++stats.lost_tasks;

			for (auto &c : cArray)
				if (c.ready()) {
					if (!tList->empty()) {
						c.add();
						tList->pop();
					}
				}
				else if (c.done())
					stats.finished_tasks++;
		}
	}

	void PrintInfo() {
		int total_tasks = stats.lost_tasks + stats.finished_tasks;
		double percent = (double)stats.finished_tasks / (double)total_tasks * 100;

		print("Total cores:\t", stats.number_of_cores);
		print("Total ticks:\t", stats.total_ticks);
		print("Total tasks:\t", total_tasks);
		print("\nFinished tasks:\t", stats.finished_tasks);
		print("Lost tasks:\t", stats.lost_tasks);
		print("\nEfficiency %:\t", percent);
	}

	~JobStream() {
		delete tList;
	}
};