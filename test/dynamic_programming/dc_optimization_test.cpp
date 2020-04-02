#include "../../code/dynamic_programming/dc_optimization.h"
const int MAXX = 1000010;
int mp[MAXX];
int ans, L, R;
int v[MAXN];
void add(int i){
  if (mp[v[i]] == 0)
    ans++;
  mp[v[i]]++;
}
void remove(int i){
  mp[v[i]]--;
  if (mp[v[i]] == 0)
    ans--;
}
int C(int i, int j){
  while (i < L)
    add(--L);
  while (R < j)
    add(++R);
  while (L < i)
    remove(L++);
  while (j < R)
    remove(R--);
  return ans;
}
int dp2[MAXN][MAXK];
int bruteforce(int n, int k){
  if (n == 0)
    return (k == 0) ? 0 : -INF;
  int ans = -INF;
  for (int j = 0; j < n; j++)
    ans = max(ans, bruteforce(j, k - 1) + C(j + 1, n));
  return ans;
}
void test1(){
  int n = 8, k = 3;
  int i = 1;
  for (int x : {7, 7, 8, 7, 7, 8, 1, 7})
    v[i++] = x;
  L = 1, R = 1;
  add(1);
  assert(solve(n, k) == bruteforce(n, k));
}
void test2(){
  int n = 7, k = 2;
  int i = 1;
  for (int x : {1, 3, 3, 1, 4, 4, 4})
    v[i++] = x;
  L = 1, R = 1;
  add(1);
  assert(solve(n, k) == bruteforce(n, k));
}
int main(){
  test1();
  test2();
  return 0;
}