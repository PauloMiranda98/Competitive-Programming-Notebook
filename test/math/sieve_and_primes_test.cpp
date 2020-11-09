#include "../../code/math/sieve_and_primes.h"

void testIsPrime(){
  sieve(10000000);
  for (ll prime : {1993LL, 1997LL, 1999LL, 2017LL, 7823LL, 7829LL, 998244353LL, 1000000007LL, 1000000009LL, 87178291199LL})
    assert(isPrime(prime) == true);
  for (ll noPrime : {7875, 7878, 4623, 4641, 1000000005})
    assert(isPrime(noPrime) == false);
}

int main(){
  testIsPrime();
  return 0;
}
