#include "../../code/miscellaneous/identify_pattern.h"
void test(){
  assert(identifyPattern({1, 2, 3, 2, 2, 2, 2, 2, 2}) == pii(3, 1));
  assert(identifyPattern({1, 2, 3, 2, 3, 2, 3, 2, 3}) == pii(1, 2));
  assert(identifyPattern({1, 2, 3, 3, 2, 3, 3, 2, 3}) == pii(1, 3));
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  test();
  return 0;
}
