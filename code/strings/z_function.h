#include <bits/stdc++.h>
using namespace std;
// z[i] is the length of the longest common prefix between s[0..(n-1)] and the suffix of s[i..(n-1)].
// z[0] is generally not well defined.
// "aaabaab" - [0,2,1,0,2,1,0]
// "abacaba" - [0,0,1,0,3,0,1]
vector<int> z_function(string s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++){
    if (i <= r)
      z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}
