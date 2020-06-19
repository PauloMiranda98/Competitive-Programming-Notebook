#include "../../code/geometry/count_lattices.h"
void testCountLattices(){
  Fraction k, b;
  k = 1;
  b = 0;
  assert(count_lattices(k, b, 4) == 6);

  k = 1;
  b = 1;
  assert(count_lattices(k, b, 4) == 10);

  k = -1;
  b = 4;
  assert(count_lattices(k, b, 4) == 10);

  k = {5, 2};
  b = 2;
  assert(count_lattices(k, b, 4) == 22);

}

int main(){
  testCountLattices();
  return 0;
}
