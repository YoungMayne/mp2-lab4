#include "JobStream.h"

int main() {
	double q1 = 0.6;
	double q2 = 0.1;
	int cores = 5;
	int ticks = 1000;
	int queueSize = 5;

	JobStream j(q1, q2, cores, ticks, queueSize);
	j.Start();
	j.PrintInfo();

	system("pause");
	return 0;
}