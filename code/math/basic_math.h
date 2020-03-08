#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastPow(ll base, ll exp, ll mod){
  ll ans = 1;
  while(exp > 0){
    if(exp & 1LL)
      ans = (ans * base)%mod;
    base = (base * base)%mod;
    exp >>= 1;
  }
  return ans;  
}
