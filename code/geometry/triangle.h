#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld PI = acosl(-1);
struct Triangle{
  ld a, b, c;
  Triangle(){}
  Triangle(ld a1, ld b1, ld c1):a(a1), b(b1), c(c1){
    fix();
  }
  ld area(){
    ld s = (a + b + c)/2;
    return sqrtl(s*(s-a)*(s-b)*(s-c));
  }
  void fix(){
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
  }
  tuple<ld, ld, ld> angle(){
    fix();
    ld h = (2*area())/c;
    ld aa = asin(h/b);
    ld bb = asin(h/a);
    return {aa, bb, PI - aa - bb};
  }
};
