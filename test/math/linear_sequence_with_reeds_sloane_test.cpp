#include "../../code/math/linear_sequence_with_reeds_sloane.h"
void test1(){
  assert(true); // AC: https://codeforces.com/gym/103960/problem/K
}
const int MOD = 1e9;
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
    vector<long long> v = {0, 1, 1, 2}; 
    LinearRecurrence lr(v, MOD, false);
    int f1 = lr.calc(i);
    assert(f1 == fib(i));
  }
}
int main(){
  test1();
  test2();
  return 0;
}
