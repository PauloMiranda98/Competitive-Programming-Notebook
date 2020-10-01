#include "../../code/miscellaneous/polyominoes.h"

void test(){
  buildPolyominoes();
  assert(polyominoes[1].size() == 1);
  assert(polyominoes[2].size() == 2);
  assert(polyominoes[3].size() == 6);
  assert(polyominoes[4].size() == 19);
  assert(polyominoes[5].size() == 63);
  assert(polyominoes[6].size() == 216);
  assert(polyominoes[7].size() == 760);
  assert(polyominoes[8].size() == 2725);
  assert(polyominoes[9].size() == 9910);
  assert(polyominoes[10].size() == 36446);  
}

int main() {
  test();
  return 0;
}
