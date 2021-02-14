#include "../../code/graph/centroid_decomposition.h"
void test1(){
  int n = 5, k = 2;
  CD::init(n);
  CD::addEdge(0, 1);
  CD::addEdge(1, 2);
  CD::addEdge(2, 3);
  CD::addEdge(2, 4);
  assert(CD::solve(k) == 4);
}
int main(){
  test1();
  return 0;
}