#include "../../code/math/fraction.h"
void testFraction(){
  Fraction a, b;
  a = {1, 3};
  b = {2, 3};
  assert(a+b == Fraction(1, 1));
  assert(a-b == Fraction(-1, 3));
  assert(b-a == Fraction(1, 3));
  assert(a*b == Fraction(2, 9));
  assert(a/b == Fraction(1, 2));

  a = {5, 3};
  b = {3, 3};
  assert(a+b == Fraction(8, 3));
  assert(a-b == Fraction(2, 3));
  assert(b-a == Fraction(-2, 3));
  assert(a*b == Fraction(15, 9));
  assert(a/b == Fraction(5, 3));

  a = {5, 3};
  b = {3, 2};
  assert(a+b == Fraction(19, 6));
  assert(a-b == Fraction(1, 6));
  assert(b-a == Fraction(-1, 6));
  assert(a*b == Fraction(15, 6));
  assert(a/b == Fraction(10, 9));
}

int main(){
  testFraction();
  return 0;
}
