#include "../../code/graph/vertex_cover_in_tree.h"

void test1(){
  int n = 5;
  for(int i=0; i<n; i++){
    adj[i].clear();
    dp[i][0] = dp[i][1] = -1;
  }
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[0].push_back(2);
  adj[2].push_back(0);
  adj[0].push_back(3);
  adj[3].push_back(0);
  adj[0].push_back(4);
  adj[4].push_back(0);
  assert(vertexCover(0) == 1);
}
void test2(){
  int n = 5;
  for(int i=0; i<n; i++){
    adj[i].clear();
    dp[i][0] = dp[i][1] = -1;
  }
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[0].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  adj[3].push_back(2);
  adj[2].push_back(4);
  adj[4].push_back(2);
  assert(vertexCover(0) == 2);
}

int main() {
  test1();
  test2();
  return 0;
}
