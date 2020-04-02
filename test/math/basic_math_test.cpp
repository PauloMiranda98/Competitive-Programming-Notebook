#include "../../code/math/basic_math.h"
void testFastPow(){
  for (ll mod = 2; mod <= 100; mod++){
    for (ll base = 0; base <= 100; base++){
      ll ans = 1;
      for (ll exp = 1; exp <= 100; exp++){
        ans = (ans * base) % mod;
        assert(ans == fastPow(base, exp, mod));
      }
    }
  }
}
void testMillerRabin(){
  for (ll prime : {1993LL, 1997LL, 1999LL, 2017LL, 7823LL, 7829LL, 998244353LL, 1000000007LL, 1000000009LL, 87178291199LL})
    assert(millerRabin(prime) == true);
  for (ll noPrime : {7875, 7878, 4623, 4641, 1000000005})
    assert(millerRabin(noPrime) == false);
}
int main(){
  testFastPow();
  testMillerRabin();
  return 0;
}