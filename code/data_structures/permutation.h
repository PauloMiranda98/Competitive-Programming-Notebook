#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
namespace Permutation{
  const int MAXN = 500010;
  ll mp[MAXN], sumXor[MAXN], p[MAXN+1], inv[MAXN];
  void init(vector<int> v){
    sumXor[0] = inv[0] = p[0] = 0;
    for(int i=0; i<MAXN; i++){
      mp[i] = rng() + 1;
      p[i+1] = p[i] ^ mp[i];
    }
    for(int i=0; i<v.size(); i++){
      if(v[i] < 0 or v[i] >= MAXN){
        inv[i+1] = 1 + inv[i];
        sumXor[i+1] = sumXor[i];
      }else{
        inv[i+1] = inv[i];
        sumXor[i+1] = sumXor[i] ^ mp[v[i]];
      }
    }
  }
  // Verify if {v[l], v[l+1], ..., v[r]} is {0, 1, ... , r-l+1}
  // 0-indexed;
  bool isPermutation(int l, int r){
    l++, r++;
    if(inv[r] - inv[l-1] > 0)
      return false;
    return p[r-l+1] == (sumXor[r] ^ sumXor[l-1]);
  }
};