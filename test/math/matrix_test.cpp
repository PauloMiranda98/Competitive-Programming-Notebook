#include "../../code/math/matrix.h"
Matrix fastPow(Matrix base, ll exp, ll mod = MOD){
	Matrix ans(true);
	while (exp > 0){
		if (exp & 1LL)
			ans = ans * base;
		base = base * base;
		exp >>= 1;
	}
	return ans;
}
int nthFib(int n){
  if(n < 1)
    return 0;
	Matrix base({{1, 1, 1}, {0, 1, 1}, {0, 1, 0}});
	base = fastPow(base, n-1);
	return modSum(base[1][0],  base[1][1]);
}
int sumFib(int n){
  if(n < 1)
    return 0;
	Matrix base({{1, 1, 1}, {0, 1, 1}, {0, 1, 0}});
	base = fastPow(base, n-1);
	return modSum(base[0][0],  base[0][1]);
}
const int MAXN = 10010;
int fib[MAXN];
int sum[MAXN];
void test(){
  fib[0] = sum[0] = 0;
  fib[1] = sum[1] = 1;
  for(int i=2; i<MAXN; i++){
    fib[i] = modSum(fib[i-1], fib[i-2]);
    assert(fib[i] == nthFib(i));
    sum[i] = modSum(sum[i-1], fib[i]);
    assert(sum[i] == sumFib(i));
  }
}
int main(){
  test();
  return 0;
}