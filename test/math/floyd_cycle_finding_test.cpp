#include "../../code/math/floyd_cycle_finding.h"
const int MAXN = 10010;
int g[MAXN], tmp[MAXN];
int f(int x){
  return g[x];
}
void test(){
  int T=5;
  srand(2020);
  while(T--){
    for(int i=0; i<MAXN; i++){
      g[i] = rand()%MAXN;
      tmp[i] = -1;
    }
    pii ans = floydCycleFinding(0);
    int t=0, x = 0;
    while(tmp[x] == -1){
      tmp[x] = t++;
      x = f(x);
    }
    assert(ans == pii(tmp[x], t-tmp[x]));
  }
}
int main() {
  test();
  return 0;
}

