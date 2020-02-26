#include "../../code/data_structures/dynamic_wavelet_tree.h"

void testInsert(){
	Wavelet wavelet(-100, 100);
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
	Wavelet wavelet(-100, 100);
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
	Wavelet wavelet(-100, 100);
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

void testTime(){
	clock_t init = clock();
	Wavelet wavelet(-1000000000, 1000000000);
	for(int i=0;i<=100000; i++){
		if(i&1)
			wavelet.get(i>>1);
		else
			wavelet.insert(i>>1, i);
	}
	clock_t end = clock();

	assert( (end-init) <= 2*CLOCKS_PER_SEC );
}

int main(){
	testInsert();
	testErase();
	testKth();
	testTime();
	return 0;
}
