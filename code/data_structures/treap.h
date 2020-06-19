#include <bits/stdc++.h>
using namespace std;
namespace Treap{
  const int N = 500010; 
  typedef long long treap_t;
  treap_t X[N];
  int en = 1, Y[N], sz[N], L[N], R[N], root;

  const treap_t neutral = 0;
  treap_t op_val[N];
  treap_t lazy[N];
  inline treap_t join(treap_t a, treap_t b, treap_t c){
    return a + b + c;
  }
  void calc(int u) { // update node given children info
    sz[u] = sz[L[u]] + 1 + sz[R[u]];
    // code here, no recursion
    op_val[u] = join(op_val[L[u]], X[u], op_val[R[u]]);
  }
  void unlaze(int u) {
    if(!u) return;
    // code here, no recursion
    if (lazy[u]){
      X[u] += lazy[u];
      if(L[u])
        lazy[L[u]] += lazy[u];
      if(R[u])
        lazy[R[u]] += lazy[u];			
      lazy[u] = 0;
    }
  }
  void split(int u, treap_t x, int &l, int &r) { // l gets <= x, r gets > x
    unlaze(u); if(!u) return (void) (l = r = 0);
    if(X[u] <= x) { split(R[u], x, l, r); R[u] = l; l = u; }
    else { split(L[u], x, l, r); L[u] = r; r = u; }
    calc(u);
  }
  int merge(int l, int r) { // els on l <= els on r
    unlaze(l); unlaze(r); 
    if(!l || !r) return l + r; 
    int u;
    if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
    else { L[r] = merge(l, L[r]); u = r; }
    calc(u); 
    return u;
  }
  int new_node(treap_t x){
    X[en] = x;
    op_val[en] = x;
    lazy[en] = 0;
    return en++;
  }
  int nth(int u, int idx){
    if(!u)
    return 0;
    if(idx <= sz[L[u]])
      return nth(L[u], idx);
    else if(idx == sz[L[u]] + 1)
      return u;
    else
      return nth(R[u], idx - sz[L[u]] - 1);
  }	
//Public
  void init(int n=N-1) { // call before using other funcs
    //init position 0
    sz[0] = 0;
    op_val[0] = neutral;
    //init Treap
    root = 0;
    for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
    random_shuffle(Y + 1, Y + n + 1);
  }
  void insert(treap_t x){
    int a, b;
    split(root, x, a, b);
    root = merge(merge(a, new_node(x)), b);
  }
  void erase(treap_t x){
    int a, b, c, d;
    split(root, x-1, a, b);
    split(b, x, c, d);
    root = merge(a, d);
  }
  int count(treap_t x){
    int a, b, c, d;
    split(root, x-1, a, b);
    split(b, x, c, d);
    int ans = sz[c];
    root = merge(a, merge(c, d));
    return ans;
  }
  int size(){ return sz[root];}
  treap_t nth(int idx){ //1-indexed
    int u = nth(root, idx);
    return X[u];
  }	
}; 
