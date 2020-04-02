#include "../../code/data_structures/bit2d.h"

void testAddAndGet(){
	Bit2d bit(10, 10);
	bit.add(1, 1, 5);
	bit.add(2, 1, 3);
	bit.add(1, 3, 2);

	assert(bit.get(1, 1) == 5);
	assert(bit.get(2, 1) == 8);
	assert(bit.get(1, 3) == 7);
	assert(bit.get(3, 3) == 10);

	assert(bit.get(2, 2, 3, 3) == 0);
	assert(bit.get(1, 1, 1, 1) == 5);
	assert(bit.get(2, 1, 2, 1) == 3);
	assert(bit.get(1, 3, 1, 3) == 2);
}

int main(){
	testAddAndGet();
	return 0;
}
