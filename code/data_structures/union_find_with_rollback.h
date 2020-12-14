#include <bits/stdc++.h>
using namespace std;
struct RollbackUF {
  vector<int> e; 
  vector<tuple<int, int, int, int>> st;
  RollbackUF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return st.size(); }
  void rollback(int t) {
    while (st.size() > t){
      auto [a1, v1, a2, v2] = st.back();
      e[a1] = v1; e[a2] = v2;
      st.pop_back();
    }
  }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    st.push_back({a, e[a], b, e[b]});
    e[a] += e[b]; e[b] = a;
    return true;
  }
};