#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
template<bool directed=false> struct EulerianPath{
  vector<vector<pii>> adj;
  vector<int> ans, pos;
  vector<bool> used;
  int n, m;
  EulerianPath(int n1){
    n = n1; m = 0;
    adj.assign(n, vector<pii>());
  }
  void addEdge(int a, int b) {
    int at = m++;
    adj[a].push_back({b, at});
    if (!directed) adj[b].push_back({a, at});
  }
  void dfs(int u){
    while(pos[u] < adj[u].size()){
      auto [to, id] = adj[u][pos[u]];
      pos[u]++;
      if(!used[id]){
        used[id] = true;
        dfs(to);
      }
    }
    ans.push_back(u);
  }
  // Lembrar de chamar para o src certo
  // Se for verificar se existe resposta lembre de analisar se toda componente > 1 do grafo está conectada
  vector<int> getPath(int src){
    pos.assign(n, 0);
    used.assign(m, false);
    ans.clear();
    dfs(src);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};