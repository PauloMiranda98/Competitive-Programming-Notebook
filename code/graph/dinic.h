#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Dinic{
private:
  struct FlowEdge{
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
  };
  const ll flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;
  bool bfs(){
    while (!q.empty()){
      int v = q.front();
      q.pop();
      for (int id : adj[v]){
        if (edges[id].cap - edges[id].flow < 1)
          continue;
        if (level[edges[id].u] != -1)
          continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }
  ll dfs(int v, ll pushed){
    if (pushed == 0)
      return 0;
    if (v == t)
      return pushed;
    for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++){
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }
public:
  Dinic(int n) : n(n){
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  void addEdge(int v, int u, ll cap){
    edges.push_back(FlowEdge(v, u, cap));
    edges.push_back(FlowEdge(u, v, 0));
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }
  ll maxFlow(int s1, int t1){
    s = s1;
    t = t1;
    ll f = 0;
    while (true){
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (!bfs())
        break;
      fill(ptr.begin(), ptr.end(), 0);
      while (ll pushed = dfs(s, flow_inf))
        f += pushed;
    }
    return f;
  }
  typedef pair<int, int> pii;
  vector<pii> recoverCut(){
    fill(level.begin(), level.end(), 0);
    vector<pii> rc;
    q.push(s);
    level[s] = 1;
    while (!q.empty()){
      int v = q.front();
      q.pop();
      for (int id : adj[v]){
        if ((id & 1) == 1)
          continue;
        if (edges[id].cap == edges[id].flow){
          rc.push_back(pii(edges[id].v, edges[id].u));
        }else{
          if (level[edges[id].u] == 0){
            q.push(edges[id].u);
            level[edges[id].u] = 1;
          }
        }
      }
    }
    vector<pii> ans;
    for (pii p : rc)
      if ((level[p.first] == 0) or (level[p.second] == 0))
        ans.push_back(p);
    return ans;
  }
};