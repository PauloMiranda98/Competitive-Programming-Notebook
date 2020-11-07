#include <bits/stdc++.h>
using namespace std;
#define POINT_DOUBLE
#ifdef POINT_DOUBLE
  // Se necessario, apelar para __float128
  typedef double ftype;
  typedef long double ftLong;
  const double EPS = 1e-9;
  #define eq(a, b) (abs(a - b) < EPS)
  #define lt(a, b) ((a + EPS) < b)
  #define gt(a, b) (a > (b + EPS))
  #define le(a, b) (a < (b + EPS))
  #define ge(a, b) ((a + EPS) > b)
#else
  typedef int32_t ftype;
  typedef int64_t ftLong;
  #define eq(a, b) (a == b)
  #define lt(a, b) (a < b)
  #define gt(a, b) (a > b)
  #define le(a, b) (a <= b)
  #define ge(a, b) (a >= b)
#endif
//Begin Point 2D
struct Point2d{
  ftype x, y;
  Point2d() {}
  Point2d(ftype x1, ftype y1) : x(x1), y(y1) {}
  Point2d operator+(const Point2d &t){
    return Point2d(x + t.x, y + t.y);
  }
  Point2d operator-(const Point2d &t){
    return Point2d(x - t.x, y - t.y);
  }
  Point2d operator*(ftype t){
    return Point2d(x * t, y * t);
  }
  Point2d operator/(ftype t){
    return Point2d(x / t, y / t);
  }
  bool operator<(const Point2d &o) const{
    return lt(x, o.x) or (eq(x, o.x) and lt(y, o.y));
  }
  bool operator==(const Point2d &o) const{
    return eq(x, o.x) and eq(y, o.y);
  }
  friend std::istream& operator >> (std::istream &is, Point2d &p) {
    return is >> p.x >> p.y;
  }  
};
ftLong pw2(ftype a){
  return a * (ftLong)a;
}
//Scalar product
ftLong dot(Point2d a, Point2d b){
  return a.x*(ftLong)b.x + a.y*(ftLong)b.y;
}
ftLong norm(Point2d a){
  return dot(a, a);
}
double len(Point2d a){
  return sqrtl(dot(a, a));
}
double dist(Point2d a, Point2d b){
  return len(a - b);
}
//Vector product
ftLong cross(Point2d a, Point2d b){
  return a.x * (ftLong)b.y - a.y * (ftLong)b.x;
}
//Projection size from A to B
double proj(Point2d a, Point2d b){
  return dot(a, b) / len(b);
}
//The angle between A and B
double angle(Point2d a, Point2d b){
  return acos(dot(a, b) / len(a) / len(b));
}
//Left rotation. Angle in radian
Point2d rotateL(Point2d p, double ang){
  return Point2d(p.x * cos(ang) - p.y * sin(ang), p.x * sin(ang) + p.y * cos(ang));
}
//90 degree left rotation
Point2d perpL(Point2d a){
  return Point2d(-a.y, a.x);
}
//0-> 1o,2o quadrant, 1-> 3o,4o
int half(Point2d &p){
  if (gt(p.y, 0) or (eq(p.y, 0) and ge(p.x, 0)))
    return 0;
  else
    return 1;
}
//angle(a) < angle(b)
bool cmpByAngle(Point2d a, Point2d b){
  int ha = half(a), hb = half(b);
  if (ha != hb){
    return ha < hb;
  }else{
    ftLong c = cross(a, b);
    if(eq(c, 0))
      return lt(norm(a), norm(b));
    else
      return gt(c, 0);
  }
}
inline int sgn(ftLong x){
  return ge(x, 0) ? (eq(x, 0) ? 0 : 1) : -1;
}
//-1: angle(a, b) < angle(b, c)
// 0: angle(a, b) = angle(b, c)
//+1: angle(a, b) > angle(b, c)
int cmpAngleBetweenVectors(Point2d a, Point2d b, Point2d c){
  ftLong dotAB = dot(a, b), dotBC = dot(b, c);
  int sgnAB = sgn(dotAB), sgnBC = sgn(dotBC);
  if(sgnAB == sgnBC){
    //Careful with overflow
    ftLong l = pw2(dotAB)*dot(c, c), r = pw2(dotBC)*dot(a, a);
    if(l == r)
      return 0;
    if(sgnAB == 1)
      return gt(l, r)? -1 : +1;
    return lt(l, r)? -1 : +1;
  }else{
    return (sgnAB > sgnBC)? -1 : +1;
  }   
}
//Line parameterized: r1 = a1 + d1*t
//This function can be generalized to 3D
Point2d intersect(Point2d a1, Point2d d1, Point2d a2, Point2d d2){
  return a1 + d1 * (cross(a2 - a1, d2) / cross(d1, d2));
}
//distance between the point(a) e line(pl1, pl2)
//This function can be generalized to 3D
double dist(Point2d a, Point2d pl1, Point2d pl2){
  //crs = parallelogram area
  double crs = cross(Point2d(a - pl1), Point2d(pl2 - pl1));
  //h = area/base
  return abs(crs / dist(pl1, pl2));
}
long double area(vector<Point2d> p){
  long double ret = 0;
  for (int i = 2; i < (int)p.size(); i++)
    ret += cross(p[i] - p[0], p[i - 1] - p[0]) / 2.0;
  return abs(ret);
}
ftLong signed_area_parallelogram(Point2d p1, Point2d p2, Point2d p3){
  return cross(p2 - p1, p3 - p2);
}
long double triangle_area(Point2d p1, Point2d p2, Point2d p3){
  return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}
