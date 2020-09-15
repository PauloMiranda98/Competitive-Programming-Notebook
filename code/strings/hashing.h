#include <bits/stdc++.h>
using namespace std;
struct StringHashing{
  const uint64_t MOD = (1ll<<61) - 1;
  const int base = 31;
  const uint64_t invBase = 2231460976658413501uLL; //31^-1 % MOD
  uint64_t modMul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
    uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
    uint64_t ret = (l&MOD) + (l>>61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
    ret = (ret & MOD) + (ret>>61);
    ret = (ret & MOD) + (ret>>61);
    return ret-1;
  }
  int getInt(char c){
    return c-'a'+1;
  }
  vector<uint64_t> pre, p, inv;
//Public:
  StringHashing(string s){
    int n = s.size();
    pre.resize(n); 
    p.resize(n);
    inv.resize(n);
    p[0] = 1;
    inv[0] = 1;
    pre[0] = getInt(s[0]);
    for(int i=1; i<n; i++){
      p[i] = modMul(p[i-1], base);
      inv[i] = modMul(inv[i-1], invBase);
      pre[i] = (pre[i-1] + modMul(p[i], getInt(s[i])))%MOD;
    }    
  }
  uint64_t getValue(int i, int j){
    return modMul(inv[i], (pre[j] - ((i>0)?pre[i-1]:0) + MOD)%MOD);
  }
};
