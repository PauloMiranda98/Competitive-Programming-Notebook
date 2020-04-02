#include "../../code/data_structures/dynamic_median.h"
const double EPS = 1e-9;

void testAddAndGet(){
	DinamicMedian md;
	md.push(10);
	md.push(50);
	md.push(5);
	assert(abs(md.median() - 10) < EPS);

	md.push(5);
	assert(abs(md.median() - 7.5) < EPS);

	md.push(2);
	assert(abs(md.median() - 5) < EPS);

	md.push(50);
	md.push(30);
	assert(abs(md.median() - 10) < EPS);
}

int main(){
	testAddAndGet();
	return 0;
}
