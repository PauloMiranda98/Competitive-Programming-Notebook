#include <bits/stdc++.h>
using namespace std;
//O((V^2)*E): for generic graph.
//O(sqrt(V)*E): on unit networks. A unit network is a network in which all the edges have unit capacity, and for any vertex except s and t either incoming or outgoing edge is unique. That's exactly the case with the network we build to solve the maximum matching problem with flows.
template <typename flow_t>
struct Dinic{
  struct FlowEdge{
    int from, to, id;
    flow_t cap, flow = 0;
    FlowEdge(int f, int t, flow_t c, int id1) : from(f), to(t), cap(c){
      id = id1;
    }
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
      int u = q.front();
      q.pop();
      for (int id : adj[u]){
        if (edges[id].cap - edges[id].flow < 1)
          continue;
        if (level[edges[id].to] != -1)
          continue;
        level[edges[id].to] = level[u] + 1;
        q.push(edges[id].to);
      }
    }
    return level[t] != -1;
  }
  flow_t dfs(int u, flow_t pushed){
    if (pushed == 0)
      return 0;
    if (u == t)
      return pushed;
    for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++){
      int id = adj[u][cid];
      int to = edges[id].to;
      if (level[u] + 1 != level[to] || edges[id].cap - edges[id].flow < 1)
        continue;
      flow_t tr = dfs(to, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }
//Public:
  Dinic(){}
  void init(int _n){
    n = _n;  
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  void addEdge(int from, int to, flow_t cap, int id=0){
    assert(n>0);
    edges.emplace_back(from, to, cap, id);
    edges.emplace_back(to, from, 0, -id);
    adj[from].push_back(m);
    adj[to].push_back(m + 1);
    m += 2;
  }
  flow_t maxFlow(int s1, int t1){
    s = s1, t = t1;
    flow_t f = 0;
    //Reset Flow
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
// Returns the minimum cut edge IDs 
vector<int> recoverCut(Dinic<int> &d){
  vector<int> seen(d.n, 0);
  queue<int> q;
  q.push(d.s);
  seen[d.s] = 1;
  while (!q.empty()){
    int u = q.front(); 
    q.pop();
    for (int idx : d.adj[u]){
      if (d.edges[idx].cap == d.edges[idx].flow)
        continue;
      if (!seen[d.edges[idx].to]){
        q.push(d.edges[idx].to);
        seen[d.edges[idx].to] = 1;
      }
    }
  }
  vector<int> ans;
  for(auto e: d.edges){
    if((e.cap == e.flow) and (seen[e.from] != seen[e.to]) and e.id >= 0)
      ans.push_back(e.id);
  }
  return ans;
}

