#include "../../code/data_structures/segment_tree_lazy.h"
const int MAXX = 1000000000;
const int MAXN = 1000;
long long v[MAXN + 10];

int randWithNeg(){
  if (rand() % 2)
    return (rand() % MAXX);
  else
    return -(rand() % MAXX);
}

long long rangeSum(int a, int b){
  long long ans = v[a];
  for (int i = a + 1; i <= b; i++)
    ans = (ans + v[i]);
  return ans;
}
void rangeUpdate(int a, int b, int x){
  for (int i = a; i <= b; i++)
    v[i] += x;
}

void testUpdateAndQuery(){
  vector<int> aux(MAXN);
  srand(42);
  for (int i = 0; i < MAXN; i++){
    v[i] = randWithNeg();
    aux[i] = v[i];
  }

  SegTreeLazy st(aux.begin(), aux.end());
  for (int i = 0; i < MAXN; i++){
    for (int j = i; j < MAXN; j++){
      assert(st.query(i, j) == rangeSum(i, j));
    }
  }
  for (int i = 0; i < MAXN; i++){
    for (int j = i; j < MAXN; j++){
      assert(st.query(i, j) == rangeSum(i, j));
      int x = randWithNeg();
      rangeUpdate(i, j, x);
      st.update(i, j, x);
      assert(st.query(i, j) == rangeSum(i, j));
    }
  }
}

int main(){
  testUpdateAndQuery();
  return 0;
}
