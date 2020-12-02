#include "basic_geometry.h"
using namespace std;
struct LineCHT{
    ftype k, b;
    int id;
    LineCHT() {}
    LineCHT(ftype k, ftype b, int id=-1): k(k), b(b), id(id) {}
};
struct ConvexHullTrick{
  vector<Point2d> hull, vecs;
  ConvexHullTrick(){}
  ConvexHullTrick(vector<LineCHT> v){
    sort(v.begin(), v.end(), [&](LineCHT a, LineCHT b){
      return lt(a.k, b.k);
    });
    for(auto l: v)
      add_line(l.k, l.b);
  }  
  //Here we will assume that when linear functions are added, their k only increases and we want to find minimum values.
  void add_line(ftype k, ftype b) {
    Point2d nw(k, b);
    while(!vecs.empty() && lt(dot(vecs.back(), nw - hull.back()), 0)) {
      hull.pop_back();
      vecs.pop_back();
    }
    if(!hull.empty()) 
      vecs.push_back(perpL(nw - hull.back()));    
    hull.push_back(nw);
  }
  //Find minimum value
  ftLong get(ftype x) {
    Point2d query(x, 1);
    auto it = lower_bound(vecs.begin(), vecs.end(), query, [](Point2d a, Point2d b) {
      return gt(cross(a, b), 0);
    });
    return dot(query, hull[it - vecs.begin()]);
  }  
};
