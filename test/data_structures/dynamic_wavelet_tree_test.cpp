#include "../../code/data_structures/dynamic_wavelet_tree.h"
const int MAXX = 1000000000;
const int MAXN = 100;
int v[MAXN + 10];

int randWithNeg(){
  if(rand()%2)
    return (rand()%MAXX);
  else
    return -(rand()%MAXX);
}

int lte(int a, int b, int k){
  int count = 0;
  for(int i=a; i<b; i++)
    count += v[i]<=k;
  return count;
}

int count(int a, int b, int k){
  int count = 0;
  for(int i=a; i<b; i++)
    count += v[i]==k;
  return count;
}

int kth(int a, int b, int k){
  vector<int> v2(b-a);
  int count = 0;
  for(int i=a; i<b; i++)
    v2[i-a] = v[i];
  sort(v2.begin(), v2.end());
  return v2[k-1];
}

void testOnlyQuery(){   
  srand(42);
  WaveletTree wt(-MAXX, MAXX);
  for(int i=0; i<MAXN; i++){
    v[i] = randWithNeg();
    wt.insert(i, v[i]);
  }

  for(int i=0; i<MAXN; i++){
    for(int j=i+1; j<=MAXN; j++){
      for(int k=1; k<=(j-i); k++){
        assert(wt.lte(i, j, v[i+k-1]) == lte(i, j, v[i+k-1])); 
        assert(wt.kth(i, j, k) == kth(i, j, k));   
        assert(wt.count(i, j, v[i+k-1]) == count(i, j, v[i+k-1]));   
      }
    }
  }
}

void testInsert(){
	WaveletTree wavelet(-100, 100);
	wavelet.insert(0, 10);
	wavelet.insert(1, 20);
	wavelet.insert(2, 30);
	wavelet.insert(1, -5);

	assert(wavelet.get(0) == 10);	
	assert(wavelet.get(1) == -5);	
	assert(wavelet.get(2) == 20);	
	assert(wavelet.get(3) == 30);	
}

void testErase(){
	WaveletTree wavelet(-100, 100);
	wavelet.insert(0, 10);
	wavelet.insert(1, 20);
	wavelet.insert(2, 30);
	wavelet.insert(1, -5);
	
	wavelet.erase(2);

	assert(wavelet.get(0) == 10);	
	assert(wavelet.get(1) == -5);	
	assert(wavelet.get(2) == 30);	
}


void testKth(){
	WaveletTree wavelet(-100, 100);
	wavelet.insert(0, 10);
	wavelet.insert(1, 20);
	wavelet.insert(2, 30);
	wavelet.insert(3, -5);
	wavelet.insert(4, 10);
	wavelet.insert(5, -4);

	assert(wavelet.kth(0, 6, 3) == 10);	
	assert(wavelet.kth(0, 6, 2) == -4);	
	assert(wavelet.kth(0, 6, 6) == 30);	

	assert(wavelet.kth(2, 5, 1) == -5);	
	assert(wavelet.kth(2, 5, 2) == 10);	
	assert(wavelet.kth(2, 5, 3) == 30);	
}

// void testTime(){
// 	clock_t init = clock();
// 	WaveletTree wavelet(-1000000000, 1000000000);
// 	for(int i=0;i<=100000; i++){
// 		if(i&1)
// 			wavelet.get(i>>1);
// 		else
// 			wavelet.insert(i>>1, i);
// 	}
// 	clock_t end = clock();

// 	assert( (end-init) <= 1*CLOCKS_PER_SEC );
// }

int main(){
	testOnlyQuery();
	testInsert();
	testErase();
	testKth();
//	testTime();
	return 0;
}