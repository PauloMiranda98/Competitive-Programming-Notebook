#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MAXL = 20;
namespace LCA{
  typedef int lca_t;
  typedef pair<int, lca_t> lca_p;
  const lca_t neutral = 0;
  vector<lca_p> adj[MAXN];
  int level[MAXN], P[MAXN][MAXL];
  lca_t D[MAXN][MAXL];
  int n;
  void init(int n1){
    n = n1;
    for(int i=0; i<n; i++)
      adj[i].clear();
  }
  inline lca_t join(lca_t a, lca_t b){
    return a + b;
  }
  void addEdge(int a, int b, lca_t w = 1){
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
  void dfs(int u){
    for (auto to : adj[u]){
      int v = to.first;
      lca_t w = to.second;
      if (v == P[u][0])
        continue;
      P[v][0] = u;
      D[v][0] = w;
      level[v] = level[u] + 1;
      dfs(v);
    }
  }
  void build(int root = 0){
    level[root] = 0;
    P[root][0] = root;
    D[root][0] = neutral;
    dfs(root);
    for (int j = 1; j < MAXL; j++)
      for (int i = 0; i < n; i++){
        P[i][j] = P[P[i][j - 1]][j - 1];
        D[i][j] = join(D[P[i][j - 1]][j - 1], D[i][j - 1]);
      }
  }
  lca_p lca(int u, int v){
    if (level[u] > level[v])
      swap(u, v);
    int d = level[v] - level[u];
    lca_t ans = neutral;
    for (int i = 0; i < MAXL; i++){
      if (d & (1 << i)){
        ans = join(ans, D[v][i]);
        v = P[v][i];
      }
    }
    if (u == v)
      return lca_p(u, ans);
    for (int i = MAXL - 1; i >= 0; i--){
      while (P[u][i] != P[v][i]){
        ans = join(ans, D[v][i]);
        ans = join(ans, D[u][i]);
        u = P[u][i];
        v = P[v][i];
      }
    }
    ans = join(ans, D[v][0]);
    ans = join(ans, D[u][0]);
    return lca_p(P[u][0], ans);
  }
};