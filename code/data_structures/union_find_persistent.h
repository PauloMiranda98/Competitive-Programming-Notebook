#include <bits/stdc++.h>
using namespace std;
namespace UnionFind{
  const int MAXN = 200010;
  int n, p[MAXN], sz[MAXN], ti[MAXN], T;
  void build(int n0) {
    T = -1, n = n0;
    for (int i = 0; i < n; i++) {
      p[i] = i;
      sz[i] = 1;
      ti[i] = -1;
    }
  }
  int find(int k, int t) {
    if (p[k] == k or ti[k] > t) return k;
    return find(p[k], t);
  }
  bool join(int a, int b, int t) {
    assert(T <= t);
    a = find(a, t); b = find(b, t);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    p[a] = b;
    ti[a] = t;
    T = t;
    return true;
  }
  bool isSame(int a, int b, int t){
    return find(a, t) == find(b, t);
  }
}