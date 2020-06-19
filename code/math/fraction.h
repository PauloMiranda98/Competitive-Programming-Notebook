#include <bits/stdc++.h>
using namespace std;
typedef long long f_type;
//Representation of the a/b
struct Fraction {  
  f_type a, b;
  Fraction(f_type _a = 0): a(_a), b(1){}  
  Fraction(f_type _a, f_type _b) {
    f_type g = __gcd(_a, _b);
    a = _a/g;
    b = _b/g;    
    if(b < 0){
      a = -a;
      b = -b;
    }
  }
  Fraction operator+(Fraction oth) {    
    return Fraction(a*oth.b + oth.a*b, b*oth.b);
  }
  Fraction operator-(Fraction oth) {    
    return Fraction(a*oth.b - oth.a*b, b*oth.b);
  }
  Fraction operator*(Fraction oth) {    
    return Fraction(a*oth.a, b*oth.b);
  }
  Fraction operator/(Fraction oth) {    
    return Fraction(a*oth.b, b*oth.a);
  }
  bool operator>=(Fraction oth){
    return ((*this) - oth).a >= 0;
  }
  bool operator==(Fraction oth){
    return a == oth.a and b == oth.b;
  }  
  operator f_type() {return a/b;}
  operator double() {return double(a)/b;}
};
