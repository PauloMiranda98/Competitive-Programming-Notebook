#include <bits/stdc++.h>
using namespace std;
double f(double x);
const int N = 1000000;
double simpson_integration(double a, double b){
  double h = (b - a) / N;
  double s = f(a) + f(b); // a = x_0 and b = x_2n
  for (int i = 1; i <= N - 1; ++i) { // Refer to final Simpson's formula
    double x = a + h * i;
    s += f(x) * ((i & 1) ? 4 : 2);
  }
  s *= h / 3;
  return s;
}