#include <bits/stdc++.h>
using namespace std;
// O(N*log(N))
struct CentroidDecomposition{
  vector<vector<int>> adj;
  vector<int> dad, sub;
  vector<bool> rem;
  int centroidRoot, n;
  void init(int _n){
    n = _n;
    adj.resize(n);
    dad.resize(n);
    sub.resize(n);
    rem.assign(n, false);
  }
  // Return Centroid Decomposition Tree
  vector<vector<int>> build(){
    assert(n > 0);
    centroidRoot = decomp(0, -1);
    vector<vector<int>> ret(n);
    for (int u = 0; u < n; u++){
      if (dad[u] != u)
        ret[dad[u]].push_back(u);
    }
    return ret;
  }
  void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int decomp(int u, int p){
    int sz = dfs(u, p);
    int c = centroid(u, p, sz);
    if (p == -1)
      p = c;
    dad[c] = p;
    rem[c] = true;
    for (auto to : adj[c]){
      if (!rem[to])
        decomp(to, c);
    }
    return c;
  }
  int dfs(int u, int p){
    sub[u] = 1;
    for (int to : adj[u]){
      if (!rem[to] and to != p)
        sub[u] += dfs(to, u);
    }
    return sub[u];
  }
  int centroid(int u, int p, int sz){
    for (auto to : adj[u])
      if (!rem[to] and to != p and sub[to] > sz / 2)
        return centroid(to, u, sz);
    return u;
  }
  int operator[](int i){
    return dad[i];
  }
};