#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
// O(N)
pll bruteForce(ll n){
  ll ans1 = 0, ans2 = 0;
  for(ll i = 1; i <= n; i++){
    ans1 += n/i;
    ans2 += (n/i)*i; // n - (n mod i);
  }
  return pll(ans1, ans2);
}
ll AP(ll a1, ll an){
  ll n = (an-a1+1);
  return ((a1+an)*n)/2LL;
}
// O(sqrt(N))
pll divisionTrick(ll n){
  ll ans1 = 0, ans2 = 0;
  for(ll l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    // n / i has the same value for l <= i <= r
    ans1 += (n/l)*(r-l+1);
    ans2 += (n/l)*AP(l, r);
  }
  return pll(ans1, ans2);
}
