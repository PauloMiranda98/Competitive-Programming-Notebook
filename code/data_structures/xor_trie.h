#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Vertex {
  int next[2];
  int leaf;
  int count;
  Vertex() {
    next[0] = next[1] = -1;
    leaf = count = 0;
  }
};
const int MAXB = 20;
struct Trie{
  vector<Vertex> trie;
  ll lazy;
  Trie(){
    trie.emplace_back();
    lazy = 0;
  }
  void add(ll x) {
    int v = 0;
    trie[v].count++;
    for(int i=MAXB; i>=0; i--){
      int c = (x>>i)&1;
      if (trie[v].next[c] == -1) {
        trie[v].next[c] = trie.size();
        trie.emplace_back();
      }
      v = trie[v].next[c];
      trie[v].count++;
    }
    trie[v].leaf++;
  }
  void apply(ll x) {
    lazy ^= x;
  }
  ll min(){
    int v = 0;
    ll ans = 0;
    for(int i=MAXB; i>=0; i--){
      int b = (lazy>>i)&1;
      int to1 = trie[v].next[b];
      int to2 = trie[v].next[b^1];
      if(to1 != -1){
        v = to1;
      }else if(to2 != -1){
        ans |= (1LL<<i);
        v = to2;
      }else{
        return -1;
      }
    }
    return ans;
  }
  ll max(){
    int v = 0;
    ll ans = 0;
    for(int i=MAXB; i>=0; i--){
      int b = (lazy>>i)&1;
      int to1 = trie[v].next[b];
      int to2 = trie[v].next[b^1];
      if(to2 != -1){
        ans |= (1LL<<i);
        v = to2;
      }else if(to1 != -1){
        v = to1;
      }else{
        return -1;
      }
    }
    return ans;
  }
  int countLE(ll x) {
    int v = 0, ans = 0;
    for(int i=MAXB; i>=0; i--){
      int c = (x>>i)&1;
      int b = (lazy>>i)&1;
      if(c == 0){
        if (trie[v].next[c^b] == -1)
          return ans;
        v = trie[v].next[c^b];
      }else{
        int to = trie[v].next[c^b^1];
        if (to != -1)
          ans += trie[to].count;
        
        if (trie[v].next[c^b] == -1)
          return ans;
        v = trie[v].next[c^b];
      }
    }
    ans += trie[v].leaf;
    return ans;
  }
};