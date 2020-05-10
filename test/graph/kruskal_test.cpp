#include "../../code/graph/kruskal.h"
void test1(){
  int n = 5;
  vector<Edge> v;
  v.emplace_back(1, 2, 15);
  v.emplace_back(1, 3, 10);
  v.emplace_back(2, 3, 1);
  v.emplace_back(3, 4, 3);
  v.emplace_back(2, 4, 5);
  v.emplace_back(4, 5, 20);
  assert(kruskal(v, n) == 34);
}
void test2(){
  int n = 5;
  vector<Edge> v;
  v.emplace_back(1, 2, 1);
  v.emplace_back(1, 3, 10);
  v.emplace_back(1, 4, 1);
  v.emplace_back(2, 3, 1);
  v.emplace_back(2, 4, 10);
  v.emplace_back(3, 4, 1);
  assert(kruskal(v, n) == 3);
}
int main(){
  test1();
  test2();
  return 0;
}