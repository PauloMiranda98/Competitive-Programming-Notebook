#include "../../code/data_structures/range_color.h"

void testRangeColor(){
  RangeColor rc(1, 10, 1);
  assert(rc.countColor(0) == 10 and rc.countColor(1) == 0);
  rc.set(2, 5, 1);
  assert(rc.countColor(0) == 6 and rc.countColor(1) == 4);
  rc.set(1, 10, 1);
  assert(rc.countColor(0) == 0 and rc.countColor(1) == 10);
  rc.set(2, 4, 0);
  assert(rc.countColor(0) == 3 and rc.countColor(1) == 7);
  rc.set(3, 3, 0);
  assert(rc.countColor(0) == 3 and rc.countColor(1) == 7);
  rc.set(9, 10, 0);
  assert(rc.countColor(0) == 5 and rc.countColor(1) == 5);
  rc.set(1, 1, 0);
  assert(rc.countColor(0) == 6 and rc.countColor(1) == 4);
  rc.set(5, 6, 0);
  assert(rc.countColor(0) == 8 and rc.countColor(1) == 2);
  rc.set(8, 8, 0);
  assert(rc.countColor(0) == 9 and rc.countColor(1) == 1);
  rc.set(7, 7, 0);
  assert(rc.countColor(0) == 10 and rc.countColor(1) == 0);
}

int main(){
  testRangeColor();
  return 0;
}
