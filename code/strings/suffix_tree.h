#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
namespace SuffixTree {
const int NS = 60; //Number of strings
const int MAXN = 100010; //Number of letters
int cn, cd, ns, en = 1, lst;
string S[NS]; int lastS = -1;
/* sufn[si][i] no do sufixo S[si][i...] */
vector<int> sufn[NS];
struct Node {
  int l, r, si=0;
  int p, suf=0;
  map<char, int> adj;
  Node() : l(0), r(-1){ suf = p = 0; }
  Node(int l1, int r1, int s1, int p1) : l(l1), r(r1), si(s1), p(p1) {}
  inline int len() { return r - l + 1; }
  inline int operator[](int i) { return S[si][l + i]; }
  inline int& operator()(char c) { return adj[c]; }
};
Node t[2*MAXN];
inline int new_node(int l, int r, int s, int p) {
  t[en] = Node(l, r, s, p);
  return en++;
}
void init(){
  t[0] = Node();
  cn=0, cd=0, ns=0, en = 1, lst=0;
  lastS = -1;  
}
//The strings are inserted independently
void add_string(string s, char id='$') {
  assert(id < 'A');
  s += id;
  S[++lastS] = s;
  sufn[lastS].resize(s.size() + 1);
  cn = cd = 0;
  int i = 0; const int n = s.size();
  for(int j = 0; j < n; j++){
    for(; i <= j; i++) {
      if(cd == t[cn].len() && t[cn](s[j]))
        cn = t[cn](s[j]), cd = 0;
      if(cd < t[cn].len() && t[cn][cd] == s[j]) {
        cd++;
        if(j < (int)s.size() - 1) break;
        else {
          if(i) t[lst].suf = cn;
          for(; i <= j; i++) {
            sufn[lastS][i] = cn;
            cn = t[cn].suf;
          }
        }
      } else if(cd == t[cn].len()) {
        sufn[lastS][i] = en;
        if(i) t[lst].suf = en; 
        lst = en;
        t[cn](s[j]) = new_node(j, n - 1, lastS, cn);
        cn = t[cn].suf;
        cd = t[cn].len();
      } else {
        int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].si, t[cn].p);
        t[t[cn].p](t[cn][0]) = mid;
        if(ns) t[ns].suf = mid;
        if(i) t[lst].suf = en; 
        lst = en;
        sufn[lastS][i] = en;
        t[mid](s[j]) = new_node(j, n - 1, lastS, mid);
        t[mid](t[cn][cd]) = cn;
        t[cn].p = mid; t[cn].l += cd;
        cn = t[mid].p;
        int g = cn? j - cd : i + 1;
        cn = t[cn].suf;
        while(g < j && g + t[t[cn](S[lastS][g])].len() <= j)
          cn = t[cn](S[lastS][g]), g += t[cn].len();
        if(g == j)
          ns = 0, t[mid].suf = cn, cd = t[cn].len();
        else
          ns = mid, cn = t[cn](S[lastS][g]), cd = j - g;
      }
    }
  }
}
bool match(string &s, int i=0, int no=0, int iEdge=0){
  if(i == (int)s.size())
    return true;
  if(iEdge == t[no].len()){ //I arrived at the Node
    if(t[no].adj.count(s[i]))
      return match(s, i+1, t[no].adj[s[i]], 1);
    else
      return false;
  }
  if(t[no][iEdge] == s[i])
    return match(s, i+1, no, iEdge+1);
  return false;
}
typedef tuple<int, int, int> tp;
// O(n), substring <i, l, r> = s[i..l], s[i..l+1], ..., s[i..r]
void getDistinctSubstrings(vector<tp> &v, int no=0, int d=0){
  d += t[no].len() - t[no].adj.empty();
  int l = t[no].l, r = t[no].r - t[no].adj.empty();
  if(l <= r){
    v.emplace_back(r - d + 1, l, r);
  }
  for(auto [x, to]: t[no].adj)
    getDistinctSubstrings(v, to, d);
}
};