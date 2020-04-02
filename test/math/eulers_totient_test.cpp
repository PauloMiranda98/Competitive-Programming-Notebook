#include "../../code/math/eulers_totient.h"
#include <bits/stdc++.h>
using namespace std;
void testNthPhi(){
  int phi[24] = {0, 1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8, 8, 16, 6, 18, 8, 12, 10, 22};
  for (int i = 0; i < 24; i++)
    assert(phi[i] == nthPhi(i));
}
void testPhiFrom1ToN(){
  int N = 10000;
  vector<int> phi = phiFrom1toN(N);
  for (int i = 0; i <= N; i++)
    assert(phi[i] == nthPhi(i));
}
int main(){
  testNthPhi();
  testPhiFrom1ToN();
  return 0;
}