#include "../../code/math/fraction.h"
Fraction f_1 = 1;
//Calculates number of integer points (x,y) such for 0<=x<n and 0<y<=floor(k*x+b)
//O(log(N)*log(MAXV))
f_type count_lattices(Fraction k, Fraction b, f_type n) {
  auto fk = (f_type)k;
  auto fb = (f_type)b;
  auto cnt = 0LL;
  
  if (k >= f_1 || b >= f_1) {
    cnt += (fk * (n - 1) + 2 * fb) * n / 2;
    k = k - Fraction(fk, 1);
    b = b - Fraction(fb, 1);
  }
  auto t = k * Fraction(n, 1) + b;
  auto ft = (f_type)t;
  if (ft >= 1) {
    cnt += count_lattices(f_1 / k, (t - Fraction((f_type)t, 1)) / k, (f_type)t);
  }
  return cnt;
}
