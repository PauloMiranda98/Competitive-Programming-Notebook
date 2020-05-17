#include "../../code/geometry/basic_geometry.h"

void testPoint(){
  Point2d a(1, 1), b(3, 2);
  assert(eq(len(a), sqrt(2)));
  assert(eq(len(b), sqrt(13)));
  assert(a == a);
  assert(!(a == b));

	Point2d p(-50, 1);
	Point2d l1(0, 0);
	Point2d l2(4, 0);
  assert(eq(dist(p, l1, l2), 1));
}

void testLine(){
	Line l1(10, 5, 10);
	Line l2(10, 5, 20);		
	assert(parallel(l1, l2));
	assert(!equivalent(l1, l2));

	l2 = Line(10, 5, 10);		
	assert(parallel(l1, l2));
	assert(equivalent(l1, l2));

	l2 = Line(5, 5, 10);		
	assert(!parallel(l1, l2));
	assert(!equivalent(l1, l2));

	Point2d pt;
	assert(intersect(l1, l2, pt));
	assert(pt == Point2d(0, -2));
}

void testSegment(){
	Segment s1({0, 0}, {0, 4});
	Segment s2({0, 2}, {0, 8});
	Segment ans;
  assert(check_intersection(s1, s2));
  assert(intersect(s1, s2, ans));
  assert(ans.a == Point2d(0, 2) and ans.b == Point2d(0, 4));

  s2 = Segment({0, 4}, {0, 8});
  assert(check_intersection(s1, s2));
  assert(intersect(s1, s2, ans));
  assert(ans.a == Point2d(0, 4) and ans.b == Point2d(0, 4));

  s2 = Segment({0, 5}, {0, 8});
  assert(!check_intersection(s1, s2));
  assert(!intersect(s1, s2, ans));
  
  s1 = Segment({-1, 0}, {0, -2});
  s2 = Segment({-2, 0}, {0, -2});
  assert(check_intersection(s1, s2));
  assert(intersect(s1, s2, ans));
  assert(ans.a == Point2d(0, -2) and ans.b == Point2d(0, -2));
}

void testCircle(){
  Circle c1(1, 0, 1), c2(-1, 0, 1);
  Point2d p1, p2;
  assert(circle_intersection(c1, c2, p1, p2) == 1);
  assert(p1 == p2 and p1 == Point2d(0, 0));

  c1.r = c2.r = sqrt(2);
  assert(circle_intersection(c1, c2, p1, p2) == 2);
  if(p2 < p1) swap(p1, p2);
  assert(p1 == Point2d(0, -1) and p2 == Point2d(0, 1));

  Line l({-2, 1}, {0, -1});
  assert(circle_line_intersection(c1, l, p1, p2) == 1);
  assert(p1 == p2 and p2 == Point2d(0, -1));

  assert(circle_line_intersection(c2, l, p1, p2) == 2);
  if(p2 < p1) swap(p1, p2);
  assert(p1 == Point2d(-2, 1) and p2 == Point2d(0, -1));
}

int main(){
  testPoint();
  testLine();
  testSegment();
  testCircle();
  return 0;
}