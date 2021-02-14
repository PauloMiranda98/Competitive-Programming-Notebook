#include "../../code/graph/hld.h"

void testVertice(){
  int n = 6;
  HLD hld;
  hld.init(n);
  hld.addEdge(0, 1);
  hld.addEdge(0, 2);
  hld.addEdge(2, 5);
  hld.addEdge(1, 3);
  hld.addEdge(1, 4);

  vector<long long> v(n);
  for(int i=0; i<n; i++)
    v[i] = i;
  hld.buildToVertex(v, 0);
  //LCA
  assert(hld.lca(3, 5) == 0);
  assert(hld.lca(3, 4) == 1);
  //Query Path
  assert(hld.query_path(3, 5) == 11);
  assert(hld.query_path(3, 4) == 8);
  //Query Sub Tree
  assert(hld.query_subtree(1) == 8);
  assert(hld.query_subtree(2) == 7);
  //Update Path
  hld.update_path(1, 2, 2);
  assert(hld.query_path(3, 5) == 17);
  hld.update_path(4, 3, -1);
  assert(hld.query_path(3, 4) == 7);
  hld.update_path(1, 2, -2);
  hld.update_path(4, 3, +1);
  //Update Sub Tree
  hld.update_subtree(1, +2);
  assert(hld.query_subtree(1) == 14);
  hld.update_subtree(2, -1);
  assert(hld.query_subtree(2) == 5);
  hld.update_subtree(1, -2);
  hld.update_subtree(2, +1);
}

void testEdge(){
  int n = 6;
  HLD hld;
  hld.init(n);
  hld.addEdge(0, 1, 1);
  hld.addEdge(0, 2, 2);
  hld.addEdge(2, 5, 5);
  hld.addEdge(1, 3, 3);
  hld.addEdge(1, 4, 4);

  hld.buildToEdge(0);
  //LCA
  assert(hld.lca(3, 5) == 0);
  assert(hld.lca(3, 4) == 1);
  //Query Path
  assert(hld.query_path(3, 5) == 11);
  assert(hld.query_path(3, 4) == 7);
  //Query Sub Tree
  assert(hld.query_subtree(1) == 7);
  assert(hld.query_subtree(2) == 5);
  //Update Path
  hld.update_path(1, 2, 2);
  assert(hld.query_path(3, 5) == 15);
  hld.update_path(4, 3, -1);
  assert(hld.query_path(3, 4) == 5);
  hld.update_path(1, 2, -2);
  hld.update_path(4, 3, +1);
  //Update Sub Tree
  hld.update_subtree(1, +2);
  assert(hld.query_subtree(1) == 11);
  hld.update_subtree(2, -1);
  assert(hld.query_subtree(2) == 4);
  hld.update_subtree(1, -2);
  hld.update_subtree(2, +1);
}

int main(){
  testVertice();
  testEdge();
  return 0;
}