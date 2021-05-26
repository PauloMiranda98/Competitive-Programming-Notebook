#include "../../code/graph/strongly_connected_component.h"
typedef pair<int, int> pii;
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
  vector<int> comp = SCC::scc(8, edges);
  for (pii p : edges)
    assert(comp[p.first] != comp[p.second]);
}
void test2(){
  vector<pii> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(1, 2);
  edges.emplace_back(2, 3);
  edges.emplace_back(3, 4);
  edges.emplace_back(4, 2);
  edges.emplace_back(3, 5);
  edges.emplace_back(3, 6);
  vector<int> comp = SCC::scc(8, edges);
  vector<pii> equals = {pii(2, 3), pii(3, 4)};
  vector<pii> diff = {pii(0, 1), pii(1, 2), pii(0, 2), pii(3, 5), pii(3, 6), pii(5, 6)};
  for (pii p : equals)
    assert(comp[p.first] == comp[p.second]);
  for (pii p : diff)
    assert(comp[p.first] != comp[p.second]);
}

void test3(){
  assert(true); // AC: https://cses.fi/problemset/task/1682/
}

int main(){
  test1();
  test2();
  return 0;
}