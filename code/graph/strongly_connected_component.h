#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
namespace SCC{
  vector<vector<int>> adj, revAdj;
  vector<bool> visited;
  vector<int> ts, component;
  void dfs1(int u){
    visited[u] = true;
    for(int to : adj[u]){
      if(!visited[to])
        dfs1(to);
    }
    ts.push_back(u);
  }
  void dfs2(int u, int c){
    component[u] = c;
    for(int to : revAdj[u]){
      if(component[to] == -1)
        dfs2(to, c);
    }
  }
  vector<int> scc(int n, vector<pii> &edges){
    adj.assign(n, vector<int>());
    revAdj.assign(n, vector<int>());
    visited.assign(n, false);
    component.assign(n, -1);
    for(auto [a, b] : edges){
      adj[a].push_back(b);
      revAdj[b].push_back(a);
    }
    ts.clear();
    for (int i = 0; i < n; i++){
      if (!visited[i])
        dfs1(i);
    }
    reverse(ts.begin(), ts.end());
    int comp = 0;
    for (int u : ts){
      if (component[u] == -1)
        dfs2(u, comp++);
    }
    return component;
  }
}