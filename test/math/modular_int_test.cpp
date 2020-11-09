#include "../../code/math/modular_int.h"
void testDiv(){
  for(int a=1; a<=1000; a++){
    for(int b=1; b<=1000; b++){
      modInt a1 = a, b1=b;
      assert((a1/b1)*b1 == a1);
    }
  }
}
int main(){
  testDiv();
  return 0;
}
