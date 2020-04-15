#include "../../code/math/montgomery.h"
void testMontgomery(){
  u128 MOD = 10000000000000000007ULL;
  Montgomery mont(MOD);
  u128 x = mont.mult(1234567890123LL, 987654321098765LL);
  assert(x == 5278253119480564534ULL);
}
int main(){
  testMontgomery();
  return 0;
}