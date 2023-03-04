#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937_64 rng_64((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline int64_t rand(int64_t l, int64_t r){
  return uniform_int_distribution<int64_t>(l, r)(rng_64);
}
const uint64_t MOD = (1ll<<61) - 1;
const uint64_t BASE = rand(2e9, MOD - 1);
// If x is limited it is possible to replace fastPow with a precomputed vector
struct MultisetHash{
public:
  MultisetHash(vector<ll> init={}) {
    val = 0;
    for(auto x: init)
      add(x);
  }
  void add(ll x){
    val = sum(val, fastPow(BASE, x));
  }
  void add(ll x, ll times){
    val = sum(val, mul(fastPow(BASE, x), times));
  }
  void addMultiset(MultisetHash oth){
    val = sum(getHash(), oth.getHash());
  }
  void rem(ll x){
    val = sub(val, fastPow(BASE, x));
  }
  void rem(ll x, ll times){
    val = sub(val, mul(fastPow(BASE, x), times));
  }
  void remMultiset(MultisetHash oth){
    val = sub(getHash(), oth.getHash());
  }
  void sumToAll(ll d){
    val = mul(val, fastPow(BASE, d));
  }
  ll getHash(){
    return val;
  }
private:
  ll val;
  ll inline sum(ll a, ll b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
  }
  ll inline sub(ll a, ll b){
    a -= b;
    if(a < 0) a += MOD;
    return a;
  }
  ll mul(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
    uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
    uint64_t ret = (l&MOD) + (l>>61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
    ret = (ret & MOD) + (ret>>61);
    ret = (ret & MOD) + (ret>>61);
    return ret-1;
  }
  
  ll fastPow(ll a, ll p) {
    ll ans = 1;
    while (p > 0) {
      if (p & 1)
        ans = mul(ans, a);
      a = mul(a, a);
      p >>= 1;
    }
    return ans;
  }
};