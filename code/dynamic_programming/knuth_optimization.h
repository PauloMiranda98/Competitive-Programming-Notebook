#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1009;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
ll C(int a, int b);
ll dp[MAXN][MAXN];
int opt[MAXN][MAXN];
ll knuth(int n){
  for (int i = 0; i < n; i++){
    dp[i][i] = 0;
    opt[i][i] = i;
  }
  for (int s = 1; s < n; s++){
    for (int i = 0, j; (i + s) < n; i++){
      j = i + s;
      dp[i][j] = INFLL;
      for (int k = opt[i][j - 1]; k < min(j, opt[i + 1][j] + 1); k++){
        ll cur = dp[i][k] + dp[k + 1][j] + C(i, j);
        if (dp[i][j] > cur){
          dp[i][j] = cur;
          opt[i][j] = k;
        }
      }
    }
  }
  return dp[0][n - 1];
}