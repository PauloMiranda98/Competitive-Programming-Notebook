#include <bits/stdc++.h>
using namespace std;
namespace Dijkstra{
  typedef long long T;
  typedef pair<T, int> pti;
  vector<vector<pti>> adj;
  int n;
  void init(int n1){
    n = n1;
    adj.assign(n, vector<pti>());
  }
  void addEdge(int from, int to, T w){
    adj[from].emplace_back(w, to);
  }
  vector<T> solve(int s){  
    vector<T> dist(n, numeric_limits<T>::max());
    dist[s] = 0;
    priority_queue<pti, vector<pti>, greater<pti>> st;
    st.emplace(dist[s], s); 
    while(!st.empty()){
      auto [wu, u] = st.top();
      st.pop();
      if(wu > dist[u]) continue;
      for(auto [w, to]: adj[u]){
        if(dist[u] + w < dist[to]){
          dist[to] = dist[u] + w;
          st.emplace(dist[to], to);
        }
      }
    }
    return dist;
  }
};
