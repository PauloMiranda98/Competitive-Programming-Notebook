#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//This algorithm finds the Global Min-Cut in O(|V|^3)
namespace MinCut{
  const int MAXN = 510;
  bool exist[MAXN], in_a[MAXN];
  ll g[MAXN][MAXN], w[MAXN];
  vector<int> v[MAXN];
  int n;
  void init(int n1){
    n = n1;
    memset(g, 0, sizeof(g));
  }
  void addEdge(int a, int b, int w1){
    if(a == b) return;
    g[a][b] += w1;
    g[b][a] += w1;
  }
  pair<ll, vector<int>> mincut() {
    ll best_cost = 0x3f3f3f3f3f3f3f3fLL;
    vector<int> best_cut;
    for (int i=0; i<n; ++i)
      v[i].assign (1, i);
    memset (exist, true, sizeof(exist));
    for(int ph=0; ph<n-1; ++ph) {
      memset (in_a, false, sizeof in_a);
      memset (w, 0, sizeof w);
      for(int it=0, prev=0; it<n-ph; ++it){
        int sel = -1;
        for(int i=0; i<n; ++i)
          if(exist[i] && !in_a[i] && (sel == -1 || w[i] > w[sel]))
            sel = i;
        if(it == n-ph-1){
          if(w[sel] < best_cost)
            best_cost = w[sel],  best_cut = v[sel];
          v[prev].insert (v[prev].end(), v[sel].begin(), v[sel].end());
          for(int i=0; i<n; ++i)
            g[prev][i] = g[i][prev] += g[sel][i];
          exist[sel] = false;
        }else{
          in_a[sel] = true;
          for(int i=0; i<n; ++i)
            w[i] += g[sel][i];
          prev = sel;
        }
      }
    }
    return {best_cost, best_cut};
  }  
};