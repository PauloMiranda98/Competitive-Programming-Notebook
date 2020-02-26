#include <bits/stdc++.h>
using namespace std;
class UnionFind{
private:
	vector<int> p, w, sz;
public:
	UnionFind(int n){    
    w.resize(n+1, 1);
    sz.resize(n+1, 1);
    p.resize(n+1);
    for(int i=0; i<=n; i++)
      p[i] = i; 
	}
	int find(int x){    
		if(p[x] == x)
			return x;		
		return p[x] = find(p[x]);
	}
	void join(int x, int y){    
		x = find(x);
		y = find(y);		
		if(x == y)
			return;			
		if(w[x] > w[y])
			swap(x, y);				
		p[x] = y;
		sz[y] += sz[x];		
		if(w[x] == w[y])
			w[y]++;			
	}	
	bool isSame(int x, int y){
		return find(x) == find(y);
	}
	int size(int x){
		return sz[find(x)];
	}
};