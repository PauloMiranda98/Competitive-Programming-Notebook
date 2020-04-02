#include "../../code/graph/topological_sort.h"
typedef pair<int, int> pii;
bool testTopologicalSort(int n, vector<pii> edges){
  vector<int> ts = TopologicalSort::order(n, edges);
  vector<int> time(n);
  for(int i=0; i<n; i++)
    time[ts[i]] = i;
  for(pii p: edges){
    if(time[p.first] > time[p.second])
      return false;
  }
  return true;
}
void test1(){
  vector<pii> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(0, 2);
  edges.emplace_back(1, 3);
  edges.emplace_back(2, 3);
  edges.emplace_back(3, 4);
  edges.emplace_back(3, 5);
  edges.emplace_back(3, 6);
  edges.emplace_back(6, 7);
  assert(testTopologicalSort(8, edges));
}
void test2(){
  vector<pii> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(1, 2);
  edges.emplace_back(1, 3);
  edges.emplace_back(2, 3);
  edges.emplace_back(3, 4);
  edges.emplace_back(3, 5);
  edges.emplace_back(3, 6);
  assert(testTopologicalSort(7, edges));
}
int main(){
  test1();
  test2();
  return 0;
}