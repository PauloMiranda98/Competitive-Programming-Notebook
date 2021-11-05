#include "modular_int.h"
namespace LagrangePoly {
  const int MAXN = 100010;
  modInt den[MAXN], fat[MAXN], ifat[MAXN], l[MAXN], r[MAXN];
  void build(int n){
    fat[0] = 1;
    for(int i=1; i<=n; i++)
      fat[i] = fat[i-1] * i;
    ifat[n] = fat[n].inv();
    for(int i=n-1; i>=0; i--)
      ifat[i] = ifat[i+1] * (i+1);
  }
  // f(i) = y[i]
  //return f(x0)
  modInt getVal(vector<modInt> &y, ll x0) {
    int n = y.size();
    assert(fat[n-1] != 0);
    modInt x = x0;
    for(int i = 0; i < n; i++) {
      den[i] = ifat[n - i - 1] * ifat[i];
      if((n - i - 1) % 2 == 1) {
        den[i] = -den[i];
      }
    }
    l[0] = 1;
    for(int i = 1; i < n; i++) {
      l[i] = l[i - 1] * (x - (i - 1));
    }
    r[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
      r[i] = r[i + 1] * (x - (i + 1));
    }
    modInt ans = 0;
    for(int i = 0; i < n; i++) {
      modInt li = l[i] * r[i] * den[i];
      ans = (ans + (y[i] * li));
    }
    return ans;
  }
};