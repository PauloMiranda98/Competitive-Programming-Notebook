#include "../../code/data_structures/sqrt_decomposition.h"
const int MAXX = 1000000000;
const int MAXN = 1000;
int v[MAXN + 10];

int randWithNeg(){
  if(rand()%2)
    return (rand()%MAXX);
  else
    return -(rand()%MAXX);
}

long long rangeSum(int a, int b){
  long long ans = v[a];
  for(int i=a+1; i<=b; i++)
    ans = (ans + v[i]);
  return ans;
}

void testUpdateAndQuery(){   
  srand(42);
  for(int i=0; i<MAXN; i++){
    v[i] = randWithNeg();
  }

  SqrtDecomposition sdSum(v, v+MAXN);
  for(int i=0; i<MAXN; i++){
    for(int j=i; j<MAXN; j++){
      assert(sdSum.query(i, j) == rangeSum(i, j));   
    }
  }
  for(int i=0; i<MAXN; i++){
    for(int j=i; j<MAXN; j++){
      assert(sdSum.query(i, j) == rangeSum(i, j));   
      v[j] = randWithNeg();
      sdSum.update(j, v[j]);
      assert(sdSum.query(i, j) == rangeSum(i, j));   
    }
  }

}

int main() {		
	testUpdateAndQuery();
	return 0;	
}