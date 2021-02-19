#include "basic_geometry.h"
const int INSIDE=-1, BOUNDARY=0, OUTSIDE=1;
struct GeneralPolygon{
  vector<Point2d> vp;  
  GeneralPolygon(vector<Point2d> aux){
    vp = aux;
  }
  // -1 inside, 0 boundary, 1 outside
  int pointInPolygon(Point2d pt) {
    int n = vp.size(), w = 0;
    for(int i=0; i<n; i++){
      if(pt == vp[i]) 
        return 0;
      int j = (i+1==n?0:i+1);
      if(vp[i].y == pt.y and vp[j].y == pt.y) {
        if (min(vp[i].x, vp[j].x) <= pt.x and pt.x <= max(vp[i].x, vp[j].x)) 
          return 0;
      }else{
        bool below = vp[i].y < pt.y;
        if (below != (vp[j].y < pt.y)) {
          auto orientation = cross(pt-vp[i], vp[j]-vp[i]);
          if (orientation == 0) return 0;
          if (below == (orientation > 0))
            w += below ? 1 : -1;
        }
      }
    }
    return (w==0?1:-1);
  }
};
