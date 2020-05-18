#include "basic_geometry.h"
using namespace std;

const double PI = acos(-1);
pair<double, double> isCC(Circle circ1, Circle circ2){
  Point2d c1(circ1.x, circ1.y), c2(circ2.x, circ2.y);
  double r1 = circ1.r, r2 = circ2.r;
  double d = dist(c1, c2);
  double x1 = c1.x, x2 = c2.x, y1 = c1.y, y2 = c2.y;
  double mid = atan2(y2 - y1, x2 - x1);
  double a = r1, c = r2;
  double t = acos((a * a + d * d - c * c) / (2 * a * d));
  return make_pair(mid - t, mid + t);
}
int testCC(Circle circ1, Circle circ2){
  Point2d c1(circ1.x, circ1.y), c2(circ2.x, circ2.y);
  double r1 = circ1.r, r2 = circ2.r;
  double d = dist(c1, c2);
  if (le(r1 + r2, d))
    return 1; // not intersected or tged
  if (le(r1 + d, r2))
    return 2; // C1 inside C2
  if (le(r2 + d, r1))
    return 3; // C2 inside C1
  return 0;   // intersected
}
struct event_t{
  double theta;
  int delta;
  event_t(double t, int d) : theta(t), delta(d) {}
  bool operator<(const event_t &r) const{
    if (fabs(theta - r.theta) < EPS)
      return delta > r.delta;
    return theta < r.theta;
  }
};
vector<event_t> e;
void add(double begin, double end){
  if (begin <= -PI)
    begin += 2 * PI, end += 2 * PI;
  if (end > PI){
    e.push_back(event_t(begin, 1));
    e.push_back(event_t(PI, -1));
    e.push_back(event_t(-PI, 1));
    e.push_back(event_t(end - 2 * PI, -1));
  }else{
    e.push_back(event_t(begin, 1));
    e.push_back(event_t(end, -1));
  }
}
double calc(Point2d c, double r, double a1, double a2){
  double da = a2 - a1;
  double aa = r * r * (da - sin(da)) / 2;
  Point2d p1 = Point2d(cos(a1), sin(a1)) * r + c;
  Point2d p2 = Point2d(cos(a2), sin(a2)) * r + c;
  return cross(p1, p2) / 2 + aa;
}
/* O(n^2logn), please remove coincided circles first. */
double circle_union(vector<Circle> &vc){
  int n = vc.size();
  for (int i = n - 1; i >= 0; i--){
    if (eq(vc[i].r, 0)){
      swap(vc[i], vc[n - 1]);
      n--;
      continue;
    }
    for (int j = 0; j < i; j++){
      if (eq(vc[i].x, vc[j].x) and eq(vc[i].y, vc[j].y) and eq(vc[i].r, vc[j].r)){
        swap(vc[i], vc[n - 1]);
        n--;
      }
    }
  }
  if (n == 0)
    return 0;
  vc.resize(n);
  vector<double> cntarea(2 * n, 0);
  for (int c = 0; c < n; c++){
    int cvrcnt = 0;
    e.clear();
    for (int i = 0; i < n; i++){
      if (i != c){
        int r = testCC(vc[c], vc[i]);
        if (r == 2){
          cvrcnt++;
        } else if (r == 0){
          auto paa = isCC(vc[c], vc[i]);
          add(paa.first, paa.second);
        }
      }
    }
    if (e.size() == 0){
      double a = PI * vc[c].r * vc[c].r;
      cntarea[cvrcnt] -= a;
      cntarea[cvrcnt + 1] += a;
    } else {
      e.push_back(event_t(-PI, 1));
      e.push_back(event_t(PI, -2));
      sort(e.begin(), e.end());
      for (int i = 0; i < int(e.size()) - 1; i++){
        cvrcnt += e[i].delta;
        double a = calc(Point2d(vc[c].x, vc[c].y), vc[c].r, e[i].theta, e[i + 1].theta);
        cntarea[cvrcnt - 1] -= a;
        cntarea[cvrcnt] += a;
      }
    }
  }
  double ans = 0;
  for(int i=1; i<=n; i++)
    ans += cntarea[i];  
  return ans;
}