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
void testFloorSum(){
  for(int a=0; a<50; a++){
    for(int b=0; b<50; b++){
      for(int m=max(a, b)+1; m <= 50; m++){
        ll ans = 0;
        for(int n = 1; n<=50; n++){
          ans += (a*(n-1)+b)/m;
          assert(ans == floor_sum(n, m, a, b));
        }
      }
    }
  }
}
int main(){
  testFastPow();
  testFloorSum();
  return 0;
}