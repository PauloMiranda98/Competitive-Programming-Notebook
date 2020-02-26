#include <bits/stdc++.h>
using namespace std;
struct SqrtDecomposition{
  typedef long long t_sqrt;
	int sqrtLen;
	vector<t_sqrt> block;
	vector<t_sqrt> v;
  template <class MyIterator>
	SqrtDecomposition(MyIterator begin, MyIterator end){
		int n = end-begin;
		sqrtLen = (int) sqrt (n + .0) + 1;
		v.resize(n);
		block.resize(sqrtLen + 5);
		for(int i=0; i<n; i++, begin++){
      v[i] = (*begin);
      block[i / sqrtLen] += v[i];	  
    }  
	}	
  //0-indexed
	void update(int idx, t_sqrt new_value){
		t_sqrt d = new_value - v[idx];
		v[idx] += d;
		block[idx/sqrtLen] += d;
	}
  //0-indexed [l, r]
	t_sqrt query(int l, int r){
		t_sqrt sum = 0;
		int c_l = l/sqrtLen, c_r = r/sqrtLen;
		if (c_l == c_r){
			for (int i=l; i<=r; i++)
				sum += v[i];
		}else{
			for (int i=l, end=(c_l+1)*sqrtLen-1; i<=end; i++)
				sum += v[i];
			for (int i=c_l+1; i<=c_r-1; i++)
				sum += block[i];
			for (int i=c_r*sqrtLen; i<=r; i++)
				sum += v[i];
		}		
		return sum;
	}	
};