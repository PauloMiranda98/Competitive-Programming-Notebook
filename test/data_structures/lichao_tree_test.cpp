#include "../../code/data_structures/lichao_tree.h"

void testAddAndGet(){
	LiChaoTree lct(-100, 100);
	lct.add(1, -10);
	lct.add(-2, -30);	
	
	for(int x=-100; x>=-7; x--)
		assert(lct.get(x) == (-2*x - 30));		
	for(int x=-6; x<=100; x++)
		assert(lct.get(x) == (1*x - 10));		
	
	lct.add(0, 6);
	for(int x=-100; x>=-18; x--)
		assert(lct.get(x) == (-2*x - 30));		
	for(int x=-18; x<=16; x++)
		assert(lct.get(x) == (0*x + 6));		
	for(int x=16; x<=100; x++)
		assert(lct.get(x) == (1*x -10));		
}

int main() {		
	testAddAndGet();
	return 0;	
}