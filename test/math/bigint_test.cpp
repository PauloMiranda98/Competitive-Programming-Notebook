#include "../../code/math/bigint.h"
void testBigInt1(){
  BigInt a("1234513244000000032132300000032");
  BigInt b("1324551121513244421211111222332");
  BigInt c = a+b;
  assert(c.to_string() == "2559064365513244453343411222364");
  c = a-b;
  assert(c.to_string() == "-90037877513244389078811222300");
  c = a*b;
  assert(c.to_string() == "1635175901863153601955105325768291916578212950817279159114624");
}
void testBigInt2(){
  BigInt a("1234513244000000032132300000032");
  BigInt b("124551121");
  int b1 = 124551121;
  BigInt c = a*b1;
  assert(c.to_string() == "153760008429546528002113985312285635872");
  c = a/b;
  assert(c.to_string() == "9911699180933104826349");
  c = a/b1;
  assert(c.to_string() == "9911699180933104826349");
  c = a%b;
  assert(c.to_string() == "21712803");
}
int main(){
  testBigInt1();
  testBigInt2();
  return 0;
}