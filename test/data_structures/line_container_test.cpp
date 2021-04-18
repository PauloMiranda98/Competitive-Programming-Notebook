#include "../../code/data_structures/line_container.h"

void testAddAndGet(){
  LineContainer lc;
  lc.add(1, -10);
  lc.add(-2, -30);

  for (int x = -100; x >= -7; x--)
    assert(lc.getMax(x) == (-2 * x - 30));
  for (int x = -6; x <= 100; x++)
    assert(lc.getMax(x) == (1 * x - 10));

  lc.add(0, 6);
  for (int x = -100; x >= -18; x--)
    assert(lc.getMax(x) == (-2 * x - 30));
  for (int x = -18; x <= 16; x++)
    assert(lc.getMax(x) == (0 * x + 6));
  for (int x = 16; x <= 100; x++)
    assert(lc.getMax(x) == (1 * x - 10));
}

int main(){
  testAddAndGet();
  return 0;
}