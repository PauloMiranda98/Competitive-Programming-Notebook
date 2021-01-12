#include <bits/stdc++.h>
using namespace std;
// Source: https://github.com/brunomaletta/Biblioteca
template<typename T> struct RMQ{
  vector<T> v;
  int n; static const int b = 30;
  vector<int> mask, t;
  int op(int x, int y) { return v[x] < v[y] ? x : y; }
  int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
  int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
  RMQ(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
    for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
      at = (at<<1)&((1<<b)-1);
      while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
    }
    for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
    for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
      t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
  }
  T query(int l, int r) {
    if (r-l+1 <= b) return v[small(r, r-l+1)];
    int ans = op(small(l+b-1), small(r));
    int x = l/b+1, y = r/b-1;
    if (x <= y) {
      int j = msb(y-x+1);
      ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
    }
    return v[ans];
//    return ans; // for get position
  }
};
