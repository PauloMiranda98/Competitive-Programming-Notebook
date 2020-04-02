#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
