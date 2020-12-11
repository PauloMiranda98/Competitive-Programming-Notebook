#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
// Adaptado de: https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Grafos/blossom.cpp
// Edmond's Blossoms algorithm give a maximum matching in general graphs (non-bipartite)
// O(N^3)
namespace EdmondBlossoms{
vector<int> adj[MAXN];
int match[MAXN];
int n, pai[MAXN], base[MAXN], vis[MAXN];
queue<int> q;
void init(int n1){
  n = n1;
  for(int i=0; i<n; i++)
    adj[i].clear();
}
void addEdge(int a, int b){
  adj[a].push_back(b);
  adj[b].push_back(a);
}
void contract(int u, int v, bool first = 1) {
  static vector<bool> bloss;
  static int l;
  if (first) {
    bloss = vector<bool>(n, 0);
    vector<bool> teve(n, 0);
    int k = u; l = v;
    while (1) {
      teve[k = base[k]] = 1;
      if (match[k] == -1) break;
      k = pai[match[k]];
    }
    while (!teve[l = base[l]]) l = pai[match[l]];
  }
  while (base[u] != l) {
    bloss[base[u]] = bloss[base[match[u]]] = 1;
    pai[u] = v;
    v = match[u];
    u = pai[match[u]];
  }
  if (!first) return;
  contract(v, u, 0);
  for (int i = 0; i < n; i++) if (bloss[base[i]]) {
    base[i] = l;
    if (!vis[i]) q.push(i);
    vis[i] = 1;
  }
}
int getpath(int s) {
  for (int i = 0; i < n; i++) 
    base[i] = i, pai[i] = -1, vis[i] = 0;
  vis[s] = 1; q = queue<int>(); q.push(s);
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int i : adj[u]) {
      if (base[i] == base[u] or match[u] == i) continue;
      if (i == s or (match[i] != -1 and pai[match[i]] != -1))
        contract(u, i);
      else if (pai[i] == -1) {
        pai[i] = u;
        if (match[i] == -1) return i;
        i = match[i];
        vis[i] = 1; q.push(i);
      }
    }
  }
  return -1;
}
typedef pair<int, int> pii;
vector<pii> maximumMatching(){
  vector<pii> ans;
  memset(match, -1, sizeof(match));
  for (int i = 0; i < n; i++) if (match[i] == -1)
    for (int j : adj[i]) if (match[j] == -1) {
      match[i] = j;
      match[j] = i;
      break;
    }
  for (int i = 0; i < n; i++) if (match[i] == -1) {
    int j = getpath(i);
    if (j == -1) continue;
    while (j != -1) {
      int p = pai[j], pp = match[p];
      match[p] = j;
      match[j] = p;
      j = pp;
    }
  }
  for(int i=0; i < n; i++)
    if(i < match[i])
      ans.emplace_back(i, match[i]);
  return ans;
}
};