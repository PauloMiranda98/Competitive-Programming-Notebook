#include <bits/stdc++.h>
using namespace std;
namespace TopologicalSort{
  typedef pair<int, int> pii;
  vector<vector<int>> adj;
  vector<bool> visited;
  vector<int> vAns;
  void dfs(int u){
    visited[u] = true;
    for (int to : adj[u]){
      if (!visited[to])
        dfs(to);
    }
    vAns.push_back(u);
  }
  vector<int> order(int n, vector<pii> &edges){
    adj.assign(n, vector<int>());
    for (pii p : edges)
      adj[p.first].push_back(p.second);
    visited.assign(n, false);
    vAns.clear();
    for (int i = 0; i < n; i++){
      if (!visited[i])
        dfs(i);
    }
    reverse(vAns.begin(), vAns.end());
    return vAns;
  }
}; // namespace TopologicalSort