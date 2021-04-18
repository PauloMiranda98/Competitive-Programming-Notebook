#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;
//Articulation Point
namespace AP{
  vector<int> adj[MAXN];
  vector<bool> visited, isAP;
  vector<int> tin, low;
  int timer, n;
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
    int children=0;
    for (int to : adj[u]) {
      if (to == p) continue;
      if (visited[to]) {
        low[u] = min(low[u], tin[to]);
      } else {
        dfs(to, u);
        low[u] = min(low[u], low[to]);
        if (low[to] >= tin[u] && p!=-1)
          isAP[u] = true;
        ++children;
      }
    }
    if(p == -1 && children > 1)
      isAP[u] = true;
  }
  vector<bool> findArticulationPoint() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    isAP.assign(n, false);
    for (int i = 0; i < n; i++) {
      if (!visited[i])
        dfs(i);
    }
    return isAP;
  }
};