bool pointInTriangle(Point2d a, Point2d b, Point2d c, Point2d p){
  ftLong s1 = abs(cross(b - a, c - a));
  ftLong s2 = abs(cross(a - p, b - p)) + abs(cross(b - p, c - p)) + abs(cross(c - p, a - p));
  return eq(s1, s2);
}
bool clockwise(Point2d p1, Point2d p2, Point2d p3){
  return lt(signed_area_parallelogram(p1, p2, p3), 0);
}
bool counter_clockwise(Point2d p1, Point2d p2, Point2d p3){
  return gt(signed_area_parallelogram(p1, p2, p3), 0);
}
//End Point 2D

//Begin Line
ftLong det(ftype a, ftype b, ftype c, ftype d){
  return a * (ftLong)d - b * (ftLong)c;
}
struct Line{
  ftype a, b, c;
  Line() {}
  Line(ftype a1, ftype b1, ftype c1) : a(a1), b(b1), c(c1){
    normalize();
  }
  Line(Point2d p1, Point2d p2){
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -a * p1.x - b * p1.y;
    normalize();
  }
  void normalize(){
#ifdef POINT_DOUBLE
    ftype z = sqrt(pw2(a) + pw2(b));
#else
    ftype z = __gcd(abs(a), __gcd(abs(b), abs(c)));
#endif
    if(eq(z, 0)) return;
    a /= z;
    b /= z;
    c /= z;
    if (lt(a, 0) or (eq(a, 0) and lt(b, 0))){
      a = -a;
      b = -b;
      c = -c;
    }
  }
};
bool intersect(Line m, Line n, Point2d &res){
  ftype zn = det(m.a, m.b, n.a, n.b);
  if (eq(zn, 0))
    return false;
  res.x = -det(m.c, m.b, n.c, n.b) / zn;
  res.y = -det(m.a, m.c, n.a, n.c) / zn;
  return true;
}
bool parallel(Line m, Line n){
  return eq(det(m.a, m.b, n.a, n.b), 0);
}
bool equivalent(Line m, Line n){
  return eq(det(m.a, m.b, n.a, n.b), 0) &&
         eq(det(m.a, m.c, n.a, n.c), 0) &&
         eq(det(m.b, m.c, n.b, n.c), 0);
}
//Distance from a point(x, y) to a line m
double dist(Line m, ftype x, ftype y){
  return abs(m.a * (ftLong)x + m.b * (ftLong)y + m.c) /
         sqrt(m.a * (ftLong)m.a + m.b * (ftLong)m.b);
}
//End Line

