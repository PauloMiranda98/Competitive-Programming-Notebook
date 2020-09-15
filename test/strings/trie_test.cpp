#include "../../code/strings/trie.h"

void test(){
  Trie t; 
  t.add("paulo");
  t.add("paula");
  assert(t.countPre("paulo") == 1);
  assert(t.countPre("paula") == 1);
  assert(t.countPre("paul") == 2);
  assert(t.countStr("paulo") == 1);
  assert(t.countStr("paula") == 1);
  assert(t.countStr("paul") == 0);

  assert(t.remove("paul") == false);
  assert(t.remove("paulo") == true);
  assert(t.remove("paulo") == false);

  assert(t.countPre("paulo") == 0);
  assert(t.countPre("paula") == 1);
  assert(t.countPre("paul") == 1);
  assert(t.countStr("paulo") == 0);
  assert(t.countStr("paula") == 1);
  assert(t.countStr("paul") == 0);
}

int main() {
  test();
  return 0; 
}
