#include "../../code/math/prime.h"
void testMillerRabin(){
  for (ll prime : {1993LL, 1997LL, 1999LL, 2017LL, 7823LL, 7829LL, 998244353LL, 1000000007LL, 1000000009LL, 87178291199LL})
    assert(millerRabin(prime) == true);
  for (ll noPrime : {7875, 7878, 4623, 4641, 1000000005})
    assert(millerRabin(noPrime) == false);
}
void testFactor(){
  vector<ull> v1, v2;
  v1 = factor(12345);
  sort(v1.begin(), v1.end());
  v2 = {3ULL, 5ULL, 823ULL};
  assert(v1 == v2);

  v1 = factor(12345678911);
  sort(v1.begin(), v1.end());
  v2 = {3643ULL, 3388877ULL};
  assert(v1 == v2);

}
int main(){
  testMillerRabin();
  testFactor();
  return 0;
}