//Begin Segment
struct Segment{
  Point2d a, b;
  Segment() {}
  Segment(Point2d a1, Point2d b1) : a(a1), b(b1) {}
};
bool inter1d(ftype a, ftype b, ftype c, ftype d){
  if (gt(a, b)) swap(a, b);
  if (gt(c, d)) swap(c, d);
  return le(max(a, c), min(b, d));
}
bool check_intersection(Segment s1, Segment s2){
  Point2d a = s1.a, b = s1.b, c = s2.a, d = s2.b;
  if (eq(cross(a - c, d - c), 0) && eq(cross(b - c, d - c), 0))
    return inter1d(a.x, b.x, c.x, d.x) && inter1d(a.y, b.y, c.y, d.y);
  return sgn(cross(b - a, c - a)) != sgn(cross(b - a, d - a)) &&
         sgn(cross(d - c, a - c)) != sgn(cross(d - c, b - c));
}
inline bool betw(ftype l, ftype r, ftype x){
  return le(min(l, r), x) and le(x, max(l, r));
}
bool intersect(Segment s1, Segment s2, Segment &ans){
  Point2d a = s1.a, b = s1.b, c = s2.a, d = s2.b;
  if (!inter1d(a.x, b.x, c.x, d.x) || !inter1d(a.y, b.y, c.y, d.y))
    return false;
  Line m(a, b);
  Line n(c, d);
  if (parallel(m, n)){
    if (!equivalent(m, n))
      return false;
    if (b < a)
      swap(a, b);
    if (d < c)
      swap(c, d);
    ans = Segment(max(a, c), min(b, d));
    return true;
  }else{
    Point2d p(0, 0);
    intersect(m, n, p);
    ans = Segment(p, p);
    return betw(a.x, b.x, p.x) && betw(a.y, b.y, p.y) &&
           betw(c.x, d.x, p.x) && betw(c.y, d.y, p.y);
  }
}
//End Segment

