#include "../../code/data_structures/union_find.h"

void testFindAndJoin(){
  UnionFind uf(10);
  for (int i = 0; i <= 10; i++)
    assert(uf.find(i) == i);
  uf.join(1, 3);
  assert(uf.find(1) == uf.find(3));
  uf.join(3, 4);
  assert(uf.find(1) == uf.find(4));
  assert(uf.find(3) == uf.find(4));
  uf.join(8, 10);
  assert(uf.find(8) == uf.find(10));
  for (int i = 0; i < 10; i++)
    uf.join(i, i + 1);
  for (int i = 0; i <= 10; i++)
    assert(uf.find(i) == uf.find(0));
}

int main(){
  testFindAndJoin();
  return 0;
}