#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
namespace GraphTheorem{
  // return if a sequence of integers d can be represented as the 
  // degree sequence of a finite simple graph on n vertices
  bool ErdosGallai(vector<int> d){
    int n = d.size();
    sort(all(d), greater<int>());
    ll sum1 = 0, sum2 = 0;
    int mn = n-1;
    for(int k=1; k<=n; k++){
      sum1 += d[k-1];
      while(k <= mn and k > d[mn])
        sum2 += d[mn--];
      if(mn + 1 < k)
        sum2 -= d[mn++];
      ll a = sum1, b = k*(ll)mn + sum2;
      if(a > b)
        return false;
    }
    return sum1%2 == 0;
  }
  vector<pii> recoverErdosGallai(vector<int> d){
    int n = d.size();
    priority_queue<pii> pq;
    for(int i=0; i<n; i++)
      pq.emplace(d[i], i);
    vector<pii> edges;
    while(!pq.empty()){
      auto [g, u] = pq.top();
      pq.pop();
      vector<pii> aux(g);
      for(int i=0; i<g; i++){
        if(pq.empty())
          return {};
        auto [g2, u2] = pq.top();
        pq.pop();
        if(g2 == 0)
          return {};
        edges.emplace_back(u, u2);
        aux[i] = pii(g2-1, u2);
      }
      for(auto [g2, u2]: aux)
        pq.emplace(g2, u2);
    }
    return edges;
  }  
};