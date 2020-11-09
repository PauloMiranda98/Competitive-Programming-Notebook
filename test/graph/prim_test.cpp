#include "../../code/graph/prim.h"
void test1(){
  int n = 5;
  Prim::init(n);
  Prim::addEdge(0, 1, 15);
  Prim::addEdge(0, 2, 10);
  Prim::addEdge(1, 2, 1);
  Prim::addEdge(2, 3, 3);
  Prim::addEdge(1, 3, 5);
  Prim::addEdge(3, 4, 20);
  assert(Prim::solve() == 34);
}
void test2(){
  int n = 5;
  Prim::init(n);
  Prim::addEdge(0, 1, 1);
  Prim::addEdge(0, 2, 10);
  Prim::addEdge(0, 3, 1);
  Prim::addEdge(1, 2, 1);
  Prim::addEdge(1, 3, 10);
  Prim::addEdge(2, 3, 1);
  assert(Prim::solve() == 3);
}
int main(){
  test1();
  test2();
  return 0;
}
