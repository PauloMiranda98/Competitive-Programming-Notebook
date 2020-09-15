#include "../../code/graph/arborescence.h"
void test(){
  Arborescence::init();
  Arborescence::addEdge(1, 0, 10);
  assert(Arborescence::dmst(2, 0) == -1);
  assert(Arborescence::dmst(2, 1) == 10);
  assert(Arborescence::dmstAnyRoot(2) == 10);

  Arborescence::init();
  Arborescence::addEdge(0, 1, 10);
  Arborescence::addEdge(0, 2, 10);
  Arborescence::addEdge(1, 3, 20);
  Arborescence::addEdge(2, 3, 30);
  assert(Arborescence::dmst(4, 0) == 40);
  assert(Arborescence::dmstAnyRoot(4) == 40);

  Arborescence::init();
  Arborescence::addEdge(0, 1, 10);
  Arborescence::addEdge(1, 2, 20);
  Arborescence::addEdge(2, 0, 30);
  Arborescence::addEdge(2, 3, 100);
  assert(Arborescence::dmst(4, 0) == 130);

  assert(true); // AC in https://codeforces.com/gym/102483/problem/F
  assert(true); // AC in https://vjudge.net/problem/UVA-11183
}
int main(){
  test();
  return 0;
}
