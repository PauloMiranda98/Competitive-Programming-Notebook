#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e4 + 10, UPD = 2e5 + 10, LOG = 20;
const int MAXS = 4 * MAX + UPD * LOG;
namespace PerSegTree{
  typedef long long pst_t;
  pst_t seg[MAXS];
  int T[UPD], L[MAXS], R[MAXS], cnt, t;
  int n, *v;
  pst_t neutral = 0;  
  pst_t join(pst_t a, pst_t b){
    return a + b;
  }
  pst_t build(int p, int l, int r){
    if (l == r)
      return seg[p] = v[l];
    L[p] = cnt++, R[p] = cnt++;
    int m = (l + r) / 2;
    return seg[p] = join(build(L[p], l, m), build(R[p], m + 1, r));
  }
  pst_t query(int a, int b, int p, int l, int r){
    if (b < l or r < a)
      return 0;
    if (a <= l and r <= b)
      return seg[p];
    int m = (l + r) / 2;
    return join(query(a, b, L[p], l, m), query(a, b, R[p], m + 1, r));
  }
  pst_t update(int a, int x, int lp, int p, int l, int r){
    if (l == r)
      return seg[p] = x;
    int m = (l + r) / 2;
    if (a <= m)
      return seg[p] = join(update(a, x, L[lp], L[p] = cnt++, l, m), seg[R[p] = R[lp]]);
    return seg[p] = join(seg[L[p] = L[lp]], update(a, x, R[lp], R[p] = cnt++, m + 1, r));
  }
//Public:
  //O(n)
  void build(int n2, int *v2){
    n = n2, v = v2;
    T[0] = cnt++;
    build(0, 0, n - 1);
  }
  //O(log(n))
  pst_t query(int a, int b, int tt){
    return query(a, b, T[tt], 0, n - 1);
  }
  //O(log(n))
  //update: v[idx] = x;
  int update(int idx, int x, int tt = t){
    update(idx, x, T[tt], T[++t] = cnt++, 0, n - 1);
    return t;
  }
}; // namespace perseg
