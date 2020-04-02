#include "../../code/math/chinese_remainder_theorem.h"
void test1CRT(){
  vector<ll> m = {5, 6, 7, 11};
  vector<ll> a = {3, 3, 1, 0};
  assert(CRT::solve(a, m) == 1023);
}
void test2CRT(){
  vector<ll> m = {2, 3, 4, 6, 11};
  vector<ll> a(m.size());
  for (int test = 0; test <= 100; test++){
    for (int i = 0; i < m.size(); i++)
      a[i] = test % m[i];
    ll ans = CRT::solve(a, m);
    assert(test == ans);
  }
}
int main(){
  test1CRT();
  test2CRT();
  return 0;
}