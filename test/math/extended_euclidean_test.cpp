#include "../../code/math/extended_euclidean.h"
void testExtEuclidean(){
  for(ll a=-100; a<=100; a++){
    for(ll b=-100; b<=100; b++){
      ll x, y;
      ll g = extGcd(a, b, x, y);
      assert(a*x + b*y == g);
    }  
  }
}
int main(){
  testExtEuclidean();
  return 0;
}