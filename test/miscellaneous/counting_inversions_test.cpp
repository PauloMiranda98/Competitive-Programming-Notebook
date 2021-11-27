#include "../../code/miscellaneous/counting_inversions.h"
void test1(){
  int T = 5;
  srand(2020);
  while(T--){
    int n = 1000;
    vector<int> v(n);
    for(int i=0; i<n; i++)
      v[i] = rand()%10;
    int ans = 0;
    for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++)
        ans += (v[i] > v[j]);
    assert(ans == ci(v));
  }
}
void test2(){ 
  assert(true); // AC: https://www.spoj.com/submit/INVCNT/
  assert(true); // AC: https://neps.academy/problem/63
  assert(true); // AC: https://cses.fi/problemset/task/1162/
}
int main() {
  test1();
  test2();
  return 0; 
}
