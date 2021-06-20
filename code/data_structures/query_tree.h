#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Query; // Anything that can be activated for a period of time
int n;
int getAnswer();
void rollback(int t);
void insert(Query q);
int getLastVersion();
namespace QueryTree{
  const int MAXN = 200010;
  vector<Query> queries[4*MAXN];
  int T;
  void addQuery(int node, int i, int j, int a, int b, Query &q){
    if ((i > b) or (j < a))
      return;
    if (a <= i and j <= b){
      queries[node].push_back(q);
      return;
    }
    int m = (i + j) / 2;
    int l = (node << 1);
    int r = l + 1;
    addQuery(l, i, m, a, b, q); 
    addQuery(r, m + 1, j, a, b, q);
  }
  void dfs(int node, int i, int j, vector<int> &ans){
    int lastTime = getLastVersion();
    for(Query q: queries[node])
      insert(q);
    if( i == j){
      ans[i] = getAnswer();
    }else{
      int m = (i + j) / 2;
      int l = (node << 1);
      int r = l + 1;
      dfs(l, i, m, ans); 
      dfs(r, m + 1, j, ans);
    }
    rollback(lastTime);
  }
  // Public:
  void init(int tMax){
    T = tMax;
    for(int i=0; i<=T; i++)
      queries[i].clear();
  }
  void addQuery(int l, int r, Query q){
    addQuery(1, 0, T, l, r, q);
  }
  vector<int> solve(){
    vector<int> ans(T+1);
    dfs(1, 0, T, ans);
    return ans;
  }
};
