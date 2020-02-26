#include "../../code/data_structures/set_and_clear.h"

void testSetAndClear(){
	SetAndClear sc(1, 10);
  assert(sc.count() == 0);
  sc.set(2, 5);
  assert(sc.count() == 4);
  sc.set(1, 10);
  assert(sc.count() == 10);
  sc.clear(2, 4);
  assert(sc.count() == 7);
  sc.clear(3, 3);
  assert(sc.count() == 7);
  sc.clear(9, 10);
  assert(sc.count() == 5);
  sc.clear(1, 1);
  assert(sc.count() == 4);
  sc.clear(5, 6);
  assert(sc.count() == 2);
  sc.clear(8, 8);
  assert(sc.count() == 1);
  sc.clear(7, 7);
  assert(sc.count() == 0);
}

int main() {		
	testSetAndClear();
	return 0;
}
