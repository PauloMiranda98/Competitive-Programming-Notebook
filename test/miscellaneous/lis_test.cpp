#include "../../code/miscellaneous/lis.h"
vector<int> v;
int n;
int brute(int i, int x){
  if(i == n)
    return 0;
  if(v[i] > x)
    return max(brute(i+1, x), 1 + brute(i+1, v[i]));
  else
    return brute(i+1, x);
}
void test(){
  srand(time(0));
  n = 18;
  v.resize(n);
  for (int i = 0; i < n; i++)
    v[i] = rand() % 100000;
  vector<int> ans = lis(v);
  assert((int)ans.size() == brute(0, -0x3f3f3f3f));
}
int main(){
  for(int i=0; i<10; i++)
    test();
  
  return 0;
}