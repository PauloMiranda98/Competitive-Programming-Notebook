#include <bits/stdc++.h>
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