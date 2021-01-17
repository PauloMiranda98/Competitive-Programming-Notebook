#include <bits/stdc++.h>
using namespace std;
namespace ITreap{
  const int N = 500010;
  typedef long long treap_t;
  treap_t X[N];
  int en = 1, Y[N], sz[N], L[N], R[N], P[N], root;
  const treap_t neutral = 0;
  treap_t op_val[N];
  bool rev[N];
  inline treap_t join(treap_t a, treap_t b, treap_t c){
    return a + b + c;
  }
  void calc(int u) { // update node given children info
    if(L[u]) P[L[u]] = u;
    if(R[u]) P[R[u]] = u;
    sz[u] = sz[L[u]] + 1 + sz[R[u]];
    // code here, no recursion
    op_val[u] = join(op_val[L[u]], X[u], op_val[R[u]]);
  }
  void unlaze(int u) {
    if(!u) return;
    // code here, no recursion
    if (rev[u]){
      if(L[u]) rev[L[u]] ^= rev[u];
      if(R[u]) rev[R[u]] ^= rev[u];
      swap(L[u], R[u]);
      rev[u] = false;
    }
  }
  void split(int u, int s, int &l, int &r) { // l gets first s, r gets remaining
    unlaze(u); 
    if(!u) return (void) (l = r = 0);
    if(sz[L[u]] < s) { split(R[u], s - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
    else { split(L[u], s, l, r); L[u] = r; r = u; }
    P[u] = 0;
    calc(u);
  }
  int merge(int l, int r) { // els on l <= els on r
    unlaze(l); unlaze(r); 
    if(!l || !r) return l + r; 
    int u;
    if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l;}
    else { L[r] = merge(l, L[r]); u = r;}
    P[u] = 0;
    calc(u); 
    return u;
  }
  int new_node(treap_t x){
    P[en] = 0;
    X[en] = x;
    op_val[en] = x;
    rev[en] = false;
    return en++;
  }
  int nth(int u, int idx){
    if(!u)
      return 0;
    unlaze(u); 
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
    std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
    for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
    shuffle(Y + 1, Y + n + 1, rng);
  }
  //0-indexed
  int insert(int idx, int val){ 
    int a, b;
    split(root, idx, a, b);
    int node = new_node(val);
    root = merge(merge(a, node), b);
    return node;
  }
  //0-indexed
  void erase(int idx){ 
    int a, b, c, d;
    split(root, idx, a, b);
    split(b, 1, c, d);
    root = merge(a, d);
  }
  //0-indexed
  treap_t nth(int idx){
    int u = nth(root, idx+1);
    return X[u];
  } 
  //0-indexed [l, r]
  treap_t query(int l, int r){
    if(l > r) swap(l, r);
    int a, b, c, d;
    split(root, l, a, d);
    split(d, r - l + 1, b, c);
    treap_t ans = op_val[b];
    root = merge(a, merge(b, c));
    return ans;
  }
  //0-indexed [l, r]
  void reverse(int l, int r){
    if (l > r) swap(l, r);
    int a, b, c, d;
    split(root, l, a, d);
    split(d, r - l + 1, b, c);
    if(b)
      rev[b] ^= 1;
    root = merge(a, merge(b, c));
  }
  int getRoot(int x){
    while(P[x]) x = P[x];
    return x;
  }
  int getPos(int node){
    int ans = sz[L[node]];
    while(P[node]){
      if(L[P[node]] == node){
        node = P[node];
      }else{
        node = P[node];
        ans += sz[L[node]] + 1;
      }
    }
    return ans;
  }
};
