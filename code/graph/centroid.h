#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
typedef pair<int, int> pii;
namespace Centroid{
  vector<int> adj[MAXN];
  int sub[MAXN];
  int n;
  void init(int n1){
    n = n1;
    for(int i=0; i<n; i++) adj[i].clear();
  }
  void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int dfsS(int u, int p){
    sub[u] = 1;
    for(int to: adj[u]){
      if(to != p)
        sub[u] += dfsS(to, u);
    }
    return sub[u];
  }
  pii dfsC(int u, int p){
    for(int to : adj[u]){
      if(to != p and sub[to] > n/2)
        return dfsC(to, u);
    }
    for(int to : adj[u]){
      if(to != p and (sub[to]*2) == n)
        return pii(u, to);
    } 
    return pii(u, u);
  }
  pii findCentroid(){
    dfsS(0, -1);
    return dfsC(0, -1);
  }
}
