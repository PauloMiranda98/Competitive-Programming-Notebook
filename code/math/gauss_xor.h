#include <bits/stdc++.h>
using namespace std;
const int MAXB = 30;
struct GaussXOR {
  int table[MAXB];
  GaussXOR() {
    for(int i = 0; i < MAXB; i++) {
      table[i] = 0;
    }
  }
  int size() {
    int ans = 0;
    for(int i = 0; i < MAXB; i++) {
      if(table[i]) ans++;
    }
    return ans;
  }
  bool isComb(int x) {
    for(int i = MAXB-1; i >= 0; i--) {
      x = std::min(x, x ^ table[i]);
    }
    return x == 0;
  }
  void add(int x) {
    for(int i = MAXB-1; i >= 0; i--) {
      if((table[i] == 0) and ((x>>i) & 1)){
        table[i] = x;
        x = 0;
      } else {
        x = std::min(x, x ^ table[i]);
      }
    }
  }
  int max(){
    int ans = 0;
    for(int i = MAXB-1; i >= 0; i--) {
      ans = std::max(ans, ans ^ table[i]);
    }
    return ans;
  }
};
