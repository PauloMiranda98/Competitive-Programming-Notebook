#include "../../code/graph/arborescence.h"
void test1(){
  vector<Edge> v;
  v.push_back(Edge({1, 0, 10}));
  vector<Edge> ans;
  assert(dmst(2, 0, v).first == -1);
  assert(dmst(2, 1, v).first == 10);
  assert(dmstAnyRoot(2, v).first == 10);
}
void test2(){
  vector<Edge> v;
  v.push_back(Edge({0, 1, 10}));
  v.push_back(Edge({0, 2, 10}));
  v.push_back(Edge({1, 3, 20}));
  v.push_back(Edge({2, 3, 30}));
  assert(dmst(4, 0, v).first == 40);
  assert(dmstAnyRoot(4, v).first == 40);
}
void test3(){
  vector<Edge> v;
  v.push_back(Edge({0, 1, 10}));
  v.push_back(Edge({1, 2, 20}));
  v.push_back(Edge({2, 0, 30}));
  v.push_back(Edge({2, 3, 100}));
  assert(dmst(4, 0, v).first == 130);
  assert(dmstAnyRoot(4, v).first == 130);
}
void test4(){
  assert(true); // AC in https://codeforces.com/gym/102483/problem/F
  assert(true); // AC in https://vjudge.net/problem/UVA-11183
  assert(true); // AC in https://judge.yosupo.jp/problem/directedmst
}
int main(){
  test1();
  test2();
  test3();
  test4();
  return 0;
}

