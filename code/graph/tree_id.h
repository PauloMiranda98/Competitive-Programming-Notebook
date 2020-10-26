#include "centroid.h"
#define F first
#define S second
namespace TreeID{
  int id=0;
  map<map<int, int>, int> mpId;
  vector<int> adj[MAXN];
  int treeID(int u, int p){
    map<int, int> mp;
    for(int to: adj[u]){
      if(to != p)
        mp[treeID(to, u)]++;
    }
    if(!mpId.count(mp))
      mpId[mp] = ++id;
    return mpId[mp];
  }
  //Returns a pair of values that represents a tree only. O((N+M)*log(M))
  //0-indexed
  pii getTreeID(vector<pii> &edges, int n){
    for(int i=0; i<n; i++) 
      adj[i].clear();
    Centroid::init(n);
    for(pii e: edges){
      adj[e.F].push_back(e.S);
      adj[e.S].push_back(e.F);
      Centroid::addEdge(e.F, e.S);
    }
    pii c = Centroid::findCentroid();
    pii ans(treeID(c.F, -1), treeID(c.S, -1));
    if(ans.F > ans.S)
      swap(ans.F, ans.S);
    return ans;
  }
  bool isomorphic(vector<pii> &tree1, vector<pii> &tree2, int n){
    return getTreeID(tree1, n) == getTreeID(tree2, n);
  }
};