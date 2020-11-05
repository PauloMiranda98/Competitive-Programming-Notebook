#include "../../code/geometry/convex_polygon.h"

void test1(){
  vector<Point2d> v;
  v.emplace_back(0, 0);
  v.emplace_back(0, 10);
  v.emplace_back(10, 0);
  v.emplace_back(10, 10);
  ConvexPolygon pol(v);
  assert(pol.pointInPolygon(Point2d(5, 5)) == true);
  assert(pol.pointInPolygon(Point2d(0, 0)) == true);
  assert(pol.pointInPolygon(Point2d(0, 5)) == true);
  assert(pol.pointInPolygon(Point2d(-1, 0)) == false);
  assert(pol.pointInPolygon(Point2d(0, 11)) == false);
  assert(pol.pointInPolygon(Point2d(-1, 5)) == false);
  assert(pol.pointInPolygon(Point2d(11, 11)) == false);
}
void test2(){
  
  int n, m, k;
  
  cin >> n >> m >> k;
  vector<Point2d> v(n);
  
  for(int i=0; i<n; i++){
    cin >> v[i].x >> v[i].y;
  }
  ConvexPolygon pol(v);
  for(int i=0; i<m; i++){
    Point2d p;
    cin >> p.x >> p.y;
    k -= pol.pointInPolygon(p);
  }
 
  if(k <= 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  test1();
//  test2(); // AC: https://codeforces.com/problemsets/acmsguru/submission/99999/84838119
  return 0;
}