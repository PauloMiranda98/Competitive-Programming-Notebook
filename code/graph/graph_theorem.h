#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
namespace GraphTheorem{
  // return if a sequence of integers d can be represented as the 
  // degree sequence of a finite simple graph on n vertices
  bool ErdosGallai(vector<int> d){
    int n = d.size();
    sort(all(d), greater<int>());
    ll sum1 = 0, sum2 = 0;
    int mn = n-1;
    for(int k=1; k<=n; k++){
      sum1 += d[k-1];
      while(k <= mn and k > d[mn])
        sum2 += d[mn--];
      if(mn + 1 < k)
        sum2 -= d[mn++];
      ll a = sum1, b = k*(ll)mn + sum2;
      if(a > b)
        return false;
    }
    return sum1%2 == 0;
  }
};