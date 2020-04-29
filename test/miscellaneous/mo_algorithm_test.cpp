#include "../../code/miscellaneous/mo_algorithm.h"
int ans;
vector<int> v;
void add(int i){
  ans += v[i];
}
void remove(int i){
  ans -= v[i];
}
int getAnswer(){
  return ans;
}
void clearAnswer(){
  ans = 0;
}

int brute(int i, int j){
  int sum = 0;
  for (int k = i; k <= j; k++)
    sum += v[k];
  return sum;
}
void testMo(){
  srand(time(0));
  int n = 1000;
  v.resize(n);
  for (int i = 0; i < n; i++)
    v[i] = rand() % 100000;
  vector<Query> q(n);
  for (int i = 0; i < n; i++){
    q[i].idx = i;
    q[i].l = rand() % n;
    q[i].r = rand() % n;
    if (q[i].l > q[i].r)
      swap(q[i].l, q[i].r);
  }
  vector<int> ans = mo_s_algorithm(q);
  for (int i = 0; i < n; i++)
    assert(ans[i] == brute(q[i].l, q[i].r));
}
int main(){
  for(int i=0; i<10; i++)
    testMo();
  
  return 0;
}