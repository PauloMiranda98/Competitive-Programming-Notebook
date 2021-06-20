#include "../../code/geometry/triangle.h"
const double EPS = 1e-9;

void test(){
  Triangle t(3, 4, 5);
  auto [a, b, c] = t.angle();
  
  assert(abs(t.area() - (3*4)/2) < EPS);
  assert(abs(a - 0.643501108793) < EPS);
  assert(abs(b - 0.9272952180021) < EPS);
  assert(abs(c - PI/2) < EPS);
}
int main(){
  test();
  return 0;
}
