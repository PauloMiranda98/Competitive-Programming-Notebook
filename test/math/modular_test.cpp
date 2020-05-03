#include "../../code/math/modular.h"
void testDiv(){
  for(int a=1; a<=1000; a++)
    for(int b=1; b<=1000; b++)
      assert( modMul(modDiv(a,b), b) == a);
}
int main(){
  testDiv();
  return 0;
}