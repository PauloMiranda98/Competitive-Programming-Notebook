#include <bits/stdc++.h>
using namespace std;
namespace LCA{
  typedef long long lca_t;
  typedef pair<int, lca_t> lca_p;
  const lca_t neutral = 0;
  vector<vector<lca_p>> adj;
  vector<int> level;
  vector<vector<lca_t>> D;
  vector<vector<int>> P;
  int n, mxLogN;
  void init(int _n, int _mxLogN = 20){
    n = _n;
    mxLogN = _mxLogN;
    adj.assign(n, vector<lca_p>());
    D.resize(n, vector<lca_t>(mxLogN));
    level.resize(n);
  }
  lca_t join(lca_t a, lca_t b){
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
    P.assign(n, vector<int>(mxLogN, -1));
    level[root] = 0;
    P[root][0] = root;
    D[root][0] = neutral;
    dfs(root);
    for (int j = 1; j < mxLogN; j++)
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
    for (int i = 0; i < mxLogN; i++){
      if (d & (1 << i)){
        ans = join(ans, D[v][i]);
        v = P[v][i];
      }
    }
    if (u == v)
      return lca_p(u, ans);
    for (int i = mxLogN - 1; i >= 0; i--){
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
