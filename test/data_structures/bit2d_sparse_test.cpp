#include "../../code/data_structures/bit2d_sparse.h"

void testAddAndGet(){
  Bit2d::add(1, 1);
  Bit2d::add(2, 1);
  Bit2d::add(1, 3);

  assert(Bit2d::get(1, 1) == 1);
  assert(Bit2d::get(2, 1) == 2);
  assert(Bit2d::get(1, 3) == 2);
  assert(Bit2d::get(3, 3) == 3);

  assert(Bit2d::get(2, 2, 3, 3) == 0);
  assert(Bit2d::get(1, 1, 1, 1) == 1);
  assert(Bit2d::get(2, 1, 2, 1) == 1);
  assert(Bit2d::get(1, 3, 1, 3) == 1);
}

int main(){
  testAddAndGet();
  return 0;
}
