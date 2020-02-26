#include "../../code/data_structures/queue_query.h"

void testPushAndQuery(){   
	QueueQuery qq; //Minimum
	qq.push(10);
	qq.push(1);
	qq.push(8);
	qq.push(5);

	assert(qq.front() == 10);
	assert(qq.query() == 1);
	assert(qq.size() == 4);
  qq.pop();
	assert(qq.front() == 1);
	assert(qq.query() == 1);
	assert(qq.size() == 3);
  qq.pop();
	assert(qq.front() == 8);
	assert(qq.query() == 5);
	assert(qq.size() == 2);
  qq.pop();
  qq.push(-2);
	assert(qq.front() == 5);
	assert(qq.query() == -2);
	assert(qq.size() == 2);
  qq.pop();
	assert(qq.front() == -2);
	assert(qq.query() == -2);
	assert(qq.size() == 1);
  qq.pop();
	assert(qq.size() == 0);
}

int main() {		
	testPushAndQuery();
	return 0;	
}