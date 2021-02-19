#include "../../code/geometry/general_polygon.h"

void test1(){
  vector<Point2d> v;
  v.emplace_back(0, 0);
  v.emplace_back(0, 10);
  v.emplace_back(10, 10);
  v.emplace_back(10, 0);
  for(int i=0; i<2; i++){
    GeneralPolygon pol(v);
    assert(pol.pointInPolygon(Point2d(5, 5)) == INSIDE);
    assert(pol.pointInPolygon(Point2d(0, 0)) == BOUNDARY);
    assert(pol.pointInPolygon(Point2d(0, 5)) == BOUNDARY);
    assert(pol.pointInPolygon(Point2d(-1, 0)) == OUTSIDE);
    assert(pol.pointInPolygon(Point2d(0, 11)) == OUTSIDE);
    assert(pol.pointInPolygon(Point2d(-1, 5)) == OUTSIDE);
    assert(pol.pointInPolygon(Point2d(11, 11)) == OUTSIDE);
    reverse(v.begin(), v.end());
  }
}

void test2(){
  vector<Point2d> v;
  v.emplace_back(0, 0);
  v.emplace_back(5, 0);
  v.emplace_back(10, 5);
  v.emplace_back(15, 0);
  v.emplace_back(15, 10);
  v.emplace_back(0, 10);
  
  for(int i=0; i<2; i++){
    GeneralPolygon pol(v);
    assert(pol.pointInPolygon(Point2d(0, 0)) == BOUNDARY);
    assert(pol.pointInPolygon(Point2d(10, 0)) == OUTSIDE);
    assert(pol.pointInPolygon(Point2d(10, 5)) == BOUNDARY);
    assert(pol.pointInPolygon(Point2d(10, 6)) == INSIDE);
    assert(pol.pointInPolygon(Point2d(2, 2)) == INSIDE);
    
    reverse(v.begin(), v.end());
  }
}
void test3(){
  assert(true); // AC: https://vjudge.net/problem/UVA-634
  assert(true); // AC: https://open.kattis.com/problems/pointinpolygon
  assert(true); // AC: https://cses.fi/problemset/task/2192/
}
int main() {
  test1();
  test2();
  test3();
  return 0;
}
