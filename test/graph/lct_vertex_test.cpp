#include "../../code/graph/lct_vertex.h"
void test1(){ // AC: https://judge.yosupo.jp/submission/34750
  int n, q;
  cin >> n >> q;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    lct::makeTree(i, x);
  }
  for(int i=0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    lct::link(a, b);
  }
  while(q--){
    int op;
    cin >> op;
    if(op == 0){
      int u, v, w, x;
      cin >> u >> v >> w >> x;
      lct::cut(u, v);
      lct::link(w, x);
    }else if(op == 1){
      int p, x;
      cin >> p >> x;
      lct::update(p, p, x);
    }else{
      int u, v;
      cin >> u >> v;
      cout << lct::query(u, v) << endl;
    }
  }
}
int main() {
  //test1();
  return 0;
}
