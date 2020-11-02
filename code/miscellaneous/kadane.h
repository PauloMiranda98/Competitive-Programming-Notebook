#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Largest Sum Contiguous Subarray: O(N)
ll kadane(vector<ll> &v){
  ll ans = 0, bigger = 0;
  for(int i=0; i < (int)v.size(); i++){
    bigger = max(0LL, bigger + v[i]);
    ans = max(ans, bigger);
  }
  return ans;
}
// Largest Sum Submatrix: O(N^3)
ll kadane2d(vector<vector<int>> &mat){
  if(mat.size() == 0) return 0;
  int n = mat.size(), m = mat[0].size();
  ll ans = 0;
  vector<ll> v(m);
  for(int a=0; a<n; a++){
    fill(v.begin(), v.end(), 0);
    for(int b=a; b<n; b++){
      for(int k=0; k<m; k++)
        v[k] += mat[b][k];
      ans = max(ans, kadane(v));
    }
  }
  return ans;
}
ll circularKadane(vector<ll> v){
  ll ans1 = kadane(v);
  ll sum = 0;
  for(int i=0; i < (int)v.size(); i++){
    sum += v[i];
    v[i] = -v[i];
  }
  return max(ans1, sum + kadane(v));
}