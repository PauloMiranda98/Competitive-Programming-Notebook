#include "../../code/graph/bfs01.h"

void test1(){
  int n=7;
  BFS01::init(n);
  BFS01::addEdge(0, 1, 0);
  BFS01::addEdge(1, 0, 1);
  BFS01::addEdge(2, 1, 0);
  BFS01::addEdge(1, 2, 1);
  BFS01::addEdge(2, 3, 0);
  BFS01::addEdge(3, 2, 1);
  BFS01::addEdge(6, 3, 0);
  BFS01::addEdge(3, 6, 1);
  BFS01::addEdge(5, 1, 0);
  BFS01::addEdge(1, 5, 1);
  BFS01::addEdge(4, 5, 0);
  BFS01::addEdge(5, 4, 1);
  BFS01::addEdge(6, 4, 0);
  BFS01::addEdge(4, 6, 1);
  
  auto d = BFS01::solve(0);
  assert(d[0] == 0);
  assert(d[1] == 0);
  assert(d[2] == 1);
  assert(d[6] == 2);
}

void test2(){// https://www.codechef.com/problems/REVERSE
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  BFS01::init(n);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b; a--; b--;
    BFS01::addEdge(a, b, 0);
    BFS01::addEdge(b, a, 1);
  }
  auto d = BFS01::solve(0);
  if(d[n-1] == INF)
    cout << -1 << endl;
  else
    cout << d[n-1] << endl;
}
int main() {
  test1();
  //test2();
  return 0; 
}
