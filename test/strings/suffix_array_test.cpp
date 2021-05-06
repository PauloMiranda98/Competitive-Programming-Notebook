#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef pair<int, int> pii;
vector<int> sort_cyclic_shifts(vector<int> &v) {
  int n = v.size();
  const int alphabet = n+1;
  vector<int> p(n), c(n), cnt(alphabet, 0);
  for(int i = 0; i < n; i++) 
    cnt[v[i]]++;
  for(int i = 1; i < alphabet; i++)
    cnt[i] += cnt[i-1];
  for(int i = 0; i < n; i++)
    p[--cnt[v[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for(int i = 1; i < n; i++) {
    if(v[p[i]] != v[p[i-1]])
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
vector<int> sa_construction(vector<int> v) {
  auto aux = v;
  sort(all(aux));
  for(int &x: v)
    x = (lower_bound(all(aux), x) - aux.begin()) + 1;
  v.push_back(0);
  vector<int> suffix = sort_cyclic_shifts(v);
  suffix.erase(suffix.begin());
  return suffix;
}
// Kasai's algorithm: O(N)
vector<int> lcp_construction(vector<int> const& v, vector<int> const& suf) {
  int n = v.size();
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
    while (i + k < n && j + k < n && v[i+k] == v[j+k])
      k++;
    lcp[rank[i]] = k;
    if (k) k--;
  }
  return lcp;
}
// (ss[i] = k) --> {s[i..k], s[i..k+1], ..., s[i..n-1]}
vector<int> getDistinctSubstrings(vector<int> &v){
  int n = v.size();
  auto suf = sa_construction(v);
  auto lcp = lcp_construction(v, suf);
  vector<int> ss(n);
  ss[suf[0]] = suf[0] + 0;
  for(int i=1; i<n; i++)
    ss[suf[i]] = suf[i] + lcp[i-1];
  return ss;
}

string s;
int lcpBruteForce(int i, int j){
  int n = s.size();
  int ans = 0;
  while(i<n and j<n and s[i] == s[j]){
    i++; 
    j++;
    ans++;
  }
  return ans;
}

void test1(){
  srand(2020);
  int n = 1000;
  s.resize(n);
  for(int i=0; i<n; i++)
    s[i] = 'a' + (rand()%26);

  //Test SA
  vector<int> v(n);
  for(int i=0; i<n; i++)
    v[i] = s[i];
  auto sa = sa_construction(v);
  vector<int> sa2(n);
  iota(sa2.begin(), sa2.end(), 0);
  sort(sa2.begin(), sa2.end(), [&](int i, int j){
    return s.substr(i) < s.substr(j);
  });
  assert(sa == sa2);

  //Test LCP
  auto lcp = lcp_construction(v, sa);
  for(int i=0; i<n-1; i++)
    assert(lcp[i] == lcpBruteForce(sa[i], sa[i+1]));
}

void test2(){ //AC: https://codeforces.com/gym/102700/problem/B
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  vector<int> v1(n), v2(m);
  for(int i=0; i<n; i++)
    v1[i] = a[i];
  for(int i=0; i<m; i++)
    v2[i] = b[i];
  
  auto s1 = sa_construction(v1);
  auto s2 = sa_construction(v2);
  string ans;

  int i=s1[n-1], j=s2[m-1];
  ans += a[i++];
  while(i<n and a[i]>=b[j]){
    ans += a[i++];
  }
  while(j<m)
    ans += b[j++];
  cout << ans << endl;  
}
int main() {
  for(int i=0; i<5; i++)
    test1();
//  test2();
  return 0;
}
