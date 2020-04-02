#include <bits/stdc++.h>
using namespace std;
int C(int i, int j);
const int MAXN = 100010;
const int MAXK = 110;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXK];
void calculateDP(int l, int r, int k, int opt_l, int opt_r){
  if (l > r)
    return;
  int mid = (l + r) >> 1;
  int ans = -INF, opt;
  for (int i = opt_l; i <= min(opt_r, mid - 1); i++){
    if (ans < dp[i][k - 1] + C(i + 1, mid)){
      opt = i;
      ans = dp[i][k - 1] + C(i + 1, mid);
    }
  }
  dp[mid][k] = ans;
  calculateDP(l, mid - 1, k, opt_l, opt);
  calculateDP(mid + 1, r, k, opt, opt_r);
}
int solve(int n, int k){
  for (int i = 0; i <= n; i++)
    dp[i][0] = -INF;
  for (int j = 0; j <= k; j++)
    dp[0][j] = -INF;
  dp[0][0] = 0;
  for (int j = 1; j <= k; j++)
    calculateDP(1, n, j, 0, n - 1);
  return dp[n][k];
}
