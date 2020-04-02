#include <bits/stdc++.h>
using namespace std;
class Bit{
private:
	typedef long long t_bit;
	int nBit;
	int nLog;
	vector<t_bit> bit;
public:
	Bit(int n){
		nBit = n;
		nLog = 20;
		bit.resize(nBit + 1, 0);
	}
	//1-indexed
	t_bit get(int i){
		t_bit s = 0;
		for (; i > 0; i -= (i & -i))
			s += bit[i];
		return s;
	}
	//1-indexed [l, r]
	t_bit get(int l, int r){
		return get(r) - get(l - 1);
	}
	//1-indexed
	void add(int i, t_bit value){
		for (; i <= nBit; i += (i & -i))
			bit[i] += value;
	}
	t_bit position(t_bit value){
		t_bit sum = 0;
		int pos = 0;
		for (int i = nLog; i >= 0; i--){
			if ((pos + (1 << i) <= nBit) and (sum + bit[pos + (1 << i)] < value)){
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}
};
