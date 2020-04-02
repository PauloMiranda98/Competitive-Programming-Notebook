#include <bits/stdc++.h>
using namespace std;
int nthPhi(int n){
  int result = n;
  for (int i = 2; i <= n / i; i++){
    if (n % i == 0){
      while (n % i == 0)
        n /= i;
      result -= result / i;
    }
  }
  if (n > 1)
    result -= result / n;
  return result;
}
vector<int> phiFrom1toN(int n){
  vector<int> vPhi(n + 1);
  vPhi[0] = 0;
  vPhi[1] = 1;
  for (int i = 2; i <= n; i++)
    vPhi[i] = i;
  for (int i = 2; i <= n; i++){
    if (vPhi[i] == i){
      for (int j = i; j <= n; j += i)
        vPhi[j] -= vPhi[j] / i;
    }
  }
  return vPhi;
}