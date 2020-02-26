#include "../../code/data_structures/sqrt_tree.h"
const int MAXX = 1000000000;
const int MAXN = 1000;

int randWithNeg(){
  if(rand()%2)
    return (rand()%MAXX);
  else
    return -(rand()%MAXX);
}

long long rangeOr(vector<int> &v, int a, int b){
  long long ans = v[a];
  for(int i=a+1; i<=b; i++)
    ans = (ans | v[i]);
  return ans;
}

void testUpdateAndQuery(){   
  srand(42);
  vector<int> v(MAXN);
  for(int i=0; i<MAXN; i++){
    v[i] = randWithNeg();
  }

  SqrtTree stSum(v.begin(), v.end());
  for(int i=0; i<MAXN; i++){
    for(int j=i; j<MAXN; j++){
      assert(stSum.query(i, j) == rangeOr(v, i, j));   
    }
  }

  for(int i=0; i<MAXN; i++){
    for(int j=i; j<MAXN; j++){
      assert(stSum.query(i, j) == rangeOr(v, i, j));   
      v[j] = randWithNeg();
      stSum.update(j, v[j]);
      assert(stSum.query(i, j) == rangeOr(v, i, j));   
    }
  }

}

int main() {		
	testUpdateAndQuery();
	return 0;	
}