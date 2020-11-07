#include "../../code/graph/dijkstra.h"

void test1(){
  int n = 4;
  Dijkstra::init(n);
  Dijkstra::addEdge(0, 1, 1);
  Dijkstra::addEdge(0, 2, 3);
  Dijkstra::addEdge(0, 3, 9);
  Dijkstra::addEdge(1, 3, 2);
  Dijkstra::addEdge(2, 3, 2);

  auto d = Dijkstra::solve(0);
  vector<Dijkstra::T> ans = {0, 1, 3, 3};
  assert(ans == d);
}

void test2(){ // AC: https://neps.academy/problem/297
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  Dijkstra::init(n+2);
  for(int i=0; i<m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    Dijkstra::addEdge(a, b, w);
    Dijkstra::addEdge(b, a, w);
  }
  auto d = Dijkstra::solve(0);
  cout << d[n+1] << endl;
}
int main(){
  test1();
//  test2();
  return 0;
}
