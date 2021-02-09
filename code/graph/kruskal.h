#include "../data_structures/union_find.h"
typedef long long ll;
struct Edge{
  int u, v; ll w;	
  Edge(){}
  Edge(int u1, int v1, ll w1):u(u1), v(v1), w(w1){}
};
ll kruskal(vector<Edge> v, int nVet){
  ll cost = 0;
  UnionFind uf(nVet);	
  sort(v.begin(), v.end(), [&](Edge a, Edge b){
    return a.w < b.w;
  });	
  for(Edge &e: v){
    if(!uf.isSame(e.u, e.v)){ 
      cost += e.w;
      uf.join(e.u, e.v);
    }
  }	
  return cost;
}