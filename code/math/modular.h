#include <bits/stdc++.h>
#include "basic_math.h"
#include "extended_euclidean.h"
using namespace std;
const int MOD = 1000000007;
inline int modSum(int a, int b, int mod = MOD){
	int ans = a+b;
	if(ans >= mod) ans -= mod;
	return ans;
}
inline int modSub(int a, int b, int mod = MOD){
	int ans = a-b;
	if(ans < 0) ans += mod;
	return ans;
}
inline int modMul(int a, int b, int mod = MOD){
	return (a*1LL*b)%mod;
}
int inv(int a, int mod=MOD){
	assert(a > 0);
	ll inv_x, y;
	extGcd(a, mod, inv_x, y);
	return (inv_x%mod + mod)%mod;		
}
int modDiv(int a, int b, int mod = MOD){
  return modMul(a, inv(b, mod));
}
int primitiveRoot(int p) {
  vector<int> fact;
  int phi = p-1,  n = phi;
  for (int i=2; i*i<=n; i++){
    if (n % i == 0) {
      fact.push_back (i);
      while (n % i == 0)
        n /= i;
    }
  }
  if (n > 1)
    fact.push_back (n);
  for (int res=2; res<=p; ++res) {
    bool ok = true;
    for (size_t i=0; i<fact.size() && ok; ++i)
      ok &= fastPow(res, phi / fact[i], p) != 1;
    if (ok)  return res;
  }
  return -1;
}
// Return x  ->   a ^ x = b mod m
// Example: a = 5, m = 10^9 + 7
// Funciona melhor se 'a' for raiz primitiva de 'm'
int discreteLogarithm(int a, int b, int m) {
  a %= m, b %= m;
  int k = 1, add = 0, g;
  while ((g = gcd(a, m)) > 1) {
    if (b == k)
      return add;
    if (b % g)
      return -1;
    b /= g, m /= g, ++add;
    k = (k * 1ll * a / g) % m;
  }
  int n = sqrt(m) + 1;
  int an = 1;
  for (int i = 0; i < n; ++i)
    an = (an * 1ll * a) % m;
  unordered_map<int, int> vals;
  for (int q = 0, cur = b; q <= n; ++q) {
    vals[cur] = q;
    cur = (cur * 1ll * a) % m;
  }
  for (int p = 1, cur = k; p <= n; ++p) {
    cur = (cur * 1ll * an) % m;
    if (vals.count(cur)) {
      int ans = n * p - vals[cur] + add;
      return ans;
    }
  }
  return -1;
}