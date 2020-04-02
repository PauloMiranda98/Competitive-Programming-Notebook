#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastPow(ll base, ll exp, ll mod){
  base %= mod;
  //exp %= phi(mod) if base and mod are relatively prime
  ll ans = 1LL;
  while (exp > 0){
    if (exp & 1LL)
      ans = (ans * (__int128_t)base) % mod;
    base = (base * (__int128_t)base) % mod;
    exp >>= 1;
  }
  return ans;
}
ll extGcd(ll a, ll b, ll &x, ll &y){
  if (b == 0){
    x = 1;
    y = 0;
    return a;
  }else{
    ll g = extGcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  }
}
ll gcd(ll a, ll b){
  return __gcd(a, b);
}
ll lcm(ll a, ll b){
  return (a / gcd(a, b)) * b;
}
void enumeratingAllSubmasks(int mask){
  for (int s = mask; s; s = (s - 1) & mask)
    cout << s << endl;
}
bool checkComposite(ll n, ll a, ll d, int s){
  ll x = fastPow(a, d, n);
  if (x == 1 or x == n - 1)
    return false;
  for (int r = 1; r < s; r++){
    x = (x * (__int128_t)x) % n;
    if (x == n - 1LL)
      return false;
  }
  return true;
};
bool millerRabin(ll n){
  if (n < 2)
    return false;
  int r = 0;
  ll d = n - 1LL;
  while ((d & 1LL) == 0){
    d >>= 1;
    r++;
  }
  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
    if (n == a)
      return true;
    if (checkComposite(n, a, d, r))
      return false;
  }
  return true;
}