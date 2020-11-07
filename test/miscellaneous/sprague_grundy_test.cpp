#include "../../code/miscellaneous/sprague_grundy.h"
void test(){
  assert(solve({3, 3}) == "Second");
  assert(solve({3, 2}) == "First");
  assert(solve({1, 1, 1, 4}) == "First");
}
int main() {
  test();
  return 0;
}