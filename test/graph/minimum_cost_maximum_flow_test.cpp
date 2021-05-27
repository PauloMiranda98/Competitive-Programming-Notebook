#include "../../code/graph/minimum_cost_maximum_flow.h"
typedef pair<int, int> pii;
void test1(){
  MCMF<int> mcmf(10);
  for (int i = 1; i <= 4; i++)
    mcmf.addEdge(0, i, 1, 0);

  mcmf.addEdge(1, 5, 1, 2);
  mcmf.addEdge(2, 5, 1, 0);
  mcmf.addEdge(2, 6, 1, 4);
  mcmf.addEdge(2, 7, 1, 6);
  mcmf.addEdge(3, 6, 1, 1);
  mcmf.addEdge(3, 7, 1, 1);
  mcmf.addEdge(3, 8, 1, 1);
  mcmf.addEdge(4, 7, 1, 10);

  for (int i = 5; i <= 8; i++)
    mcmf.addEdge(i, 9, 1, 0);
  auto ans = mcmf.solve(0, 9);
  assert(ans.first == 4);
  assert(ans.second == 17);
}
void test2(){
  assert(true); // AC: https://cses.fi/problemset/task/2121/ 
}
int main(){
  test1();
  test2();
  return 0;
}