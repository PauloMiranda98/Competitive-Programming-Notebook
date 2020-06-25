#include "../../code/geometry/convex_hull.h"
void test1(){
  vector<Point2d> v;
  v.emplace_back(0, 0);
  v.emplace_back(10, 0);
  v.emplace_back(0, 10);
  auto ans1 = convex_hull(v);
  vector<Point2d> ans2;
  ans2.emplace_back(0, 0);
  ans2.emplace_back(10, 0);
  ans2.emplace_back(0, 10);
  sort(ans1.begin(), ans1.end());
  sort(ans2.begin(), ans2.end());
  assert(ans1 == ans2);
}
void test2(){
  vector<Point2d> v;
  v.emplace_back(41, -6);
  v.emplace_back(-24, -74);
  v.emplace_back(-51, -6);
  v.emplace_back(73, 17);
  v.emplace_back(-30, -34);
  auto ans1 = convex_hull(v);
  vector<Point2d> ans2;
  ans2.emplace_back(-24, -74);
  ans2.emplace_back(73, 17);
  ans2.emplace_back(-51, -6);
  sort(ans1.begin(), ans1.end());
  sort(ans2.begin(), ans2.end());
  assert(ans1 == ans2);
}
int main(){
  test1();
  test2();
  return 0;
}