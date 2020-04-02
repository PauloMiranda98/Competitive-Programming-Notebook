#include <bits/stdc++.h>
using namespace std;
class BitRange{
private:
	typedef long long t_bit;
	vector<t_bit> bit1, bit2;
	t_bit get(vector<t_bit> &bit, int i){
		t_bit sum = 0;
		for (; i > 0; i -= (i & -i))
			sum += bit[i];
		return sum;
	}
	void add(vector<t_bit> &bit, int i, t_bit value){
		for (; i < (int)bit.size(); i += (i & -i))
			bit[i] += value;
	}
public:
	BitRange(int n){
		bit1.assign(n + 1, 0);
		bit2.assign(n + 1, 0);
	}
	//1-indexed [i, j]
	void add(int i, int j, t_bit v){
		add(bit1, i, v);
		add(bit1, j + 1, -v);
		add(bit2, i, v * (i - 1));
		add(bit2, j + 1, -v * j);
	}
	//1-indexed
	t_bit get(int i){
		return get(bit1, i) * i - get(bit2, i);
	}
	//1-indexed [i,j]
	t_bit get(int i, int j){
		return get(j) - get(i - 1);
	}
};
