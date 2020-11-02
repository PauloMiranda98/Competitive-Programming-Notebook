#include "../../code/miscellaneous/kadane.h"
void test1(){
  int T = 5;
  srand(2020);
  while(T--){
    int n = 1010;
    vector<ll> v(n);
    for(int i=0; i<n; i++){
      v[i] = (rand()%100) - 50;
    }
    ll ans=0;
    for(int i=0; i<n; i++){
      ll sum = 0;
      for(int j=i; j<n; j++){
        sum += v[j];
        ans = max(ans, sum);
      }
    }
    assert(ans == kadane(v));
  }
}
const int MAXN = 110;
ll pre[MAXN][MAXN];
inline ll aux(int i, int j){
  if(i < 0 or j < 0)
    return 0;
  return pre[i][j];
}
ll sum(int i, int j, int a, int b){
  return aux(a, b) - aux(i-1, b) - aux(a, j-1) + aux(i-1, j-1);
}
void test2(){
  int T = 5;
  srand(2020);
  while(T--){
    int n = 80, m = 60;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        mat[i][j] = (rand()%100) - 50;
        pre[i][j] = aux(i-1, j) + aux(i, j-1) - aux(i-1, j-1) + mat[i][j];
      }
    }
    ll ans=0;
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        for(int a=i; a<n; a++)
          for(int b=j; b<m; b++)
            ans = max(ans, sum(i, j, a, b));
    assert(ans == kadane2d(mat));
  }
}

void test3(){ 
  assert(true); // AC: https://www.urionlinejudge.com.br/judge/pt/problems/view/2921
}

int main() {
  test1();
  test2();
  test3();
  return 0; 
}
