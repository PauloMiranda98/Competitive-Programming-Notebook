#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
class MergeSortTree{
private:
  typedef vector<int> Node;
  Node neutral;
  vector<Node> st;
  int n;
  inline void join(Node &a, Node &b, Node &ans){
    ans.resize(a.size() + b.size());
    merge(all(a), all(b), ans.begin());
  }
  inline int szEq(int node, int k){
    return upper_bound(all(st[node]), k) - lower_bound(all(st[node]), k);
  }
  inline int szLt(int node, int k){
    return lower_bound(all(st[node]), k) - st[node].begin();
  }
public:
  template <class MyIterator>
  MergeSortTree(MyIterator begin, MyIterator end){
    int sz = end - begin;
    for (n = 1; n < sz; n <<= 1);
    st.assign(n << 1, neutral);
    for (int i = 0; i < sz; i++, begin++)
      st[i + n].assign(1, *begin);
    for (int i = n - 1; i; i--){
      int l = (i << 1); 
      join(st[l], st[l+1], st[i]);
    }
  }
  // 0-indexed
  // Counts the number of elements less than k in the range [L..R]
  int lt(int l, int r, int k){
    int ans = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
      if (l & 1)
        ans += szLt(l++, k);
      if (r & 1)
        ans += szLt(--r, k);
    }
    return ans;
  }
  // 0-indexed
  // Counts the number of elements equal to k in the range [L..R]
  int eq(int l, int r, int k){
    int ans = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
      if (l & 1)
        ans += szEq(l++, k);
      if (r & 1)
        ans += szEq(--r, k);
    }
    return ans;
  }
};
