#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ns;
int np;
bitset<10000010> bs;
vector<ll> primes;
void sieve(ll l) {
  ns = l+1;
  bs.set();
  primes.clear();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < ns; i++) if (bs[i]) {
    for(ll j = i*i; j < ns; j += i) 
      bs[j] = 0;
    primes.push_back(i);
  }
  np = primes.size();
}
bool isPrime(ll n) {
  if(n < ns)
    return bs[n];
  for(ll p: primes){
    if(p*p > n) break;
    if(n%p == 0)
      return false;
  }
  return true;
}
vector<ll> primeFactors(ll n) {
  vector<ll> factors;
  for(ll p: primes){
    if(p*p > n) break;
    while(n%p == 0LL) {
      n /= p;
      factors.push_back(p);
    }
  }
  if(n != 1LL) factors.push_back(n);
  return factors;
}
ll numDiv(ll n) {
  ll ans = 1;
  for(ll p: primes){
    if(p*p > n) break;
    ll f = 0;
    while(n%p == 0LL) {
      n /= p;
      f++;
    }
    ans *= (f+1LL);
  }
  return (n != 1LL) ? 2LL*ans : ans;
}
ll sumDiv(ll n) {
  ll ans = 1;
  for(ll p: primes){
    if(p*p > n) break;
    ll power = p;
    while(n%p == 0LL) {
      n /= p;
      power *= p;
    }
    ans *= (power - 1LL)/(p - 1LL);
  }
  if(n != 1LL)
    ans *= (n*n - 1LL)/(n - 1LL);
  return ans;
}
int mobius[1000010];
void sieveMobius(ll l) {
  sieve(l);
  mobius[1] = 1;
  for(int i=2; i<=l; i++)
    mobius[i] = 0;
  for(ll p: primes){
    if(p > l) break;
    for(ll j = p; j <= l; j += p){
      if(mobius[j] != -1){
        mobius[j]++;
        if(j%(p*p) == 0)
          mobius[j] = -1;
      }
    }
  }
  for(int i=2; i<=l; i++){
    if(mobius[i] == -1)
      mobius[i] = 0;
    else if(mobius[i]%2 == 0)
      mobius[i] = 1;
    else
      mobius[i] = -1;
  }
}
