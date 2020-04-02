#include "../../code/data_structures/segment_tree_2d.h"
int mat[1010][1010];
int bruteForce(int x1, int y1, int x2, int y2){
  int mx = -0x3f3f3f3f;
  for(int a=x1; a<=x2; a++)
    for(int b=y1; b<=y2; b++)
      mx = max(mx, mat[a][b]);
  return mx;
}
void testInsertAndQuery(){
  int n = 600;
  int m = 565;
  SegTree2D seg2d(n, m);
  srand(2020);
  for(int i=0; i<1000; i++){
    int x1 = rand()%n;
    int x2 = rand()%n;
    int y1 = rand()%m;
    int y2 = rand()%m;
    if(x1 > x2)
      swap(x1, x2);
    if(y1 > y2)
      swap(y1, y2);
    assert(bruteForce(x1, y1, x2, y2) == seg2d.query(x1, y1, x2, y2));

    int x = rand()%n;
    int y = rand()%m;
    int newValue = rand();
    seg2d.update(x, y, newValue);
    mat[x][y] = newValue;
  }
}

int main(){
  testInsertAndQuery();
  return 0;
}