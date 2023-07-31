#include <bits/stdc++.h>
using namespace std;
//Source: https://codeforces.com/blog/entry/61306
typedef long long ll;
const int MOD = 104857601;
// Work only to prime MOD
namespace LinearSeq{
  const int MAXN = 233333;
  ll fastPow(ll a,ll b){
    ll x=1; a%=MOD;
    while(b){
      if(b&1) x=(x*a)%MOD;
      a=(a*a)%MOD; b>>=1;
    }
    return x;
  }  
  inline vector<int> BM(vector<int> x){
    vector<int> ls,cur;
    int lf = 0, ld = 0;
    for(int i=0; i<int(x.size()); i++){
      ll t=0;
      for(int j=0;j<int(cur.size());++j)
        t=(t+x[i-j-1]*(ll)cur[j])%MOD;
      if((t-x[i])%MOD==0) continue;
      if(!cur.size()){
        cur.resize(i+1);
        lf=i; ld=(t-x[i])%MOD;
        continue;
      }
      ll k = -(x[i]-t)*fastPow(ld,MOD-2)%MOD;
      vector<int> c(i-lf-1);
      c.push_back(k);
      for(int j=0;j<int(ls.size());++j)
        c.push_back(-ls[j]*k%MOD);
      if(c.size()<cur.size()) c.resize(cur.size());
      for(int j=0;j<int(cur.size());++j)
        c[j]=(c[j]+cur[j])%MOD;
      if(i-lf+(int)ls.size()>=(int)cur.size())
        ls=cur,lf=i,ld=(t-x[i])%MOD;
      cur=c;
    }
    for(int i=0;i<int(cur.size());++i)
      cur[i]=(cur[i]%MOD+MOD)%MOD;
    return cur;
  }
  int m;
  ll a[MAXN], h[MAXN], t2[MAXN], s[MAXN], t[MAXN];
  inline void mull(ll*p, ll*q){
    for(int i=0;i<m+m;++i) t2[i]=0;
    for(int i=0;i<m;++i) if(p[i])
      for(int j=0;j<m;++j)
        t2[i+j]=(t2[i+j]+p[i]*q[j])%MOD;
    for(int i=m+m-1;i>=m;--i) if(t2[i])
      for(int j=m-1;~j;--j)
        t2[i-j-1]=(t2[i-j-1]+t2[i]*h[j])%MOD;
    for(int i=0;i<m;++i) p[i]=t2[i];
  }
  inline ll calc(ll K){
    for(int i=m; ~i; --i)
      s[i]=t[i]=0;
    //init
    s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
    while(K){
      if(K&1) mull(s,t);
      mull(t,t); K>>=1;
    }
    ll su=0;
    for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
    return (su%MOD+MOD)%MOD;
  }
  // Public: 
  // O(MAXN + |x|^2 * log(N))
  inline int findElementInPositionN(vector<int> x, ll n){
    if(n<int(x.size())) return x[n];
    vector<int> v=BM(x); m=v.size(); if(!m) return 0;
    for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
    return calc(n);
  }
}
