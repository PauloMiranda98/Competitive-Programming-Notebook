#include "../../code/math/linear_sequence.h"
void test1(){
  assert(true); // AC: https://www.codechef.com/problems/RNG
}
int fib(int n){
  vector<int> fib(n + 1);
  fib[0] = 0;
  fib[1] = 1;
  for(int i=2; i<=n; i++){
    fib[i] = (fib[i-1] + fib[i-2])%MOD;
  }
  return fib[n];
}
void test2(){
  for(int i=0; i<=100; i++){
    int f1 = LinearSeq::findElementInPositionN({0, 1, 1, 2}, i);
    assert(f1 == fib(i));
  }
}
int main(){
  test1();
  test2();
  return 0;
}
