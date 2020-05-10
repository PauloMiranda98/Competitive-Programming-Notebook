#include "../../code/graph/centroid_decomposition.h"
vector<vector<int>> adj;
bool ok;
int verify(int u){
  int sz = 1;
  int mx = 0;
  for(int to: adj[u]){
    int aux = verify(to);
    mx = max(mx, aux);
    sz += aux;
  }
  ok = ok and (mx<=sz/2);
  return sz;
}
void test1(){
  CentroidDecomposition cd;
  int n = 1000;
  cd.init(n);
  srand(time(0));
  for (int i = 1; i < n; i++)
    cd.addEdge(i, rand()%i);
  adj = cd.build();  
  ok = true;
  verify(cd.centroidRoot);
  assert(ok);
}
int main(){
  for(int i=0; i<10; i++)
    test1();
  return 0;
}