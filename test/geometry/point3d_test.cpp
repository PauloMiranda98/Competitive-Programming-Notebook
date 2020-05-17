#include "../../code/geometry/point3d.h"
void test(){
  Point3d a(1, 1, 0), b(0, 3, 2);
  assert(eq(len(a), sqrt(2)));
  assert(eq(len(b), sqrt(13)));
}
int main(){
  test();
  return 0;
}