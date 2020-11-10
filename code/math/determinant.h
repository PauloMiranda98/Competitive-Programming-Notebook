#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld EPS = 1e-9;
ld determinant(vector<vector<ld>> a) {
  int n = a.size();
  ld det = 1;
  for(int i=0; i<n; i++) {
    int b = i;
    for(int j=i+1; j<n; j++)
      if(abs (a[j][i]) > abs (a[b][i]))
        b = j;
    if(abs(a[b][i]) < EPS)
      return 0;
    swap(a[i], a[b]);
    if(i != b)
      det = -det;
    det *= a[i][i];
    for(int j=i+1; j<n; ++j)
      a[i][j] /= a[i][i];
    for(int j=0; j<n; ++j)
      if(j != i && abs (a[j][i]) > EPS)
        for(int k=i+1; k<n; k++)
          a[j][k] -= a[i][k] * a[j][i];
  }
  return det;
}
