#include "../../code/geometry/nearest_pair_of_points.h"
const double EPS = 1e-4;
void test1(){
  vector<pt> v;
  v.emplace_back(0, 0);
  v.emplace_back(0, 1);
  v.emplace_back(100, 45);
  v.emplace_back(2, 3);
  v.emplace_back(9, 9);
  NearestPairOfPoints::solve(v);
  auto ans = NearestPairOfPoints::mindist;
  assert(abs(ans-1) < EPS);
}
void test2(){
  vector<pt> v;
  v.emplace_back(0, 0);
  v.emplace_back(-4, 1);
  v.emplace_back(-7, -2);
  v.emplace_back(4, 5);
  v.emplace_back(1, 1);
  NearestPairOfPoints::solve(v);
  auto ans = NearestPairOfPoints::mindist;
  assert(abs(ans-1.414214) < EPS);
}
int main(){
  test1();
  test2();
  return 0;
}
