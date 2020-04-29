#include "dinic.h"
using namespace std;
template <typename flow_t>
struct MaxFlowEdgeDemands{
  Dinic<flow_t> mf;
  vector<flow_t> ind, outd;
  flow_t D;
  int n;
  MaxFlowEdgeDemands(int n) : n(n){
    D = 0;
    mf.init(n + 2);
    ind.assign(n, 0);
    outd.assign(n, 0);
  }
  void addEdge(int a, int b, flow_t cap, flow_t demands){
    mf.addEdge(a, b, cap - demands);
    D += demands;
    ind[b] += demands;
    outd[a] += demands;
  }
  bool solve(int s, int t){
    mf.addEdge(t, s, numeric_limits<flow_t>::max());
    for (int i = 0; i < n; i++){
      if (ind[i]) mf.addEdge(n, i, ind[i]);
      if (outd[i]) mf.addEdge(i, n + 1, outd[i]);
    }
    return mf.maxFlow(n, n + 1) == D;
  }
};