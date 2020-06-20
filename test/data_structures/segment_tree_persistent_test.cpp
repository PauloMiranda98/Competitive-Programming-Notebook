#include "../../code/data_structures/segment_tree_persistent.h"

void testPersistentSegtree(){
  int v[] = {0, 0, 0, 0, 0, 0};
  int n = 6;
  PerSegTree::build(n, v);
  assert(PerSegTree::query(0, 5, 0) == 0);

  PerSegTree::update(1, 2);  
  assert(PerSegTree::query(0, 5, 0) == 0);
  assert(PerSegTree::query(0, 5, 1) == 2);
  assert(PerSegTree::query(1, 1, 1) == 2);

  PerSegTree::update(3, -2);  
  assert(PerSegTree::query(0, 5, 0) == 0);
  assert(PerSegTree::query(0, 5, 1) == 2);
  assert(PerSegTree::query(0, 5, 2) == 0);
  assert(PerSegTree::query(1, 1, 1) == 2);
  assert(PerSegTree::query(1, 1, 2) == 2);
  assert(PerSegTree::query(3, 3, 2) == -2);

  PerSegTree::update(3, 1);  
  assert(PerSegTree::query(0, 5, 0) == 0);
  assert(PerSegTree::query(0, 5, 1) == 2);
  assert(PerSegTree::query(0, 5, 2) == 0);
  assert(PerSegTree::query(0, 5, 3) == 3);
  assert(PerSegTree::query(1, 1, 1) == 2);
  assert(PerSegTree::query(1, 1, 2) == 2);
  assert(PerSegTree::query(3, 3, 2) == -2);
  assert(PerSegTree::query(3, 3, 3) == 1);
}
int main(){
  testPersistentSegtree();
  return 0;
}
