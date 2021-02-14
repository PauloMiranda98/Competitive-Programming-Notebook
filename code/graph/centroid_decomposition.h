#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// O(N*log(N))
// Centroid Decomposition
const int MAXN = 200010;
namespace CD{
  vector<int> adj[MAXN];
  int dad[MAXN], sub[MAXN];
  bool rem[MAXN];
  int centroidRoot, n;
  void init(int n1){
    n = n1;
    for(int i=0; i<n; i++){
      adj[i].clear();
      rem[i] = false;
    }
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
  void getChildren(int u, int p, int d, vector<int> &v){
    v.push_back(d);
    for(int to: adj[u]){
      if(rem[to] or to == p)
        continue;
      getChildren(to, u, d+1, v);
    }
  }
  ll ans = 0;
  int k;
  int decomp(int u, int p){
    int sz = dfs(u, p);
    int c = centroid(u, p, sz);
    if (p == -1)
      p = c;
    dad[c] = p;
    rem[c] = true;
    // Begin
    vector<int> f(sz+1, 0);
    f[0] = 1;
    for (auto to : adj[c]) if (!rem[to]){
      vector<int> v;
      getChildren(to, c, 1, v);
      for(int d: v){ // Query
        if(d <= k and k-d <= sz)
          ans += f[k-d];
      }
      for(int d: v) // Update
        f[d]++;
    }
    // End
    for (auto to : adj[c]){
      if (!rem[to])
        decomp(to, c);
    }
    return c;
  }
  void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  // Number of k-size paths: O(N * log(N))
  ll solve(int k1){
    assert(n > 0);
    ans = 0, k = k1;
    centroidRoot = decomp(0, -1);
    return ans;
  }
};