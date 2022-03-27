#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
struct modInt{
  int val;
  modInt(ll v = 0) {
    if (v < 0)
      v = (v % MOD) + MOD;
    if (v >= MOD)
      v %= MOD;
    val = v;
  }
  explicit operator int() const {
    return val;
  }
  modInt operator+(const modInt &oth) {
    int ans = val + oth.val;
    if (ans >= MOD) 
      ans -= MOD;
    return modInt(ans);
  }
  modInt operator-(const modInt &oth) {
    int ans = val - oth.val;
    if (ans < 0) ans += MOD;
    return ans;
  }
  modInt operator*(const modInt &oth) {
    return ((uint64_t) val * oth.val) % MOD;
  }
  modInt operator-() const {
    return (val == 0) ? 0 : MOD - val;
  }
  bool operator==(const modInt &oth) const {
    return val == oth.val;
  }
  bool operator!=(const modInt &oth) const {
    return val != oth.val;
  }
  static int modInv(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r; swap(g, r);
      x -= q * y; swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  modInt inv() const {
    return modInv(val);
  }
  modInt operator/(const modInt &oth) {
    return (*this) * oth.inv();
  }
  modInt pow(long long p) const {
    assert(p >= 0);
    modInt a = *this, result = 1;
    while (p > 0) {
      if (p & 1)
        result = result * a;
      a = a * a;
      p >>= 1;
    }
    return result;
  }
};
modInt operator*(const modInt &a, const modInt &b) {
  return ((uint64_t) a.val * b.val) % MOD;
}