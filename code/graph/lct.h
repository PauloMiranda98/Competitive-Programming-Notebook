#include <bits/stdc++.h>
using namespace std;
// Link-Cut Tree, directed version.
// All operations are O(log(n)) amortized. 
//Source: https://github.com/brunomaletta/Biblioteca/
const int MAXN = 200010;
namespace LCT {
  struct node {
    int p, ch[2];
    node() { p = ch[0] = ch[1] = -1; }
  };
  node t[MAXN];
  bool isRoot(int x) {
    return t[x].p == -1 or (t[t[x].p].ch[0] != x and t[t[x].p].ch[1] != x);
  }
  void rotate(int x) {
    int p = t[x].p, pp = t[p].p;
    if (!isRoot(p)) t[pp].ch[t[pp].ch[1] == p] = x;
    bool d = t[p].ch[0] == x;
    t[p].ch[!d] = t[x].ch[d], t[x].ch[d] = p;
    if (t[p].ch[!d]+1) t[t[p].ch[!d]].p = p;
    t[x].p = pp, t[p].p = x;
  }
  void splay(int x) {
    while (!isRoot(x)) {
      int p = t[x].p, pp = t[p].p;
      if (!isRoot(p)) 
        rotate((t[pp].ch[0] == p)^(t[p].ch[0] == x) ? x : p);
      rotate(x);
    }
  }
  int access(int v) {
    int last = -1;
    for (int w = v; w+1; last = w, splay(v), w = t[v].p)
      splay(w), t[w].ch[1] = (last == -1 ? -1 : v);
    return last;
  }
// Public:
  void init(int n){
    for(int i=0; i<=n; i++)
      t[i] = node();
  } 
  int findRoot(int v) {
    access(v);
    while (t[v].ch[0]+1) v = t[v].ch[0];
    return splay(v), v;
  }
  // V must be root. W will be the dad of V.
  void link(int v, int w) {
    access(v);
    t[v].p = w;
  }
  // Removes edge (v, dad[v])
  void cut(int v) { 
    access(v);
    if(t[v].ch[0] == -1)
      return;
    t[v].ch[0] = t[t[v].ch[0]].p = -1;
  }
  int lca(int v, int w) {
    if(findRoot(v) != findRoot(w))
      return -1;
    access(v);
    return access(w);
  }
}
