#include "../../code/data_structures/merge_sort_tree.h"

const int MAXN = 5010;
int v[MAXN];
int bruteForceEq(int l, int r, int k){
  int ans = 0;
  for(int i=l; i<=r; i++)
    ans += (v[i]==k);
  return ans;
}
int bruteForceLt(int l, int r, int k){
  int ans = 0;
  for(int i=l; i<=r; i++)
    ans += (v[i]<k);
  return ans;
}
void test1(){
  srand(98);
  for(int i=0; i<MAXN; i++)
    v[i] = rand()%50;
  MergeSortTree mst(v, v+MAXN);
  for(int i=0; i<MAXN; i++){
    int l = rand()%MAXN;
    int r = rand()%MAXN;
    int k = rand()%50;
    if(l > r)
      swap(l, r);
    assert(mst.lt(l, r, k) == bruteForceLt(l, r, k));
    assert(mst.eq(l, r, k) == bruteForceEq(l, r, k));
  }
  assert(true);// AC: https://www.spoj.com/problems/MKTHNUM/
}
int main() {
  for(int i=0; i<5; i++)
    test1();
  return 0;
}
