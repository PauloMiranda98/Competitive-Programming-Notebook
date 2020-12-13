#include <bits/stdc++.h>
using namespace std;
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
//a*x + b*y = g
//a*(x-(b/g)*k) + b*(y+(a/g)*k) = g
bool dioEq(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
	g = extGcd(abs(a), abs(b), x0, y0);
	if (c % g) return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}
inline void shift(ll &x, ll &y, ll a, ll b, ll cnt){
  x += cnt * b;
  y -= cnt * a;
}
// a1 + m1*x = a2 + m2*y
// Find the first moment that both are equal
ll findMinimum(ll a1, ll m1, ll a2, ll m2){
  ll a = m1, b = -m2, c = a2 - a1;
  ll x, y, g;
  if (!dioEq(a, b, c, x, y, g))
    return -1;
  a /= g;
  b /= g;
  int sa = a > 0 ? +1 : -1;
  int sb = b > 0 ? +1 : -1;
  shift(x, y, a, b, -x/b);
  if(x < 0) 
    shift(x, y, a, b, sb);
  if(y < 0){
    shift(x, y, a, b, y/a);
    if(y < 0)
      shift(x, y, a, b, -sa);
    if(x < 0)
      return -1;
  }
  return a*x*g;
}
ll findAllSolutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy){
	ll x, y, g;
	if(a==0 or b==0){
		if(a==0 and b==0)
			return (c==0)*(maxx-minx+1)*(maxy-miny+1);
		if(a == 0)
			return (c%b == 0)*(maxx-minx+1)*(miny<=c/b and c/b<=maxy);
		return (c%a == 0)*(minx<=c/a and c/a<=maxx)*(maxy-miny+1);
	}
	if (!dioEq(a, b, c, x, y, g))
		return 0;
	a /= g;
	b /= g;
	int sign_a = a > 0 ? +1 : -1;
	int sign_b = b > 0 ? +1 : -1;
	shift(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	ll lx1 = x;
	shift(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift(x, y, a, b, -sign_b);
	ll rx1 = x;
	shift(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	ll lx2 = x;
	shift(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift(x, y, a, b, sign_a);
	ll rx2 = x;
	if (lx2 > rx2)
		swap(lx2, rx2);
	ll lx = max(lx1, lx2);
	ll rx = min(rx1, rx2);
	if (lx > rx)
		return 0;
	return (rx - lx) / abs(b) + 1;
}
