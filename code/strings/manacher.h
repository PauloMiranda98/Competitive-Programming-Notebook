#include <bits/stdc++.h>
using namespace std;
// source: https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Strings/manacher.cpp
// ret[2*i] = larger size palindrome centered on i
// ret[2*i+1] = larger size palindrome centered on i and i + 1
vector<int> manacher(const string &s) {
  int l = 0, r = -1, n = s.size();
  vector<int> d1(n), d2(n);
  for (int i = 0; i < n; i++) {
    int k = i > r ? 1 : min(d1[l+r-i], r-i);
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) k++;
    d1[i] = k--;
    if (i+k > r) l = i-k, r = i+k;
  }
  l = 0, r = -1;
  for (int i = 0; i < n; i++) {
    int k = i > r ? 0 : min(d2[l+r-i+1], r-i+1); k++;
    while (i+k <= n && i-k >= 0 && s[i+k-1] == s[i-k]) k++;
    d2[i] = --k;
    if (i+k-1 > r) l = i-k, r = i+k-1;
  }
  vector<int> ret(2*n-1);
  for (int i = 0; i < n; i++) ret[2*i] = 2*d1[i]-1;
  for (int i = 0; i < n-1; i++) ret[2*i+1] = 2*d2[i+1];
  return ret;
}
struct Palindrome {
  vector<int> man;
  Palindrome(const string &s) : man(manacher(s)) {}
  bool isPalindrome(int i, int j) {
    return man[i+j] >= j-i+1;
  }
};
