#include "../../code/math/simpson_integration.h"
double f(double x){
  return 2*x;
}
const double EPS = 1e-9;

void test(){
  assert(abs(simpson_integration(0, 2) - 4) < EPS);
  assert(abs(simpson_integration(0, 4) - 16) < EPS);
}

int main(){ 
  test();
  return 0;
}
