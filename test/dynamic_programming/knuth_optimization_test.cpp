#include "../../code/dynamic_programming/knuth_optimization.h"
ll v[MAXN];
ll sum[MAXN];
ll C(int a, int b){
	return sum[b]-((a>0)?sum[a-1]:0);
}
ll bruteforce(int i, int j){
  if(i > j)
    return 0;
  if (i == j)
    return 0;
  ll ans = INFLL;
  for(int k=i; k<j; k++)
    ans = min(ans, C(i, j)+bruteforce(i, k)+bruteforce(k+1, j));
  return ans;
}
void test1(){
  int n = 4;
  int i=0;
  for (int x : {25, 25, 25, 25})
    v[i++] = x;
  sum[0] = v[0];
  for(int i=1; i<n; i++)
    sum[i] = sum[i-1] + v[i];
  assert(knuth(n) == bruteforce(0, n-1));
}
void test2(){
  int n = 5;
  int i=0;
  for (int x : {4, 1, 2, 1, 2})
    v[i++] = x;
  sum[0] = v[0];
  for(int i=1; i<n; i++)
    sum[i] = sum[i-1] + v[i];
  assert(knuth(n) == bruteforce(0, n-1));
}
int main(){
  test1();
  test2();
  return 0;
}