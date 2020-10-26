#include "../../code/graph/tree_id.h"
void test1(){
  vector<pii> t1;
  t1.emplace_back(1, 2);
  t1.emplace_back(3, 2);
  t1.emplace_back(4, 2);
  t1.emplace_back(2, 0);

  vector<pii> t2;
  t2.emplace_back(0, 3);
  t2.emplace_back(2, 3);
  t2.emplace_back(4, 3);
  t2.emplace_back(3, 1);
  auto id1 = TreeID::getTreeID(t1, 5);
  auto id2 = TreeID::getTreeID(t2, 5);
  assert(id1 == id2);
}

void test2(){
  vector<pii> t1;
  t1.emplace_back(1, 3);
  t1.emplace_back(3, 2);
  t1.emplace_back(4, 2);
  t1.emplace_back(2, 0);

  vector<pii> t2;
  t2.emplace_back(0, 3);
  t2.emplace_back(2, 3);
  t2.emplace_back(4, 3);
  t2.emplace_back(3, 1);
  auto id1 = TreeID::getTreeID(t1, 5);
  auto id2 = TreeID::getTreeID(t2, 5);
  assert(id1 != id2);
}
void test3(){ // AC: https://www.urionlinejudge.com.br/judge/pt/problems/view/1229
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while(cin >> n){
    vector<pii> t1, t2;
    for(int i=0; i<n-1; i++){
      int a, b;
      cin >> a >> b; a--; b--;
      t1.emplace_back(a, b);
    }
    for(int i=0; i<n-1; i++){
      int a, b;
      cin >> a >> b; a--; b--;
      t2.emplace_back(a, b);
    }
    if(TreeID::isomorphic(t1, t2, n))
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
}
int main(){ 
  test1();
  test2();
//  test3();
  return 0; 
}
