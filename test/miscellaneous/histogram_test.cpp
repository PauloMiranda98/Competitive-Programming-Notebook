#include "../../code/miscellaneous/histogram.h"
void test1(){
  assert(histogram({1, 1, 1, 1, 1}) == 5);
  assert(histogram({1, 2, 3, 2, 1}) == 6);
  assert(histogram({1}) == 1);
  assert(histogram({1, 2, 3, 4, 20}) == 20);
  
  assert(true); // AC: https://leetcode.com/problems/largest-rectangle-in-histogram/
}
int main() {
  test1();
  return 0;
}