//Begin Circle
struct Circle{
  ftype x, y, r;
  Circle() {}
  Circle(ftype x1, ftype y1, ftype r1) : x(x1), y(y1), r(r1){};
};
bool pointInCircle(Circle c, Point2d p){
  return ge(c.r, dist(Point2d(c.x, c.y), p));
}
//CircumCircle of a triangle is a circle that passes through all the vertices
Circle circumCircle(Point2d a, Point2d b, Point2d c){
  Point2d u((b - a).y, -((b - a).x));
  Point2d v((c - a).y, -((c - a).x));
  Point2d n = (c - b) * 0.5;
  double t = cross(u, n) / cross(v, u);
  Point2d ct = (((a + c) * 0.5) + (v * t));
  double r = dist(ct, a);
  return Circle(ct.x, ct.y, r);
}
//InCircle is the largest circle contained in the triangle
Circle inCircle(Point2d a, Point2d b, Point2d c){
  double m1 = dist(a, b);
  double m2 = dist(a, c);
  double m3 = dist(b, c);
  Point2d ct = ((c * m1) + (b * m2) + a * (m3)) / (m1 + m2 + m3);
  double sp = 0.5 * (m1 + m2 + m3);
  double r = sqrt(sp * (sp - m1) * (sp - m2) * (sp - m3)) / sp;
  return Circle(ct.x, ct.y, r);
}
//Minimum enclosing circle, O(n)
Circle minimumCircle(vector<Point2d> p){
  random_shuffle(p.begin(), p.end());
  Circle c = Circle(p[0].x, p[0].y, 0.0);
  for (int i = 0; i < (int)p.size(); i++){
    if (pointInCircle(c, p[i]))
      continue;
    c = Circle(p[i].x, p[i].y, 0.0);
    for (int j = 0; j < i; j++){
      if (pointInCircle(c, p[j]))
        continue;
      c = Circle((p[j].x + p[i].x) * 0.5, (p[j].y + p[i].y) * 0.5, 0.5 * dist(p[j], p[i]));
      for (int k = 0; k < j; k++){
        if (pointInCircle(c, p[k]))
          continue;
        c = circumCircle(p[j], p[i], p[k]);
      }
    }
  }
  return c;
}
//Return the number of the intersection
int circle_line_intersection(Circle circ, Line line, Point2d &p1, Point2d &p2){
  ftLong r = circ.r;
  ftLong a = line.a, b = line.b, c = line.c + line.a * circ.x + line.b * circ.y; //take a circle to the (0, 0)
  ftLong x0 = -a * c / (pw2(a) + pw2(b)), y0 = -b * c / (pw2(a) + pw2(b));       //(x0, y0) is the shortest distance point of the line for (0, 0)
  if (gt(pw2(c), pw2(r) * (pw2(a) + pw2(b)))){
    return 0;
  }
  else if (eq(pw2(c), pw2(r) * (pw2(a) + pw2(b)))){
    p1.x = p2.x = x0 + circ.x;
    p1.y = p2.y = y0 + circ.y;
    return 1;
  }else{
    ftLong d_2 = pw2(r) - pw2(c) / (pw2(a) + pw2(b));
    ftLong mult = sqrt(d_2 / (pw2(a) + pw2(b)));
    p1.x = x0 + b * mult + circ.x;
    p2.x = x0 - b * mult + circ.x;
    p1.y = y0 - a * mult + circ.y;
    p2.y = y0 + a * mult + circ.y;
    return 2;
  }
}
//Return the number of the intersection
int circle_intersection(Circle c1, Circle c2, Point2d &p1, Point2d &p2){
  if (eq(c1.x, c2.x) and eq(c1.y, c2.y)){
    if (eq(c1.r, c2.r))
      return -1; //INF
    else
      return 0;
  }else{
    Circle circ(0, 0, c1.r);
    Line line;
    line.a = -2 * (c2.x - c1.x);
    line.b = -2 * (c2.y - c1.y);
    line.c = pw2(c2.x - c1.x) + pw2(c2.y - c1.y) + pw2(c1.r) - pw2(c2.r);
    int sz = circle_line_intersection(circ, line, p1, p2);
    p1.x += c1.x;
    p2.x += c1.x;
    p1.y += c1.y;
    p2.y += c1.y;
    return sz;
  }
}

bool checkIfTheSegmentIsCompletelyCoveredByCircles(vector<Circle> &vc, Segment s){
  vector<Point2d> v = {s.a, s.b};
  Line l(s.a, s.b);
  for (Circle c : vc){
    Point2d p1, p2;
    int inter = circle_line_intersection(c, l, p1, p2);
    if (inter >= 1 and betw(s.a.x, s.b.x, p1.x) and betw(s.a.y, s.b.y, p1.y))
      v.push_back(p1);
    if (inter == 2 and betw(s.a.x, s.b.x, p2.x) and betw(s.a.y, s.b.y, p2.y))
      v.push_back(p2);
  }
  sort(v.begin(), v.end());
  bool ans = true;
  for (int i = 1; i < (int)v.size(); i++){
    bool has = false;
    for (Circle c : vc){
      if (pointInCircle(c, v[i - 1]) and pointInCircle(c, v[i])){
        has = true;
        break;
      }
    }
    ans = ans && has;
  }
  return ans;
}

void tangents(Point2d c, double r1, double r2, vector<Line> &ans){
  double r = r2 - r1;
  double z = pw2(c.x) + pw2(c.y);
  double d = z - pw2(r);
  if (lt(d, 0))
    return;
  d = sqrt(abs(d));
  Line l;
  l.a = (c.x * r + c.y * d) / z;
  l.b = (c.y * r - c.x * d) / z;
  l.c = r1;
  ans.push_back(l);
}
vector<Line> tangents(Circle a, Circle b){
  vector<Line> ans;
  for (int i = -1; i <= 1; i += 2)
    for (int j = -1; j <= 1; j += 2)
      tangents(Point2d(b.x - a.x, b.y - a.y), a.r * i, b.r * j, ans);
  for (size_t i = 0; i < ans.size(); ++i){
    ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
    ans[i].normalize();
  }
  return ans;
}
//End Circle
