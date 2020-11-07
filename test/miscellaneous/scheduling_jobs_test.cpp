#include "../../code/miscellaneous/scheduling_jobs.h"
ll penalty1(vector<Job> v){
  ll ans = 0;
  ll T=0;
  for(Job j: v){
    ans += j.c*(ll)T;
    T += j.t;
  }
  return ans;
}
long double penalty2(vector<Job> v){
  long double ans = 0;
  ll T=0;
  for(Job j: v){
    ans += j.c*exp(alfa*T);
    T += j.t;
  }
  return ans;
}
void testCmp1(){
  srand(2020);
  vector<Job> v;
  for(int i=0; i<9; i++){
    Job j;
    j.t = (rand()%1000) + 1; j.c = (rand()%1000) + 1;
    v.emplace_back(j);
  }
  sort(v.begin(), v.end(), cmp1);
  ll ans = penalty1(v);
  ll mnAns = ans;
  do{
    mnAns = min(mnAns, penalty1(v));
  }while(next_permutation(v.begin(), v.end(), cmp1));
  assert(ans == mnAns);
}
void testCmp2(){
  srand(2020);
  vector<Job> v;
  for(int i=0; i<8; i++){
    Job j;
    j.t = (rand()%2) + 1; j.c = (rand()%1000) + 1;
    v.emplace_back(j);
  }
  sort(v.begin(), v.end(), cmp2);
  long double ans = penalty1(v);
  long double mnAns = ans;
  do{
    mnAns = min(mnAns, penalty2(v));
  }while(next_permutation(v.begin(), v.end(), cmp1));
  assert(abs(ans-mnAns) < EPS);
}

int main(){
  testCmp1();
  testCmp2();
  return 0;
}

