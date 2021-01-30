#include "../../code/miscellaneous/mo_with_update.h"
int ans;
void add(int x){
  ans += x;
}
void remove(int x){
  ans -= x;
}
int getAnswer(){
  return ans;
}
void clearAnswer(){
  ans = 0;
}

int curr[MAXN];
int brute(int i, int j){
  int sum = 0;
  for (int k = i; k <= j; k++)
    sum += curr[k];
  return sum;
}
void testMo(){
  srand(time(0));
  int n = 1000;
  for (int i = 0; i < n; i++)
    curr[i] = v[i] = rand() % 100000;
  vector<Query> vq;
  vector<Update> vu;
  vector<int> vans;
  for (int i = 0; i < 5*n; i++){
    int op = rand()%2;
    if(op == 0){
      Query q;
      q.t = i;
      q.l = rand() % n;
      q.r = rand() % n;
      if (q.l > q.r)
        swap(q.l, q.r);
      vans.push_back(brute(q.l, q.r));
      vq.push_back(q);
    }else{
      Update u;
      u.t = i;
      u.pos = rand() % n;
      u.newV = rand() % 100000;
      u.oldV = curr[u.pos];
      curr[u.pos] = u.newV;
      vu.push_back(u);
    }
  }
  vector<int> vans2 = mo_s_algorithm(vq, vu);
  assert(vans == vans2);
}
int main(){
  for(int i=0; i<10; i++)
    testMo();
  
  return 0;
}