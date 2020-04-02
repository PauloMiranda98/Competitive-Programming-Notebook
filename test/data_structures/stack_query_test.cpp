#include "../../code/data_structures/stack_query.h"

void testPushAndQuery(){
	StackQuery sq; //Minimum
	sq.push(10);
	sq.push(1);
	sq.push(8);
	sq.push(5);

	assert(sq.top() == 5);
	assert(sq.query() == 1);
	assert(sq.size() == 4);
	sq.pop();
	assert(sq.top() == 8);
	assert(sq.query() == 1);
	assert(sq.size() == 3);
	sq.pop();
	assert(sq.top() == 1);
	assert(sq.query() == 1);
	assert(sq.size() == 2);
	sq.pop();
	sq.push(-2);
	assert(sq.top() == -2);
	assert(sq.query() == -2);
	assert(sq.size() == 2);
	sq.pop();
	assert(sq.top() == 10);
	assert(sq.query() == 10);
	assert(sq.size() == 1);
	sq.pop();
	assert(sq.size() == 0);
}

int main(){
	testPushAndQuery();
	return 0;
}
