#include "../../code/graph/mincut.h"

void test1(){
  MinCut::init(5);
  MinCut::addEdge(0, 1, 100);
  MinCut::addEdge(1, 2, 299);
  MinCut::addEdge(2, 4, 400);
  MinCut::addEdge(4, 3, 99);
  assert(MinCut::mincut().first == 99);
}

void test2(){
  MinCut::init(3);
  MinCut::addEdge(0, 1, 10);
  MinCut::addEdge(1, 2, 20);
  MinCut::addEdge(0, 2, 40);
  assert(MinCut::mincut().first == 30);
}

void test3(){
  MinCut::init(4);
  MinCut::addEdge(0, 1, 10);
  MinCut::addEdge(1, 2, 100);
  MinCut::addEdge(2, 3, 10);
  MinCut::addEdge(3, 0, 100);
  MinCut::addEdge(0, 2, 10);
  assert(MinCut::mincut().first == 30);
}

int main() {
  assert(true); // https://vjudge.net/problem/UVA-10989
  test1();
  test2();
  test3();
  return 0;
}
