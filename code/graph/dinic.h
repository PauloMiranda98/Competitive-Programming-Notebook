#include <bits/stdc++.h>
using namespace std;
template <typename flow_t>
struct Dinic{
  struct FlowEdge{
    int v, u;
    flow_t cap, flow = 0;
    FlowEdge(int v, int u, flow_t cap) : v(v), u(u), cap(cap) {}
  };
  const flow_t flow_inf = numeric_limits<flow_t>::max();
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
  flow_t dfs(int v, flow_t pushed){
    if (pushed == 0)
      return 0;
    if (v == t)
      return pushed;
    for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++){
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      flow_t tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }
  Dinic(){}
  void init(int _n){
    n = _n;  
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  void addEdge(int v, int u, flow_t cap){
    assert(n>0);
    edges.push_back(FlowEdge(v, u, cap));
    edges.push_back(FlowEdge(u, v, 0));
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }
  flow_t maxFlow(int s1, int t1){
    s = s1, t = t1;
    flow_t f = 0;
    for(int i=0; i<m; i++)
      edges[i].flow = 0;
    while (true){
      level.assign(n, -1);
      level[s] = 0;
      q.push(s);
      if (!bfs())
        break;
      ptr.assign(n, 0);
      while (flow_t pushed = dfs(s, flow_inf))
        f += pushed;
    }
    return f;
  }
};
typedef pair<int, int> pii;
vector<pii> recoverCut(Dinic<int> &d){
  vector<int> level(d.n, 0);
  vector<pii> rc;
  queue<int> q;
  q.push(d.s);
  level[d.s] = 1;
  while (!q.empty()){
    int v = q.front();
    q.pop();
    for (int id : d.adj[v]){
      if ((id & 1) == 1)
        continue;
      if (d.edges[id].cap == d.edges[id].flow){
        rc.push_back(pii(d.edges[id].v, d.edges[id].u));
      }else{
        if (level[d.edges[id].u] == 0){
          q.push(d.edges[id].u);
          level[d.edges[id].u] = 1;
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
