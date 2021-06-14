#include "segment_tree_persistent.h"
namespace DistinctValues{
  const int MAXN = 200010;
  int v0[MAXN], tmp[MAXN];
  vector<int> upd[MAXN];
  void init(vector<int> v){
    int n = v.size();
    map<int, int> last;
    for(int i=0; i<n; i++){
      int x = v[i];
      upd[last[x]].push_back(i);
      last[x] = i+1;
    }
    PerSegTree::build(n, v0);
    for(int i=0; i<n; i++){
      for(int p: upd[i])
        PerSegTree::update(p, 1);
      tmp[i] = PerSegTree::t;
    }
  }
  // How many distinct values are there in a range [a,b]
  // 0-indexed
  int query(int a, int b){
    return PerSegTree::query(a, b, tmp[a]);
  }
};