#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int K = 26;
inline int getID(char c){
  return c-'a';
}
namespace Aho{
  struct Vertex {
    int next[K], go[K];
    int leaf = -1; // CAUTION with repeated strings!
    int p = -1, sz, match=-1;
    char pch;
    int suff_link = -1;
    int end_link = -1;
    Vertex(int p1=-1, char ch1='$', int sz1=0) : p(p1), pch(ch1){
      fill(begin(next), end(next), -1);
      fill(begin(go), end(go), -1);
      sz = sz1;
    }
  };
  vector<Vertex> trie;
  void init(){
    trie.clear();
    trie.emplace_back();
  }
  int add_string(string const& s, int id=1) {
    int v = 0;
    for (char ch : s) {
      int c = getID(ch);
      if (trie[v].next[c] == -1) {
        trie[v].next[c] = trie.size();
        trie.emplace_back(v, ch, trie[v].sz+1);
      }
      v = trie[v].next[c];
    }
    trie[v].leaf = id;
    return v;
  }
  int go(int v, char ch);
  int get_suff_link(int v) {
    if (trie[v].suff_link == -1) {
      if (v == 0 || trie[v].p == 0)
        trie[v].suff_link = 0;
      else
        trie[v].suff_link = go(get_suff_link(trie[v].p), trie[v].pch);
    }
    return trie[v].suff_link;
  }
  int get_end_link(int v) {
    if (trie[v].end_link == -1) {
      if (v == 0 || trie[v].p == 0){
        trie[v].end_link = 0;
      }else{
        int suff_link = get_suff_link(v);
        if(trie[suff_link].leaf != -1)
          trie[v].end_link = suff_link;
        else
          trie[v].end_link = get_end_link(suff_link);
      }
    }
    return trie[v].end_link;
  }
  int go(int v, char ch) {
    int c = getID(ch);
    if (trie[v].go[c] == -1) {
      if (trie[v].next[c] != -1)
        trie[v].go[c] = trie[v].next[c];
      else
        trie[v].go[c] = (v == 0) ? 0 : go(get_suff_link(v), ch);
    }
    return trie[v].go[c];
  }
};
//Aplication:
typedef pair<int, int> pii;
void addMatch(vector<pii> &ans, int v, int i){
  // This runs at most sqrt(N) times:1+2+3+4+..+sqrt(N)=N
  while(v != 0){ 
    // The string id is Aho::trie[v].leaf
    ans.emplace_back(i - Aho::trie[v].sz + 1, i);
    v = Aho::get_end_link(v);
  }
}
//Get match positions: O(answer) = O(N * sqrt(N))
vector<pii> whatMatch(string t){
  int state = 0;
  int i=0;
  vector<pii> ans;
  for(char c : t){
    state = Aho::go(state, c);
    if(Aho::trie[state].leaf != -1)
      addMatch(ans, state, i);
    else
      addMatch(ans, Aho::get_end_link(state), i);
    i++;
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int countMatch(int v){
  if(Aho::trie[v].match == -1) {
    if (v == 0 || Aho::trie[v].p == 0){
      if(Aho::trie[v].leaf != -1)
        Aho::trie[v].match = 1;
      else
        Aho::trie[v].match = 0;
    }else{
      if(Aho::trie[v].leaf != -1)
        Aho::trie[v].match = 1 + countMatch(Aho::get_end_link(v));
      else
        Aho::trie[v].match = countMatch(Aho::get_end_link(v));
    }
  }
  return Aho::trie[v].match;
}
//Get match amount: O(t)
long long matchAmount(string t){
  int state = 0;
  long long ans = 0;
  for(char c : t){
    state = Aho::go(state, c);
    ans += countMatch(state);
  }
  return ans;
}