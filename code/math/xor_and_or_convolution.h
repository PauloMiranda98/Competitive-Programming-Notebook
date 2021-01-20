#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void xorFWHT(vector<ll> &P, bool inverse=false){
  int n = P.size();
  for(int len = 1; 2 * len <= n; len <<= 1){
    for(int i = 0; i < n; i += 2 * len){
      for(int j = 0; j < len; j++){
        ll u = P[i + j];
        ll v = P[i + len + j];
        P[i + j] = u + v;
        P[i + len + j] = u - v;
      }
    }
  }
  if(inverse){
    for (int i = 0; i < n; i++){
      P[i] /= n;
    }
  }
}
void orFWHT(vector<ll> &P, bool inverse=false){
  int n = P.size();
  for(int len = 1; 2 * len <= n; len <<= 1){
    for(int i = 0; i < n; i += 2 * len){
      for(int j = 0; j < len; j++){
        if(inverse)
          P[i + len + j] -= P[i + j];
        else
          P[i + len + j] += P[i + j];
      }
    }
  }
}
void andFWHT(vector<ll> &P, bool inverse=false){
  int n = P.size();
  for(int len = 1; 2 * len <= n; len <<= 1){
    for(int i = 0; i < n; i += 2 * len){
      for(int j = 0; j < len; j++){
        ll u = P[i + j];
        ll v = P[i + len + j];
        if(inverse){
          P[i + j] = v - u;
          P[i + len + j] = u;
        }else{
          P[i + j] = v;
          P[i + len + j] = u + v;
        }
      }
    }
  }
}
vector<ll> convolution(vector<ll> a, vector<ll> b){
  int mx = max(a.size(), b.size());
  int n = 1;
  while(n < mx) 
    n <<= 1;
  a.resize(n, 0); b.resize(n, 0);
  xorFWHT(a); xorFWHT(b);
  for(int i=0; i<n; i++)
    a[i] *= b[i];
  xorFWHT(a, true);
  return a;
}