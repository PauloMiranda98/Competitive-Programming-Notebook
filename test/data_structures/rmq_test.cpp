#include "../../code/data_structures/rmq.h"

const int MAXX = 1000000000;
const int MAXN = 1000;
vector<int> v;

int randWithNeg(){
  if (rand() % 2)
    return (rand() % MAXX);
  else
    return -(rand() % MAXX);
}

int rangeMin(int a, int b){
  int ans = v[a];
  for (int i = a + 1; i <= b; i++)
    ans = min(ans, v[i]);
  return ans;
}

void testQuery(){
  srand(98);
  v.resize(MAXN);
  for (int i = 0; i < MAXN; i++){
    v[i] = randWithNeg();
  }

  RMQ<int> rmq(v);
  for (int i = 0; i < MAXN; i++){
    for (int j = i; j < MAXN; j++){
      assert(rmq.query(i, j) == rangeMin(i, j));
    }
  }
}

int main(){
  testQuery();
  return 0;
}