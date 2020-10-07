#include <bits/stdc++.h>
using namespace std;
class SegTreeIterative{
private:
  typedef long long Node;
  Node neutral = 0;
  vector<Node> st;
  int n;
  inline Node join(Node a, Node b){
    return a + b;
  }
public:
  template <class MyIterator>
  SegTreeIterative(MyIterator begin, MyIterator end){
    int sz = end - begin;
    for (n = 1; n < sz; n <<= 1);
    st.assign(n << 1, neutral);
    for (int i = 0; i < sz; i++, begin++)
      st[i + n] = (*begin);
    for (int i = n - 1; i > 1; i--){
      st[i] = join(st[(i << 1)], st[(i << 1) + 1]);
    }
  }
  //0-indexed
  void update(int i, Node x){
    st[i += n] = x;
    for (i >>= 1; i; i >>= 1)
      st[i] = join(st[i << 1], st[(i << 1) + 1]);
  }
  //0-indexed [l, r]
  Node query(int l, int r){
    Node ansL = neutral, ansR = neutral;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
      if (l & 1)
        ansL = join(ansL, st[l++]);
      if (r & 1)
        ansR = join(st[--r], ansR);
    }
    return join(ansL, ansR);
  }
  Node lower_bound(int k){
    int no=1, l=0, r=n-1;
    while(l<r){
      int mid = (l+r)>>1;
      int lo = no<<1;
      if(st[lo] >= k){
        no = lo;
        r = mid;
      }else{
        k -= st[lo];
        no = lo + 1;
        l = mid + 1;
      }
    }
    if(st[no] >= k)
      return l;
    else
      return -1;
  }
};