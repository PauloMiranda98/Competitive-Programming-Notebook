#include "../../code/geometry/circles_to_tree.h"

void testCirclesToTree(){
  vector<Circle> vc;
  vc.emplace_back(0, 0, 100, 0);
  vc.emplace_back(0, 50, 20, 1);
  vc.emplace_back(0, -50, 20, 2);
  vc.emplace_back(0, 0, 80, 3);
  vc.emplace_back(0, 0, 2, 4);
  vc.emplace_back(0, 50, 25, 5);
  int n = 6;
  auto adj = CirclesToTree::solve(vc);  
  vector<vector<int>> adj2(n, vector<int>());
  adj2[0].push_back(3);
  adj2[3].push_back(2);
  adj2[3].push_back(4);
  adj2[3].push_back(5);
  adj2[5].push_back(1);
  for(int i=0; i<n; i++)
    sort(adj[i].begin(), adj[i].end());
  assert(adj == adj2);
}

int main(){
  testCirclesToTree();
  return 0;
}