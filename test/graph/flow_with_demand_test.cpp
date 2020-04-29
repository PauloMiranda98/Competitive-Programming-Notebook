#include "../../code/graph/flow_with_demand.h"
typedef pair<int, int> pii;
void test1(){
  MaxFlowEdgeDemands<int> mfd(4);
  mfd.addEdge(0, 1, 5, 3);
  mfd.addEdge(0, 2, 2, 2);
  mfd.addEdge(1, 3, 1, 2);
  mfd.addEdge(2, 3, 5, 0);

  assert(mfd.solve(0, 3) == false);
}

void test2(){
  MaxFlowEdgeDemands<int> mfd(4);
  mfd.addEdge(0, 1, 3, 2);
  mfd.addEdge(0, 2, 2, 2);
  mfd.addEdge(1, 3, 1, 2);
  mfd.addEdge(2, 3, 5, 0);

  assert(mfd.solve(0, 3) == true);
}

int main(){
  test1();
  test2();
  return 0;
}