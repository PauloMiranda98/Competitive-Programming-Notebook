#include "../../code/math/gray_code.h"
#include <bits/stdc++.h>
using namespace std;
void testGrayCode(){
  int v[] = {0b000, 0b001, 0b011, 0b010, 0b110, 0b111, 0b101, 0b100};
  for(int i=0; i<8; i++)
    assert(v[i] == grayCode(i));
  for(int i=0; i<8; i++)
    assert(revGrayCode(v[i]) == i);
}
int main(){
  testGrayCode();
  return 0;
}