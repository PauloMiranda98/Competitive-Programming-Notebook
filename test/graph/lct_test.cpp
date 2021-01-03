#include "../../code/graph/lct.h"

int dad[10010];
void init(int n){
  for(int i=0; i<n; i++)
    dad[i] = -1;
}
int lca(int a, int b){
  vector<int> v1(1, -1), v2(1, -2);
  while(dad[a] != -1){
    v1.push_back(a);
    a = dad[a];
  }
  v1.push_back(a);
  while(dad[b] != -1){
    v2.push_back(b);
    b = dad[b];
  }
  v2.push_back(b);
  reverse(v1.begin(), v1.end());
  reverse(v2.begin(), v2.end());
  int last = -1;
  for(int i=0; ;i++){
    if(v1[i] == v2[i])
      last = v1[i];
    else
      break;
  }
  
  return last;
}
int findRoot(int x){
  if(dad[x] == -1)
    return x;
  return findRoot(dad[x]);
}
void test(){
  srand(2020);
  int n=10000, q = 10010;

  LCT::init(n);
  init(n);
  while(q--){
    int op = rand()%4;
    if(op == 0){
      int x = rand()%n;
      assert(LCT::findRoot(x) == findRoot(x));
    }else if(op == 1){
      int x = LCT::findRoot(rand()%n), y = rand()%n;
      if(LCT::findRoot(y) == x)
        continue;
      LCT::link(x, y);
      dad[x] = y;
    }else if(op == 2){
      int x = rand()%n;
      dad[x] = -1;
      LCT::cut(x);
    }else{
      int x = rand()%n, y = rand()%n;
      assert(LCT::lca(x, y) == lca(x, y));
    }
  }
}
int main() {
  test();
  return 0;
}
