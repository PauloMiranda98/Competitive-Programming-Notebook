#include "../../code/data_structures/bit.h"

void testAddAndGet(){
	Bit bit(10);
	bit.add(1, 2);
	bit.add(4, 3);
	bit.add(7, 5);

	assert(bit.get(1, 1) == 2);
	assert(bit.get(4, 4) == 3);
	assert(bit.get(7, 7) == 5);

	assert(bit.get(1) == 2);
	assert(bit.get(4) == 5);
	assert(bit.get(7) == 10);
}

void testGetPosition(){
	Bit bit(10);
	bit.add(1, 2);
	bit.add(4, 3);
	bit.add(7, 5);

	assert(bit.get(1) == 2);
	assert(bit.get(4) == 5);
	assert(bit.get(7) == 10);

	assert(bit.lower_bound(2) == 1);
	assert(bit.lower_bound(5) == 4);
	assert(bit.lower_bound(10) == 7);
}

int main(){
	testAddAndGet();
	testGetPosition();
	return 0;
}
