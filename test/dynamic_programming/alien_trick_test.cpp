#include "../../code/dynamic_programming/alien_trick.h"

const int MAXN = 1000010;
pll dp[MAXN][2];
vector<ll> v;
int n;

pll solveDP(ll C){
  //Case base
  dp[n][0] = pll(0, 0);
  dp[n][1] = pll(0, 0);
  for(int i=n-1; i>=0; i--){
    { //Close
      pll op1 = dp[i+1][false];
      
      pll op2 = dp[i+1][true];
      op2.F += (v[i] - C);
      op2.S -= 1;
      dp[i][false] = max(op1, op2);
    }
    { // Open
      pll op1 = dp[i][false];
    
      pll op2 = dp[i+1][true];
      op2.F += v[i];
      dp[i][true] = max(op1, op2);
    }
  }
  pll ans = dp[0][false];
  ans.S = -ans.S;
  return ans;
}

void test(){
  // Case 01
  n = 6;
  v = {1, -2, 3, -4, 5, -6};
  assert(solveMax(4) == 9);

  // Case 02
  n = 9;
  v = {1, 5, -3, 4, -10, 1, 2, -4, 1};
  assert(solveMax(2) == 10);
  
  // Case 03
  n = 5;
  v = {-10, -20, -30, -40, -50};
  assert(solveMax(2) == 0);
  
  assert(true); // AC: https://neps.academy/exercise/484
}

int main() {
  test();
  return 0;
}
