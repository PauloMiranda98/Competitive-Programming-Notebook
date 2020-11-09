#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
struct Poly{
  vector<ld> v;
  Poly(vector<ld> &v1):v(v1){}
  //return f(x)
  ld f(ld x){ 
    ld ans = 0;
    ld e = 1;
    int n = v.size();
    for(int i=0; i<n; i++){
      ans += v[i] * e;
      e *= x;
    }
    return ans;
  }
  //return f'(x)
  ld df(ld x){  
    ld ans = 0;
    ld e = 1;
    int n = v.size();
    for(int i=1; i<n; i++){
      ans += i * v[i] * e;
      e *= x; 
    }
    return ans;
  }
  // takes some root of the polynomial
  ld root(ld x0=1){
    const ld eps = 1E-10;
    ld x = x0;
    for (;;) {
      ld nx = x - (f(x)/df(x));
      if (abs(x - nx) < eps)
        break;
      x = nx;
    }
    return x; 
  }
  //div f(x) by (x-a)
  void div(ld a){
    int g = (int)v.size() - 1;
    vector<ld> aux(g);
    for(int i=g; i>=1; i--){
      aux[i-1] = v[i];
      v[i-1] += a*aux[i-1];
    }
    v = aux;
  }
};