#include "../../code/data_structures/sparse_table.h"
const int MAXX = 1000000000;
const int MAXN = 1000;
int v[MAXN + 10];

int randWithNeg(){
  if(rand()%2)
    return (rand()%MAXX);
  else
    return -(rand()%MAXX);
}

int rangeMin(int a, int b){
  int ans = v[a];
  for(int i=a+1; i<=b; i++)
    ans = min(ans, v[i]);
  return ans;
}

void testQuery(){
  srand(42);
  for(int i=0; i<MAXN; i++){
    v[i] = randWithNeg();
  }

  SparseTable stMin(v, v+MAXN);
  for(int i=0; i<MAXN; i++){
    for(int j=i; j<MAXN; j++){
      assert(stMin.query(i, j) == rangeMin(i, j));   
      assert(stMin.queryRMQ(i, j) == rangeMin(i, j));   
    }
  }
}

int main() {		
	testQuery();
	return 0;	
}