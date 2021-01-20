#include "../../code/math/xor_and_or_convolution.h"
vector<ll> convolutionBrute(vector<ll> a, vector<ll> b){
  int mx = max(a.size(), b.size());
  int n = 1;
  while(n < mx) 
    n <<= 1;
  a.resize(n, 0); b.resize(n, 0);
  vector<ll> ans(n, 0);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    ans[i^j] += a[i]*b[j];
  return ans;
}
void test(){
  srand(2021);
  int n = 2048;
  vector<ll> a(n, 0), b(n, 0);
  for(int i=0; i<n; i++){
    a[i] = rand()%13231;
    b[i] = rand()%13231;
  }
  auto ans1 = convolution(a, b);
  auto ans2 = convolutionBrute(a, b);
  assert(ans1 == ans2);
  assert(true); //AC: https://judge.yosupo.jp/problem/bitwise_and_convolution
  assert(true); //AC: https://judge.yosupo.jp/problem/bitwise_xor_convolution
  assert(true); //AC: https://csacademy.com/contest/archive/task/and-closure/statement/
  assert(true); //AC: https://csacademy.com/contest/archive/#task/random_nim_generator/
}
int main() {
  test();
  return 0;
}