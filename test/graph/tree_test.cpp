#include "../../code/graph/tree.h"
Tree<int> tree;

void testDist(){
  tree.init(5);
  
  tree.addEdge(0, 1);
  tree.addEdge(0, 2);
  tree.addEdge(2, 3);
  tree.addEdge(2, 4);
  
  tree.build();
  assert(tree.dist(0, 2) == 1);
  assert(tree.dist(1, 4) == 3);
  assert(tree.dist(0, 3) == 2);

  assert(true); // AC: https://cses.fi/problemset/task/1135
}

void testLca(){
  tree.init(5);
  
  tree.addEdge(0, 1);
  tree.addEdge(0, 2);
  tree.addEdge(2, 3);
  tree.addEdge(2, 4);
  
  tree.build(0);
  assert(tree.dist(0, 1) == 0);
  assert(tree.dist(0, 4) == 0);
  assert(tree.dist(1, 2) == 0);
  assert(tree.dist(2, 3) == 2);
  assert(tree.dist(3, 4) == 2);
  
  assert(true); // AC: https://judge.yosupo.jp/problem/lca 
}

int main(){
  testDist();
  
  return 0;
}
