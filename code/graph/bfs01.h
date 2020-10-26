#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 500010;
const int INF = 0x3f3f3f3f;
namespace BFS01{
  vector<pii> adj[N];
  int n;
  void init(int n1){
    n = n1;
    for(int i=0; i<n; i++) adj[i].clear();
  }
  //0-indexed
  void addEdge(int u, int to, int w){
    adj[u].emplace_back(to, w);
  }
  vector<int> solve(int s){
    vector<int> d(n, INF);
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop_front();
      for (auto edge : adj[u]) {
        int to = edge.first;
        int w = edge.second;
        if (d[u] + w < d[to]) {
          d[to] = d[u] + w;
          if (w == 1)
            q.push_back(to);
          else
            q.push_front(to);
        }
      }
    } 
    return d;
  }
};
