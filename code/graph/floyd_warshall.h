#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
namespace FloydWarshall{
  vector<vector<ll>> dist;
  int n;
  void init(int n1){
    n = n1;
    dist.assign(n, vector<ll>(n, INFLL));
    for(int i=0; i<n; i++)
      dist[i][i] = 0LL;
  }
  void addEdge(int a, int b, ll w){
    dist[a][b] = min(dist[a][b], w);
  }
  vector<vector<ll>> solve(){
    for(int k=0; k<n; k++){
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    return dist;
  }
};