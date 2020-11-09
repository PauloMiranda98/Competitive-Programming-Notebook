#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
struct modInt{
  int val;
  modInt(long long v = 0) {
    if (v < 0)
      v = (v % MOD) + MOD;
    if (v >= MOD)
      v %= MOD;
    val = v;
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
  explicit operator int() const {
    return val;
  }
  modInt& operator+=(const modInt &other) {
    val += other.val;
    if (val >= MOD) 
      val -= MOD;
    return *this;
  }
  modInt& operator-=(const modInt &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  modInt& operator*=(const modInt &other) {
    val = ((uint64_t) val * other.val) % MOD;
    return *this;
  }
  modInt& operator/=(const modInt &other) {
    return *this *= other.inv();
  }
  friend modInt operator+(const modInt &a, const modInt &b) {
    return modInt(a) += b;
  }
  friend modInt operator-(const modInt &a, const modInt &b) {
    return modInt(a) -= b;
  }
  friend modInt operator*(const modInt &a, const modInt &b) {
    return modInt(a) *= b;
  } 
  friend modInt operator/(const modInt &a, const modInt &b) {
    return modInt(a) /= b;
  }
  modInt& operator++() {
    val = (val == (MOD - 1)) ? 0 : val + 1;
    return *this;
  }
  modInt operator++(int) {
    modInt before = *this;
    ++*this;
    return before;
  }
  modInt& operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  modInt operator--(int) {
    modInt before = *this;
    --*this;
    return before;
  }
  modInt operator-() const {
    return (val == 0) ? 0 : MOD - val;
  }
  bool operator==(const modInt &other) const {
    return val == other.val;
  }
  bool operator!=(const modInt &other) const {
    return val != other.val;
  }
  modInt inv() const {
    return modInv(val);
  }
  modInt pow(long long p) const {
    assert(p >= 0);
    modInt a = *this, result = 1;
    while (p > 0) {
      if (p & 1)
        result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
};
