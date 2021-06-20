#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int ans[MAXN];
bool test(int x);
void add(int k);
void remove(int k);
void solve(int i, int j, vector<int> &v){
  if(v.empty())
    return;
  if(i == j){
    for(int x: v)
      ans[x] = i;
    return;
  }
  int mid = (i+j)/2;
  for(int k=i; k<=mid; k++) 
    add(k);
  vector<int> left, right;
  for(int x: v){
    if(test(x))
      left.push_back(x);
    else
      right.push_back(x);
  }
  solve(mid+1, j, right);
  for(int k=mid; k>=i; k--)
    remove(k); // Or roolback();
  solve(i, mid, left);
}
