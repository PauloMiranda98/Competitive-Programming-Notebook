#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> sort_cyclic_shifts(string const& s) {
  int n = s.size();
  const int alphabet = 256;
  vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
  for(int i = 0; i < n; i++) 
    cnt[s[i]]++;
  for(int i = 1; i < alphabet; i++)
    cnt[i] += cnt[i-1];
  for(int i = 0; i < n; i++)
    p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for(int i = 1; i < n; i++) {
    if(s[p[i]] != s[p[i-1]])
      classes++;
    c[p[i]] = classes - 1;
  }
  vector<int> pn(n), cn(n);
  for(int h = 0; (1 << h) < n; ++h) {
    //Ordenando pelo second no RadixSort
    int h2 = (1 << h);
    for(int i = 0; i < n; i++){ 
      pn[i] = p[i] - h2;
      if(pn[i] < 0) pn[i] += n;
    }
    fill(cnt.begin(), cnt.begin() + classes, 0);
    for(int i = 0; i < n; i++)
      cnt[c[p[i]]]++;
    for(int i = 1; i < classes; i++)
      cnt[i] += cnt[i-1];
    for(int i = n-1; i >= 0; i--)
      p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for(int i = 1; i < n; i++){
      pii cur(c[p[i]], c[(p[i] + h2) % n]);
      pii prev(c[p[i-1]], c[(p[i-1] + h2) % n]);
      if(cur != prev)
        ++classes;
      cn[p[i]] = classes - 1;
    }
    c.swap(cn);
  }
  return p;
}
// O(N*log(N))
vector<int> sa_construction(string s) {
  s += "$";
  vector<int> sorted_shifts = sort_cyclic_shifts(s);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}
// Kasai's algorithm: O(N)
vector<int> lcp_construction(string const& s, vector<int> const& suf) {
  int n = s.size();
  vector<int> rank(n, 0);
  for(int i = 0; i < n; i++)
    rank[suf[i]] = i;
  int k = 0;
  vector<int> lcp(n-1, 0);
  for(int i = 0; i < n; i++){
    if (rank[i] == n - 1) {
      k = 0; continue;
    }
    int j = suf[rank[i] + 1];
    while (i + k < n && j + k < n && s[i+k] == s[j+k])
      k++;
    lcp[rank[i]] = k;
    if (k) k--;
  }
  return lcp;
}