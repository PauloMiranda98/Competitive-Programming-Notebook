#include <bits/stdc++.h>
using namespace std;
namespace WaveletTree{
  const int MAXN = 100010, MAXW = MAXN*30; // MAXN * LOG(maxX-MinX)
  typedef int t_wavelet;
  int last;
  int v[MAXN], aux[MAXN];
  int lo[MAXW], hi[MAXW], l[MAXW], r[MAXW];
  vector<t_wavelet> a[MAXW];
  int stable_partition(int i, int j, t_wavelet mid){
    int pivot=0;
    for(int k=i; k<j; k++)
      aux[k] = v[k], pivot += (v[k]<=mid);
    int i1=i, i2=i+pivot;
    for(int k=i; k<j; k++){
      if(aux[k]<=mid) v[i1++] = aux[k];
      else v[i2++] = aux[k];
    }
    return i1;
  }
  void build(int u, int i, int j, t_wavelet minX, t_wavelet maxX){
    lo[u] = minX, hi[u] = maxX;
    if (lo[u] == hi[u] or i >= j)
      return;
    t_wavelet mid = (minX + maxX - 1)/2;
    a[u].resize(j - i + 1);
    a[u][0] = 0;
    for(int k=i; k<j; k++)
      a[u][k-i+1] = a[u][k-i] + (v[k] <= mid);
    int pivot = stable_partition(i, j, mid);
    l[u] = last++, r[u] = last++;
    build(l[u], i, pivot, minX, mid);
    build(r[u], pivot, j, mid + 1, maxX);
  }
  inline int b(int u, int i){
    return i - a[u][i];
  }
//Public  
  template <class MyIterator>
  void init(MyIterator begin, MyIterator end, t_wavelet minX, t_wavelet maxX){
    last = 1;
    int n = end-begin;
    for(int i=0; i<n; i++, begin++)
      v[i] = *begin;
    build(last++, 0, n, minX, maxX);
  }
  //kth smallest element in range [i, j]
  //1-indexed
  int kth(int i, int j, int k, int u=1){
    if (i > j)
      return 0;
    if (lo[u] == hi[u])
      return lo[u];
    int inLeft = a[u][j] - a[u][i - 1];
    int i1 = a[u][i - 1] + 1, j1 = a[u][j];
    int i2 = b(u, i - 1) + 1, j2 = b(u, j);
    if (k <= inLeft)
      return kth(i1, j1, k, l[u]);
    return kth(i2, j2, k - inLeft, r[u]);
  }
  //Amount of numbers in the range [i, j] Less than or equal to k
  //1-indexed
  int lte(int i, int j, int k, int u=1){
    if (i > j or k < lo[u])
      return 0;
    if (hi[u] <= k)
      return j - i + 1;
    int i1 = a[u][i - 1] + 1, j1 = a[u][j];
    int i2 = b(u, i - 1) + 1, j2 = b(u, j);
    return lte(i1, j1, k, l[u]) + lte(i2, j2, k, r[u]);
  }
  //Amount of numbers in the range [i, j] equal to k
  //1-indexed
  int count(int i, int j, int k, int u=1){
    if (i > j or k < lo[u] or k > hi[u])
      return 0;
    if (lo[u] == hi[u])
      return j - i + 1;
    t_wavelet mid = (lo[u] + hi[u] - 1) / 2;
    int i1 = a[u][i - 1] + 1, j1 = a[u][j];
    int i2 = b(u, i - 1) + 1, j2 = b(u, j);
    if (k <= mid)
      return count(i1, j1, k, l[u]);
    return count(i2, j2, k, r[u]);
  }
  //swap v[i] with v[i+1]
  //1-indexed
  void swp(int i, int u=1){
    if (lo[u] == hi[u] or a[u].size() <= 2)
      return;
    if (a[u][i - 1] + 1 == a[u][i] and a[u][i] + 1 == a[u][i + 1])
      swp(a[u][i], l[u]);
    else if (b(u, i - 1) + 1 == b(u, i) and b(u, i) + 1 == b(u, i + 1))
      swp(b(u, i), r[u]);
    else if (a[u][i - 1] + 1 == a[u][i])
      a[u][i]--;
    else
      a[u][i]++;
  }
};