#include "../../code/miscellaneous/simplex.h"

bool equal(ld x, ld y){
  return abs(x-y) <= EPS;
}

void test1(){
  //int n = 3; 
  //int m = 4;
  vd _c = {4,8,12};
  vvd _a = {{1,1,0},
            {0,2,1},
            {1,1,-2},
            {-2,0,7}};
  vd _b = {10, 15, 20, 5};
  /*
  MAXIMIZE:
    Z = 4*X1 + 8*X2 + 12*X3
  SUBJECT TO:
    1*X1 + 1*X2 + 0*X3 <= 10
    0*X1 + 2*X2 + 1*X3 <= 15
    1*X1 + 1*X2 - 2*X3 <= 20
   -2*X1 + 0*X2 + 7*X3 <= 5
  EXPECTED RESULT:
    Z = 86.666666666667
    X0 = 3.333333333333
    X1 = 6.666666666667
    X2 = 1.666666666667
  */
  LPSolver solver(_a, _b, _c);
  vd x;
  ld value = solver.Solve(x);
  
  assert(equal(value, 86.666666666667));
  assert(equal(x[0], 3.333333333333));
  assert(equal(x[1], 6.666666666667));
  assert(equal(x[2], 1.666666666667));
  solver.clear();
}

void test2(){
  //int n = 3; 
  //int m = 4;
  vd _c = {4,8,12};
  vvd _a = {{1,1,0},
            {0,2,1},
            {1,1,-2},
            {-2,0,7}};
  vd _b = {-10, 15, 20, 5};
  /*
  MAXIMIZE:
    Z = 4*X1 + 8*X2 + 12*X3
  SUBJECT TO:
    1*X1 + 1*X2 + 0*X3 <= -10
    0*X1 + 2*X2 + 1*X3 <= 15
    1*X1 + 1*X2 - 2*X3 <= 20
   -2*X1 + 0*X2 + 7*X3 <= 5
  EXPECTED RESULT:
    infeasible
  */
  LPSolver solver(_a, _b, _c);
  vd x;
  ld value = solver.Solve(x);
  
  assert(value == -numeric_limits<ld>::infinity());
  solver.clear();
}

void test3(){
  //int n = 3; 
  //int m = 4;
  vd _c = {4,8,12};
  vvd _a = {{1,1,0},
            {0,2,0},
            {1,1,0},
            {-2,0,0}};
  vd _b = {10, 15, 20, 5};
  /*
  MAXIMIZE:
    Z = 4*X1 + 8*X2 + 0*X3
  SUBJECT TO:
    1*X1 + 1*X2 + 0*X3 <= 10
    0*X1 + 2*X2 + 0*X3 <= 15
    1*X1 + 1*X2 - 0*X3 <= 20
   -2*X1 + 0*X2 + 0*X3 <= 5
  EXPECTED RESULT:
    unbounded
  */
  LPSolver solver(_a, _b, _c);
  vd x;
  ld value = solver.Solve(x);
  
  assert(value == numeric_limits<ld>::infinity());
  solver.clear();
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
