#include "topological_sort.h"
using namespace std;
namespace SCC{
  typedef pair<int, int> pii;
  vector<vector<int>> revAdj;
  vector<int> component;
  void dfs(int u, int c){
    component[u] = c;
    for (int to : revAdj[u]){
      if (component[to] == -1)
        dfs(to, c);
    }
  }
  vector<int> scc(int n, vector<pii> &edges){
    revAdj.assign(n, vector<int>());
    for (pii p : edges)
      revAdj[p.second].push_back(p.first);
    vector<int> tp = TopologicalSort::order(n, edges);
    component.assign(n, -1);
    int comp = 0;
    for (int u : tp){
      if (component[u] == -1)
        dfs(u, comp++);
    }
    return component;
  }
} // namespace SCC
