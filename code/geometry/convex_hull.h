#include "basic_geometry.h"
using namespace std;
//If accept collinear points then change for <=
bool cw(Point2d a, Point2d b, Point2d c) {
  return lt(cross(b - a, c - b), 0);
}
//If accept collinear points then change for >=
bool ccw(Point2d a, Point2d b, Point2d c) {
  return gt(cross(b - a, c - b), 0);
}
vector<Point2d> convex_hull(vector<Point2d> a){
  if (a.size() == 1)
    return a;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  vector<Point2d> up, down;
  Point2d p1 = a[0], p2 = a.back();
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < (int)a.size(); i++){
    if ((i == int(a.size() - 1)) || cw(p1, a[i], p2)){
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if ((i == int(a.size() - 1)) || ccw(p1, a[i], p2)){
      while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
  }
  a.clear();
  for (int i = 0; i < (int)up.size(); i++)
    a.push_back(up[i]);  
  for (int i = down.size() - 2; i > 0; i--)
    a.push_back(down[i]);  
  return a;
}