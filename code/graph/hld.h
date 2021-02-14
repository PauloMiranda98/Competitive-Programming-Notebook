#include <bits/stdc++.h>
#include "../data_structures/bit_range.h"
using namespace std;
#define F first
template <typename T = long long>
class HLD{
private:
  vector<vector<pair<int, T>>> adj;
  vector<int> sz, h, dad, pos;
  vector<T> val, v;
  int t;
  bool edge;
  //Begin Internal Data Structure
  BitRange *bit;
  T neutral = 0;
  inline T join(T a, T b){
    return a+b;
  }
  inline void update(int a, int b, T x){
    bit->add(a+1, b+1, x);
  }
  inline T query(int a, int b){
    return bit->get(a+1, b+1);
  }
  //End Internal Data Structure
  void dfs(int u, int p = -1){
    sz[u] = 1;
    for(auto &viz: adj[u]){
      auto [to, w] = viz;
      if(to == p) continue;
      if(edge) val[to] = w;
      dfs(to, u);
      sz[u] += sz[to];
      if(sz[to] > sz[adj[u][0].F] or adj[u][0].F == p)
        swap(viz, adj[u][0]);
    }
  }
  void build_hld(int u, int p=-1){
    dad[u] = p;
    pos[u] = t++;
    v[pos[u]] = val[u];
    for(auto to: adj[u]) if(to.F != p){
      h[to.F] = (to == adj[u][0]) ? h[u] : to.F;
      build_hld(to.F, u);
    }
  }
  void build(int root, bool is_edge){
    assert(!adj.empty());
    edge = is_edge; 
    t = 0;
    h[root] = 0;
    dfs(root);
    build_hld(root);
    //Init Internal Data Structure
    for(int i=0; i<t; i++)
      update(i, i, v[i]);
  }
public:
  ~HLD(){ delete bit; }
  void init(int n){
    dad.resize(n); pos.resize(n); val.resize(n); v.resize(n);
    adj.resize(n); sz.resize(n); h.resize(n);
    bit = new BitRange(n);
  }
  void buildToEdge(int root=0){
    build(root, true);
  }
  void buildToVertex(vector<T> initVal, int root=0){
    assert(initVal.size() == val.size());
    val = initVal;
    build(root, false);
  }
  void addEdge(int a, int b, T w = 0){
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
  T query_path(int a, int b) {
    if (edge and a == b) return neutral;
    if (pos[a] < pos[b]) swap(a, b);
    if (h[a] == h[b]) return query(pos[b]+edge, pos[a]);
    return join(query(pos[h[a]], pos[a]), query_path(dad[h[a]], b));
  }
  void update_path(int a, int b, T x) {
    if (edge and a == b) return;
    if (pos[a] < pos[b]) swap(a, b);
    if (h[a] == h[b]) return (void)update(pos[b]+edge, pos[a], x);
    update(pos[h[a]], pos[a], x); update_path(dad[h[a]], b, x);
  }
  T query_subtree(int a) {
    if (edge and sz[a] == 1) return neutral;
    return query(pos[a]+edge, pos[a]+sz[a]-1);
  }
  void update_subtree(int a, T x) {
    if (edge and sz[a] == 1) return;
    update(pos[a] + edge, pos[a]+sz[a]-1, x);
  }
  int lca(int a, int b) {
    if (pos[a] < pos[b]) swap(a, b);
    return h[a] == h[b] ? b : lca(dad[h[a]], b);
  }
};