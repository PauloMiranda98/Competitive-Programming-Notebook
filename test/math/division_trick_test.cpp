#include "../../code/math/division_trick.h"
void test1(){
  for(int i=1; i<=1000; i++)
    assert(bruteForce(i) == divisionTrick(i));
  
  assert(bruteForce(1e7) == divisionTrick(1e7));
  assert(bruteForce(1e7 + 5) == divisionTrick(1e7 + 5));
  assert(bruteForce(1e6 + 7) == divisionTrick(1e6 + 7));
  assert(true); // https://cses.fi/problemset/task/1082
}
int main() {
  test1();
  return 0;
}
