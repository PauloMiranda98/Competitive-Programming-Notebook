#include "../../code/graph/dinic.h"
typedef pair<int, int> pii;
void test1(){
  Dinic dinic(10);
  for(int i=1; i<=4; i++)
    dinic.addEdge(0, i, 1);

  dinic.addEdge(1, 5, 1);
  dinic.addEdge(2, 5, 1);
  dinic.addEdge(2, 6, 1);
  dinic.addEdge(2, 7, 1);
  dinic.addEdge(3, 6, 1);
  dinic.addEdge(3, 7, 1);
  dinic.addEdge(3, 8, 1);
  dinic.addEdge(4, 7, 1);

  for(int i=5; i<=8; i++)
    dinic.addEdge(i, 9, 1);
  ll ans = dinic.maxFlow(0, 9);
  assert(ans == 4);
}
int main(){
  test1();
  return 0;
}