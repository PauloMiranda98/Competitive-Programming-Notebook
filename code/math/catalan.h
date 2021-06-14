#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
ll extGcd(ll a, ll b, ll &x, ll &y){
  if (b == 0){
    x = 1, y = 0;
    return a;
  }else{
    ll g = extGcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  }
}
ll inv(ll a){
  ll inv_x, y;
  extGcd(a, MOD, inv_x, y);
  return (inv_x%MOD + MOD)%MOD;
}
const int MAXN = 4000010;
ll fat[MAXN], ifat[MAXN];
void init(){
  fat[0] = 1;
  for(int i=1; i<MAXN; i++)
    fat[i] = (fat[i-1]*i)%MOD;
  ifat[MAXN - 1] = inv(fat[MAXN - 1]);
  for(int i=MAXN-2; i>=0; i--)
    ifat[i] = (ifat[i+1]*(i+1))%MOD;
  assert(ifat[0] == 1);
}
ll C(int n, int k){
  if(k > n)
    return 0;
  return (fat[n]*((ifat[k]*ifat[n-k])%MOD))%MOD;
}
ll catalan(int n){
  return (C(2*n, n) - C(2*n, n-1) + MOD)%MOD;
}
ll f(int x1, int y1, int x2, int y2){
  int y = y2 - y1, x = x2 - x1;
  if(y < 0 or x < 0)
    return 0;
  return C(x + y, x);
}
// o = number of '(', c = number of ')', k = fixed prefix of '(' extra
// Catalan Generalization, open[i] >= close[i] for each 0 <= i < o + c + k
// where open[i] is number of '(' in prefix until i 
// and close[i] is number of ')'
ll catalan2(int o, int c, int k){
  int x = o + k - c;
  if(x < 0)
    return 0;
  return (f(k, 0, o+k, c) - f(k, 0, o+k-x-1, c + x + 1) + MOD)%MOD;
}