#include "../../code/geometry/nearest_pair_of_points.h"
const double EPS = 1e-6;
void test1(){
  vector<pt> v;
  for(int i=0; i<100; i++)
    v.emplace_back(rand(), rand());
  
  NearestPairOfPoints::solve(v);
  auto ans = NearestPairOfPoints::mindist;
  
  double mn = 1e20;
  for(int i=0; i<100; i++)
    for(int j=i+1; j<100; j++)
      mn = min(mn, sqrt((v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y)));
  assert(abs(ans-mn) < EPS);
}
int main(){
  srand(98);
  for(int i=0; i<5; i++)
    test1();
  return 0;
}
