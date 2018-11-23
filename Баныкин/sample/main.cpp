#include "JobStream.h"

int main() {
	double q1 = 0.1;
	double q2 = 0.1;
	int cores = 1;
	int ticks = 100000;
	int queueSize = 1;

	JobStream j(q1, q2, cores, ticks, queueSize);
	j.Start();
	j.PrintInfo();

	system("pause");
	return 0;
}