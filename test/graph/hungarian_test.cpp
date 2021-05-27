#include "../../code/graph/hungarian.h"
void test1(){
  int n = 3;
  vector<vector<int>> mat(n, vector<int>(n));
  mat[0] = {2, 5, 10};
  mat[1] = {1, 5, 3};
  mat[2] = {10, 20, 10};
  auto ans = solve(mat);
  assert(ans.second == 16);
  int sum = 0;
  for(int i=0; i<n; i++)
    sum += mat[i][ans.first[i]];
  assert(sum == 16);
}
void test2(){
  assert(true); //AC: https://codeforces.com/group/Ohoz9kAFjS/contest/266572/problem/H
  assert(true); //AC: https://cses.fi/problemset/task/2129/
}
int main() {
  test1();
  test2();
  return 0;
}
