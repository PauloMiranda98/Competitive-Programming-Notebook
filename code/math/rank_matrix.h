#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld EPS = 1e-9;
int compute_rank(vector<vector<ld>> A) {
  int n = A.size();
  int m = A[0].size();
  int rank = max(n, m);
  vector<bool> row_selected(n, false);
  for (int i = 0; i < m; ++i) {
    int j;
    for (j = 0; j < n; ++j) {
      if (!row_selected[j] && abs(A[j][i]) > EPS)
        break;
    }
    if (j == n) {
      rank--;
    } else {
      row_selected[j] = true;
      for (int p = i + 1; p < m; p++)
        A[j][p] /= A[j][i];
      for (int k = 0; k < n; k++) {
        if (k != j && abs(A[k][i]) > EPS) {
          for (int p = i + 1; p < m; p++)
            A[k][p] -= A[j][p] * A[k][i];
        }
      }
    }
  }
  return rank;
}
