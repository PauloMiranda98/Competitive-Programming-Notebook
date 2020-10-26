#include "../../code/graph/centroid.h"

void test1(){
  Centroid::init(4);
  Centroid::addEdge(0, 1);
  Centroid::addEdge(1, 2);
  Centroid::addEdge(2, 3);
  auto p = Centroid::findCentroid();
  if(p.first > p.second)
    swap(p.first, p.second);
  assert(p == pii(1, 2));
}

void test2(){
  Centroid::init(7);
  Centroid::addEdge(0, 2);
  Centroid::addEdge(1, 2);
  Centroid::addEdge(2, 3);
  Centroid::addEdge(3, 4);
  Centroid::addEdge(4, 5);
  Centroid::addEdge(4, 6);
  auto p = Centroid::findCentroid();
  assert(p == pii(3, 3));
}

int main(){ 
  test1();
  test2();
  return 0; 
}
