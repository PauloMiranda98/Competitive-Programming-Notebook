#include "../../code/math/binomial_coefficients.h"
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};

void testC1(){
  vector<ll> factorial(21);
  factorial[0] = factorial[1] = 1;
  for (int n = 2; n <= 20; n++)
    factorial[n] = n * factorial[n - 1];
  for (int n = 0; n <= 20; n++){
    for (int k = 0; k <= n; k++){
      ll comb = (factorial[n] / factorial[k]) / factorial[n - k];
      assert(comb == C1(n, k));
    }
  }
}

void testC2(){
  vector<ll> factorial(21);
  factorial[0] = factorial[1] = 1;
  for (int n = 2; n <= 20; n++)
    factorial[n] = n * factorial[n - 1];

  for (int mod : primes){
    auto comb = C2(20, mod);
    for (int n = 0; n <= 20; n++){
      for (int k = 0; k <= n; k++){
        ll ans = (factorial[n] / factorial[k]) / factorial[n - k];
        assert(ans % mod == comb[n][k]);
      }
    }
  }
}

void testC3(){
  for (int mod : primes){
    auto comb = C2(mod - 1, mod);
    prevC3(mod - 1, mod);
    for (int n = 0; n < mod; n++){
      for (int k = 0; k <= n; k++){
        assert(comb[n][k] == C3(n, k, mod));
      }
    }
  }
}

void testC4(){
  for (int mod : primes){
    auto comb = C2(mod - 1, mod);
    for (int n = 0; n < mod; n++){
      for (int k = 0; k <= n; k++){
        assert(comb[n][k] == C4(n, k, mod));
      }
    }
  }
}

int main(){
  testC1();
  testC2();
  testC3();
  testC4();
  return 0;
}