#include "../../code/geometry/convex_hull_trick.h"

void testAddAndGet(){
  ConvexHullTrick cht;
  cht.add_line(-1, 10);
  cht.add_line(0, -6);
  cht.add_line(2, 30);

  for (int x = -100; x >= -18; x--)
    assert(cht.get(x) == (2 * x + 30));
  for (int x = -18; x <= 16; x++)
    assert(cht.get(x) == (0 * x - 6));
  for (int x = 16; x <= 100; x++)
    assert(cht.get(x) == (-1 * x + 10));
}

int main(){
  testAddAndGet();
  return 0;
}