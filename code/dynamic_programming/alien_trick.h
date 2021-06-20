#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
pll solveDP(ll C);
ll solveMax(int k){
  ll lo = 0, hi=1e16, ans=1e16;
  while(lo <= hi){
    ll mid = (lo+hi)>>1;
    if(solveDP(mid).S <= k){
      ans = mid;
      hi = mid - 1;
    }else{
      lo = mid + 1;
    }
  }
  return solveDP(ans).F + k*ans;
}
