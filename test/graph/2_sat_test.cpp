#include "../../code/graph/2_sat.h"
typedef pair<int, int> pii;
//(A) = (0)
//(B) = (1)
//(C) = (2)
const int A=0, B=1, C=2;

void test(){  
  //(A v B) ^ (~A v ~C) ^ (B v C)
  SAT sat(3);
  sat.addOr(A, B);
  sat.addOr(~A, ~C);
  sat.addOr(B, C);
  vector<bool> vans = sat.solve2SAT();
  bool ans = true;
  ans &= (vans[A] | vans[B]);
  ans &= ((!vans[A]) | (!vans[C]));
  ans &= (vans[B] | vans[C]);
  assert(ans);
}
int main(){
  test();
  return 0;
}