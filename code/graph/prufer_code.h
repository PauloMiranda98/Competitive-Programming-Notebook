#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
// O(N), 0-index
vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
  int n = code.size() + 2;
  vector<int> degree(n, 1);
  for (int i : code)
    degree[i]++;
  int ptr = 0;
  while (degree[ptr] != 1)
    ptr++;
  int leaf = ptr;
  vector<pair<int, int>> edges;
  for (int v : code) {
    edges.emplace_back(leaf, v);
    if (--degree[v] == 1 && v < ptr) {
      leaf = v;
    } else {
      ptr++;
      while (degree[ptr] != 1)
        ptr++;
      leaf = ptr;
    }
  }
  edges.emplace_back(leaf, n-1);
  return edges;
}
vector<vector<int>> adj;
vector<int> parent;
void dfs(int v) {
  for (int u : adj[v]) {
    if (u != parent[v]) {
      parent[u] = v;
      dfs(u);
    }
  }
}
// O(N), 0-index
vector<int> pruefer_code(vector<pii> edges) {
  int n = edges.size() + 1;
  adj.assign(n, {});
  parent.assign(n, 0);
  for(auto [a, b]: edges){
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  parent[n-1] = -1;
  dfs(n-1);
  int ptr = -1;
  vector<int> degree(n);
  for (int i = 0; i < n; i++) {
    degree[i] = adj[i].size();
    if (degree[i] == 1 && ptr == -1)
      ptr = i;
  }
  vector<int> code(n - 2);
  int leaf = ptr;
  for (int i = 0; i < n - 2; i++) {
    int next = parent[leaf];
    code[i] = next;
    if (--degree[next] == 1 && next < ptr) {
      leaf = next;
    } else {
      ptr++;
      while (degree[ptr] != 1)
        ptr++;
      leaf = ptr;
    }
  }
  return code;
}
