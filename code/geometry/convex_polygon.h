#include "convex_hull.h"
using namespace std;
//Checks if the point P belongs to the segment AB
bool pointInSegment(Point2d &a, Point2d &b, Point2d &p) {
  if(!eq(cross(a-p, b-p), 0))   
    return false;
  return betw(a.x, b.x, p.x) && betw(a.y, b.y, p.y);
}
struct ConvexPolygon{
  vector<Point2d> vp;  
  ConvexPolygon(vector<Point2d> aux){
    vp = convex_hull(aux);
  }  
  //O(log(N))
  //Accepts points on the edge
  bool pointInPolygon(Point2d point){ 
    if(vp.size() < 3)
      return pointInSegment(vp[0], vp[1], point);     
    if(!eq(cross(vp[1]-vp[0], point-vp[0]), 0) and sgn(cross(vp[1]-vp[0], point-vp[0])) != sgn(cross(vp[1]-vp[0], vp.back()-vp[0])) )
      return false;
    if(!eq(cross(vp.back()-vp[0], point-vp[0]), 0) and sgn(cross(vp.back()-vp[0], point-vp[0])) != sgn(cross(vp.back() - vp[0], vp[1]-vp[0])) )
      return false;
    if(eq(cross(vp[1]-vp[0], point-vp[0]), 0))
      return ge(norm(vp[1]-vp[0]), norm(point-vp[0]));
    int pos = 1, l = 1, r = vp.size() - 2;    
    while(l <= r){
      int mid = (l + r)/2;
      if(cross(vp[mid] - vp[0], point - vp[0]) <= 0){
        pos = mid;
        l = mid+1;
      }else{ 
        r = mid-1;
      }
    }    
    return pointInTriangle(vp[0], vp[pos], vp[pos+1], point);
  } 
};
