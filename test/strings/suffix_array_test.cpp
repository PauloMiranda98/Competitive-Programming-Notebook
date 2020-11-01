#include "../../code/strings/suffix_array.h"

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
  auto sa = sa_construction(s);
  vector<int> sa2(n);
  iota(sa2.begin(), sa2.end(), 0);
  sort(sa2.begin(), sa2.end(), [&](int i, int j){
    return s.substr(i) < s.substr(j);
  });
  assert(sa == sa2);

  //Test LCP
  auto lcp = lcp_construction(s, sa);
  for(int i=0; i<n-1; i++)
    assert(lcp[i] == lcpBruteForce(sa[i], sa[i+1]));
}

void test2(){ //AC: https://codeforces.com/gym/102700/problem/B
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();

  auto s1 = sa_construction(a);
  auto s2 = sa_construction(b);
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