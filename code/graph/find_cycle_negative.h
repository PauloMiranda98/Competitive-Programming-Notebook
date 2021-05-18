#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> Edge;
vector<int> findNegativeCycle(vector<Edge> edges, int n){
  vector<ll> d(n, 0);
  vector<int> p(n, -1);
  int last = -1;
  for(int i = 0; i < n; ++i){
    last = -1;
    for(auto [u, to, w] : edges){
      if(d[u] + w < d[to]){
        d[to] = d[u] + w;
        p[to] = u;
        last = to;
      }
    }
  }
  if(last == -1){
    return {};
  }else{
    for(int i = 0; i < n; i++)
      last = p[last];
    vector<int> cycle;
    for(int v = last; ; v = p[v]){
      cycle.push_back(v);
      if(v == last && cycle.size() > 1)
        break;
    }
    reverse(cycle.begin(), cycle.end());
    return cycle;
  }
}
