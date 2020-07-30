#include <bits/stdc++.h>
using namespace std;
//#define POINT_DOUBLE
#ifdef POINT_DOUBLE
  typedef double ftype;
  typedef long double ftLong;
  const double EPS = 1e-9;
  #define eq(a, b) (abs(a-b)<EPS)
  #define lt(a, b) ((a+EPS)<b)
  #define gt(a, b) (a>(b+EPS))
  #define le(a, b) (a<(b+EPS))
  #define ge(a, b) ((a+EPS)>b)
#else
  typedef int32_t ftype;
  typedef int64_t ftLong;
  #define eq(a, b) (a==b)
  #define lt(a, b) (a<b)
  #define gt(a, b) (a>b)
  #define le(a, b) (a<=b)
  #define ge(a, b) (a>=b)
#endif
//Point3D
struct Point3d{
  ftype x, y, z;
  Point3d() {}
  Point3d(ftype x, ftype y, ftype z) : x(x), y(y), z(z) {}
  Point3d operator+(Point3d t){
    return Point3d(x + t.x, y + t.y, z + t.z);
  }
  Point3d operator-(Point3d t){
    return Point3d(x - t.x, y - t.y, z - t.z);
  }
  Point3d operator*(ftype t){
    return Point3d(x * t, y * t, z * t);
  }
  Point3d operator/(ftype t){
    return Point3d(x / t, y / t, z / t);
  }
};
ftLong dot(Point3d a, Point3d b){
  return a.x * (ftLong)b.x + a.y * (ftLong)b.y + a.z * (ftLong)b.z;
}
double len(Point3d a){
  return sqrt(dot(a, a));
}
double dist(Point3d a, Point3d b){
  return len(a-b);
}
double proj(Point3d a, Point3d b){
  return dot(a, b) / len(b);
}
//theta -> XY; phi -> ZY;
Point3d toVetor(double theta, double phi, double r){
  return Point3d(r*cos(theta)*sin(phi), r*sin(theta)*sin(phi), r*cos(phi));
}
double getAngleTheta(Point3d p){
  return atan2(p.y, p.x);
}
double getAnglePhi(Point3d p){
  return acos(p.z/len(p));
}
Point3d rotateX(Point3d p, double ang){
  return Point3d(p.x, p.y*cos(ang)-p.z*sin(ang), p.y*sin(ang)+p.z*cos(ang));
}
Point3d rotateY(Point3d p, double ang){
  return Point3d(p.x*cos(ang)+p.z*sin(ang), p.y, -p.x*sin(ang)+p.z*cos(ang));
}
Point3d rotateZ(Point3d p, double ang){
  return Point3d(p.x*cos(ang)-p.y*sin(ang), p.x*sin(ang)+p.y*cos(ang), p.z);
}
//Rotation in relation to the normal axis
Point3d rotateNormal(Point3d v, Point3d n, double ang){
  double theta = getAngleTheta(n);
  double phi = getAnglePhi(n);
  v = rotateZ(v, -theta);
  v = rotateY(v, -phi);
  v = rotateZ(v, ang);
  v = rotateY(v, phi);
  v = rotateZ(v, theta); 
  return v; 
}
Point3d cross(Point3d a, Point3d b){
  return Point3d(a.y * b.z - a.z * b.y,
                 a.z * b.x - a.x * b.z,
                 a.x * b.y - a.y * b.x);
}
ftLong triple(Point3d a, Point3d b, Point3d c){
  return dot(a, cross(b, c));
}
Point3d planeIntersect(Point3d a1, Point3d n1, Point3d a2, Point3d n2, Point3d a3, Point3d n3){
  Point3d x(n1.x, n2.x, n3.x);
  Point3d y(n1.y, n2.y, n3.y);
  Point3d z(n1.z, n2.z, n3.z);
  Point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
  return Point3d(triple(d, y, z),
                 triple(x, d, z),
                 triple(x, y, d)) / triple(n1, n2, n3);
}
struct Sphere{
	ftype x, y, z, r;
	Sphere(){} 
	Sphere(ftype x, ftype y, ftype z,  ftype r):x(x), y(y), z(z), r(r){}
};
//Minimum enclosing Sphere, O(n*70000)
//It is also possible to do with ternary search in the 3 dimensions
Sphere minimumSphere(vector<Point3d> vp){
	Point3d ans(0, 0, 0);
	int n = vp.size();
	for(Point3d p: vp)
		ans = ans + p;		
	ans = ans/n;
	double P = 0.1;
	double d = 0, e = 0;
	for(int i = 0; i < 70000; i++){
		int f = 0;
		d = dist(ans, vp[0]);
		for (int j = 1; j < n; j++) {
			e = dist(ans, vp[j]);
			if (d < e) {
				d = e;
				f = j;
			}
		}
		ans = ans + (vp[f]-ans)*P;
		P *= 0.998;
	}
	return Sphere(ans.x, ans.y, ans.z, d);
}