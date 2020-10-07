#include "../../code/data_structures/segment_tree_iterative.h"
const int MAXX = 1000000000;
const int MAXN = 1000;
int v[MAXN + 10];

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

void testUpdateAndQuery(){
  srand(42);
  for (int i = 0; i < MAXN; i++){
    v[i] = randWithNeg();
  }

  SegTreeIterative st(v, v + MAXN);
  for (int i = 0; i < MAXN; i++){
    for (int j = i; j < MAXN; j++){
      assert(st.query(i, j) == rangeSum(i, j));
    }
  }
  for (int i = 0; i < MAXN; i++){
    for (int j = i; j < MAXN; j++){
      assert(st.query(i, j) == rangeSum(i, j));
      v[j] = randWithNeg();
      st.update(j, v[j]);
      assert(st.query(i, j) == rangeSum(i, j));
    }
  }
}

void testLowerBound(){
  srand(42);
  for (int i = 0; i < MAXN; i++){
    v[i] = rand()%5;
  }

  SegTreeIterative st(v, v + MAXN);
  for (int i = 0; i < MAXN; i++){
    int k = rand()%MAXN;
    int ans = -1;
    for(int j=0; j < MAXN; j++){
      if(st.query(0, j) >= k){
        ans = j;
        break;
      }
    }
    assert(st.lower_bound(k) == ans);
  }
}

int main(){
  testUpdateAndQuery();
  testLowerBound();
  return 0;
}