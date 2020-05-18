#include "../../code/geometry/circle_area_union.h"

void testCircle(){
  vector<Circle> vc;
  vc.emplace_back(0, 0, 1.4142135624);
  vc.emplace_back(0, 2, 1.4142135624);
  vc.emplace_back(2, 0, 1.4142135624);
  vc.emplace_back(2, 2, 1.4142135624);
  double ans = circle_union(vc);
  assert(eq(ans, 20.566370614837));
}

int main(){
  testCircle();
  return 0;
}