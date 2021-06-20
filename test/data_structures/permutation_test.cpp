#include "../../code/data_structures/permutation.h"

void test(){
  srand(2020);
  int n = 500;
  vector<int> v(n);
  for(int i=0; i<n; i++)
    v[i] = rand()%50;
  Permutation::init(v);
  for(int i=0; i<n; i++){
    set<int> st;
    for(int j=i; j<n; j++){
      st.insert(v[j]);
      int sz = j-i+1;
      bool is_permutation = (st.size() == sz and *st.begin() == 0 and *st.rbegin() == (sz-1));
      assert(is_permutation == Permutation::isPermutation(i, j));
    }
  }
}
void test2(){
  assert(true); // AC: https://codeforces.com/contest/1175/problem/F
}
int main() {
  test();
  test2();
  return 0;
}
