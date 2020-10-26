#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
typedef pair<int, int> pii;
namespace Bridge{
  vector<int> adj[MAXN];
  vector<bool> visited;
  vector<int> tin, low;
  int timer, n;
  vector<pii> bridges;
  void init(int n1){
    n = n1;
    for(int i=0; i<n; i++) adj[i].clear();
  }
  void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  void dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for (int to : adj[u]) {
      if (to == p) continue;
      if (visited[to]) {
        low[u] = min(low[u], tin[to]);
      } else {
        dfs(to, u);
        low[u] = min(low[u], low[to]);
        if (low[to] > tin[u])
          bridges.push_back({u, to});
      }
    }
  }
  vector<pii> findBridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    bridges.clear();
    for (int i = 0; i < n; i++) {
      if (!visited[i])
        dfs(i);
    }
    return bridges;
  }
};