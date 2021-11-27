#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Largest Rectangular Area in a Histogram
ll histogram(vector<int> v){
  int n = v.size();
  v.push_back(0);
  ll ans = 0;
  stack<int> st;
  for(int i = 0; i<=n; i++){
    while(st.size() && v[st.top()] >= v[i]){
      int idx = st.top(); st.pop();
      int L = st.size() ? st.top() : -1;
      ans = max(ans, (i-L-1) * (ll)v[idx]);
    }
    st.push(i);
  }
  return ans;
}

// Largest Rectangular Area formed only by 1
int maxArea1(vector<vector<bool>> mat){
  int n = mat.size();
  if(n == 0)
    return 0;
  int m = mat[0].size();
  vector<int> v(m, 0);
  int ans = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mat[i][j])
        v[j]++;
      else
        v[j] = 0;
    }
    ans = max(ans, (int)histogram(v));
  }
  return ans;
}