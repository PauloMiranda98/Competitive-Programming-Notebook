#include "../../code/math/karatsuba.h"
typedef long long ll;
vector<ll> brute(vector<ll> a, vector<ll> b){
  int n = a.size(), m = b.size();
  vector<ll> ans(n + m, 0);
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
      ans[i+j] += a[i] * b[j];
  return ans;
}
void test1(){
  srand(98);
  int n = 2048;
  for(int t=1; t<=5; t++){
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++)
      a[i] = rand();
    for(int i=0; i<n; i++)
      b[i] = rand();
    auto ans1 = karatsuba(a, b);
    auto ans2 = brute(a, b);
    assert(ans1 == ans2);
  }
}
int main() {
  test1();
  return 0;
}
