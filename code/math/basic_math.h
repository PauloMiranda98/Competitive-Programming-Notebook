#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull fastPow(ull base, ull exp, ull mod){
  base %= mod;
  //exp %= phi(mod) if base and mod are relatively prime
  ull ans = 1LL;
  while (exp > 0){
    if (exp & 1LL)
      ans = (ans * (__int128_t)base) % mod;
    base = (base * (__int128_t)base) % mod;
    exp >>= 1;
  }
  return ans;
}
ll gcd(ll a, ll b){ return __gcd(a, b); }
ll lcm(ll a, ll b){ return (a / gcd(a, b)) * b; }
void enumeratingAllSubmasks(int mask){
  for (int s = mask; s; s = (s - 1) & mask)
    cout << s << endl;
}
//MOD to Hash
namespace ModHash{
  const uint64_t MOD = (1ll<<61) - 1;
  uint64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
    uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
    uint64_t ret = (l&MOD) + (l>>61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
    ret = (ret & MOD) + (ret>>61);
    ret = (ret & MOD) + (ret>>61);
    return ret-1;
  }
};