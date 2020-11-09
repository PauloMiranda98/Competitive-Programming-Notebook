#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 500010;
namespace Prim{
  vector<pii> adj[MAXN];
  int weight[MAXN];
  bool seen[MAXN];
  int n;
  void init(int n1){
    n = n1;
    for(int i=0; i<n; i++) adj[i].clear();
  }
  void addEdge(int a, int b, int w){
    adj[a].emplace_back(w, b);
    adj[b].emplace_back(w, a);
  }
  ll solve(){
    for(int i=0; i<n; i++){
      weight[i] = 0x3f3f3f3f;
      seen[i] = 0;
    }
    weight[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > st;
    st.push(pii(weight[0], 0));
    ll ans = 0;
    while(!st.empty()){
      int u = st.top().second;
      st.pop();
      if(seen[u])
        continue;
      seen[u] = true;
      ans += weight[u];
      for(auto [edge, to]: adj[u]){
        if(!seen[to] and (edge < weight[to])){
          weight[to] = edge;
          st.emplace(weight[to], to);
        }
      }
    }
    return ans;
  }
};