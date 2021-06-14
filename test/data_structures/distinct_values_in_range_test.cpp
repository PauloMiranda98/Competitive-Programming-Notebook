#include "../../code/data_structures/distinct_values_in_range.h"
const int MAXX = 1000000000;
const int MAXN = 1010;

int randWithNeg(){
  if (rand() % 2)
    return (rand() % MAXX);
  else
    return -(rand() % MAXX);
}

vector<int> v(MAXN);

void test1(){
  srand(48);
  for (int i = 0; i < MAXN; i++){
    v[i] = randWithNeg();
  }
  DistinctValues::init(v);
  for (int i = 0; i < MAXN; i++){
    set<int> st;
    for (int j = i; j < MAXN; j++){
      st.insert(v[j]);
      assert(DistinctValues::query(i, j) == st.size());
    }
  }
}

void test2(){
  assert(true); // AC: https://cses.fi/problemset/task/1734/
}

int main(){
  test1();
  test2();
  return 0;
}
