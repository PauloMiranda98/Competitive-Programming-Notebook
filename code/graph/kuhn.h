#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
namespace Kuhn{
  int na, nb;
  vector<vector<int>> adj;
  vector<int> vis, ma, mb;
  void init(int na1, int nb1){
    na = na1, nb = nb1;
    adj.assign(na, vector<int>());
    vis.assign(na + nb, 0);
    ma.assign(na, -1);
    mb.assign(nb, -1);
  }
  void addEdge(int a, int b) { 
    adj[a].push_back(b); 
  }
  bool dfs(int u) {
    vis[u] = 1;
    for (int to : adj[u]){
      if(vis[na+to]) 
        continue;
      vis[na+to] = 1;
      if (mb[to] == -1 or dfs(mb[to])) {
        ma[u] = to, mb[to] = u;
        return true;
      }
    }
    return false;
  }
  int matching() {
    int ans = 0, c = 1;
    for (auto& v: adj) 
      shuffle(v.begin(), v.end(), rng);
    while (c) {
      for (int j = 0; j < nb; j++) 
        vis[na+j] = 0;
      c = 0;
      for (int i = 0; i < na; i++)
        if (ma[i] == -1 and dfs(i))
          ans++, c = 1;
    }
    return ans;
  }
  pair<vector<int>, vector<int>> minimumVertexCover() {
    matching();
    for (int i = 0; i < na+nb; i++) 
      vis[i] = 0;
    for (int i = 0; i < na; i++) 
      if (ma[i] == -1) 
        dfs(i);
    vector<int> va, vb;
    for (int i = 0; i < na; i++) 
      if (!vis[i]) 
        va.push_back(i);
    for (int i = 0; i < nb; i++) 
      if (vis[na+i]) 
        vb.push_back(i);
    return {va, vb};
  }
  vector<int> maximumAntichain(){
    auto [l, r] = minimumVertexCover();
    set<int> L(l.begin(), l.end());
    set<int> R(r.begin(), r.end());
    vector<int> ans;
    for (int i = 0; i < na; i++)
      if (!L.count(i) and !R.count(i))
        ans.push_back(i);
    return ans;
  }
};