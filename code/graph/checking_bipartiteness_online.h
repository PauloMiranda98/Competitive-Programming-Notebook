#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 500010;
pii parent[N];
int rk[N];
int bipartite[N];
void make_set(int v) {
  parent[v] = pii(v, 0);
  rk[v] = 0;
  bipartite[v] = true;
}
pii find_set(int v) {
  if (v != parent[v].first) {
    int parity = parent[v].second;
    parent[v] = find_set(parent[v].first);
    parent[v].second ^= parity;
  }
  return parent[v];
}
void add_edge(int a, int b) {
  int x, y;
  tie(a, x) = find_set(a);
  tie(b, y) = find_set(b);
  if (a == b) {
    if (x == y)
      bipartite[a] = false;
  }else{
    if (rk[a] < rk[b])
      swap (a, b);
    parent[b] = pii(a, x^y^1);
    bipartite[a] &= bipartite[b];
    if (rk[a] == rk[b])
      ++rk[a];
  }
}
bool is_bipartite(int v) {
  return bipartite[find_set(v).first];
}