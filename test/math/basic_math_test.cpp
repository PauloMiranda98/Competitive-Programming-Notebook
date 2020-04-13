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
int main(){
  testFastPow();
  return 0;
}