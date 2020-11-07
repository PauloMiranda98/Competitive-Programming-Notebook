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