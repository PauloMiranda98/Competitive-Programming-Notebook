#include "../../code/data_structures/wavelet_tree.h"
const int MAXX = 1000000000;
const int MAXN = 100;
int v[MAXN + 10];
int cp[MAXN + 10];

int randWithNeg(){
  if (rand() % 2)
    return (rand() % MAXX);
  else
    return -(rand() % MAXX);
}

int lte(int a, int b, int k){
  int count = 0;
  for (int i = a; i <= b; i++)
    count += v[i] <= k;
  return count;
}

int count(int a, int b, int k){
  int count = 0;
  for (int i = a; i <= b; i++)
    count += v[i] == k;
  return count;
}

int kth(int a, int b, int k){
  vector<int> v2(b - a + 1);
  int count = 0;
  for (int i = a; i <= b; i++)
    v2[i - a] = v[i];
  sort(v2.begin(), v2.end());
  return v2[k - 1];
}

void testQuery(){
  srand(42);
  for (int i = 1; i <= MAXN; i++){
    v[i] = randWithNeg();
    cp[i] = v[i];
  }

  WaveletTree wt(cp + 1, cp + MAXN + 1, -MAXX, MAXX);
  for (int i = 1; i <= MAXN; i++){
    for (int j = i; j <= MAXN; j++){
      for (int k = 1; k <= (j - i + 1); k++){
        assert(wt.lte(i, j, v[i + k - 1]) == lte(i, j, v[i + k - 1]));
        assert(wt.kth(i, j, k) == kth(i, j, k));
        assert(wt.count(i, j, v[i + k - 1]) == count(i, j, v[i + k - 1]));
      }
    }
  }
}

int main(){
  testQuery();
  return 0;
}