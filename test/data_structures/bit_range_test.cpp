#include "../../code/data_structures/bit_range.h"

void testAddAndGet(){
	BitRange bit(10);
	bit.add(1, 1, 2);
	bit.add(1, 2, 1);
	bit.add(2, 4, 3);

	assert(bit.get(1, 1) == 3);
	assert(bit.get(2, 2) == 4);
	assert(bit.get(3, 3) == 3);
	assert(bit.get(4, 4) == 3);
	assert(bit.get(5, 5) == 0);

	assert(bit.get(1) == 3);
	assert(bit.get(2) == 7);
	assert(bit.get(3) == 10);
	assert(bit.get(4) == 13);
	assert(bit.get(5) == 13);	
}

int main() {		
	testAddAndGet();
	return 0;
}
