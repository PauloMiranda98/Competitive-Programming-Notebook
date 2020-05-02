#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SuffixAutomaton{
  struct state{
    int len, link, first_pos;
    bool is_clone = false;
    map<char, int> next;
  };
  vector<state> st;
  int sz, last;
  SuffixAutomaton(string s){
    st.resize(2 * s.size() + 10);
    st[0].len = 0;
    st[0].link = -1;
    st[0].is_clone = false;
    sz = 1;
    last = 0;
    for (char c : s)
      insert(c);
    preCompute();
  }
  void insert(char c){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].first_pos = st[cur].len - 1;
    st[cur].is_clone = false;
    int p = last;
    while (p != -1 && !st[p].next.count(c)){
      st[p].next[c] = cur;
      p = st[p].link;
    }
    if (p == -1){
      st[cur].link = 0;
    }else{
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len){
        st[cur].link = q;
      }else{
        int clone = sz++;
        st[clone].len = st[p].len + 1;
        st[clone].next = st[q].next;
        st[clone].link = st[q].link;
        st[clone].first_pos = st[q].first_pos;
        st[clone].is_clone = true;
        while (p != -1 && st[p].next[c] == q){
          st[p].next[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
  string lcs(string s){
    int v = 0, l = 0, best = 0, bestpos = 0;
    for (int i = 0; i < (int)s.size(); i++){
      while (v and !st[v].next.count(s[i])){
        v = st[v].link;
        l = st[v].len;
      }
      if (st[v].next.count(s[i])){
        v = st[v].next[s[i]];
        l++;
      }
      if (l > best){
        best = l;
        bestpos = i;
      }
    }
    return s.substr(bestpos - best + 1, best);
  }
  vector<ll> dp;
  vector<int> cnt;
  ll dfsPre(int s){
    if (dp[s] != -1)
      return dp[s];
    dp[s] = cnt[s]; //Accepts repeated substrings
    //dp[s] = 1; //Does not accept repeated substrings
    for (auto p : st[s].next)
      dp[s] += dfsPre(p.second);
    return dp[s];
  }
  void preCompute(){
    cnt.assign(sz, 0);
    vector<pair<int, int>> v(sz);
    for (int i = 0; i < sz; i++){
      cnt[i] = !st[i].is_clone;
      v[i] = make_pair(st[i].len, i);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = 0; i < sz - 1; i++)
      cnt[st[v[i].second].link] += cnt[v[i].second];
    dp.assign(sz, -1);
    dfsPre(0);
  }
};