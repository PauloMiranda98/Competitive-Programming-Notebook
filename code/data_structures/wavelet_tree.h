#include <bits/stdc++.h>
using namespace std;
struct WaveletTree{
private:
	typedef int t_wavelet;
  t_wavelet lo, hi;
	WaveletTree *l, *r;
	vector<int> a, b;
public:  
  template <class MyIterator>
	WaveletTree(MyIterator begin, MyIterator end, t_wavelet x, t_wavelet y){
		lo = x, hi = y;
		if(lo == hi or begin >= end) return;
		t_wavelet mid = (lo+hi-1)/2;
		auto f = [mid](int x){
			return x <= mid;
		};
    a.reserve(end-begin+1);
		b.reserve(end-begin+1);
		a.push_back(0); 
    b.push_back(0);
		for(auto it = begin; it != end; it++){
			a.push_back(a.back() + f(*it));
			b.push_back(b.back() + !f(*it));
    }
		auto pivot = stable_partition(begin, end, f);
		l = new WaveletTree(begin, pivot, lo, mid);
		r = new WaveletTree(pivot, end, mid+1, hi);
	} 
	//kth smallest element in range [l, r]
  //1-indexed
	int kth(int l, int r, int k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = a[r] - a[l-1];
		int lb1 = a[l-1] + 1, rb1 = a[r];
		int lb2 = b[l-1] + 1, rb2 = b[r];
		if(k <= inLeft) return this->l->kth(lb1, rb1, k);
		return this->r->kth(lb2, rb2, k-inLeft);
	} 
	//Amount of numbers in the range [l, r] Less than or equal to k
  //1-indexed
	int lte(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb1 = a[l-1] + 1, rb1 = a[r];
		int lb2 = b[l-1] + 1, rb2 = b[r];
		return this->l->lte(lb1, rb1, k) + this->r->lte(lb2, rb2, k);
	} 
	//Amount of numbers in the range [l, r] equal to k
  //1-indexed
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
    int mid = (lo+hi-1)/2;
		int lb1 = a[l-1]+1, rb1 = a[r];
		int lb2 = b[l-1]+1, rb2 = b[r];
		if(k <= mid) return this->l->count(lb1, rb1, k);
		return this->r->count(lb2, rb2, k);
	}
	~WaveletTree(){
		delete l;
		delete r;
	}
};