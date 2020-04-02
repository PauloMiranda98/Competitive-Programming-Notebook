#include <bits/stdc++.h>
#include "extended_euclidean.h"
using namespace std;
typedef long long ll;
namespace CRT{
  inline ll normalize(ll x, ll mod){ 
    x %= mod; 
    if(x < 0) x += mod; 
    return x;
  }
  ll solve(vector<ll> a, vector<ll>m){
    int n = a.size();
    for(int i=0; i<n; i++)
      normalize(a[i], m[i]);
    ll ans = a[0];
    ll lcm1 = m[0];
    for(int i = 1; i < n; i++){
      ll x, y;
      ll g = extGcd(lcm1, m[i], x, y);
      if((a[i] - ans) % g != 0) 
        return -1;
      ans = normalize(ans + ((((a[i]-ans)/g)*x)%(m[i]/g))*lcm1, (lcm1/g)*m[i]);
      lcm1 = (lcm1/g)*m[i];//lcm(lcm1, m[i]);
    }
    return ans;   
  }
}