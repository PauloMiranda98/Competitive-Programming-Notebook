#include <bits/stdc++.h>
using namespace std;
class SegTree{
private:
	typedef long long Node;
	Node neutral = 0;
	vector<Node> st;
	vector<int> v;
  int n;	
	Node join(Node a, Node b){
		return (a + b);
	}
	void build(int node, int i, int j){
		if(i == j){
			st[node] = v[i];
			return;
		}
		int m = (i+j)/2;		
		int l = (node<<1);
		int r = l + 1;		
		build(l, i, m);
		build(r, m+1, j);		
		st[node] = join(st[l], st[r]);
	}
	Node query(int node, int i, int j, int a, int b){
		if( (i>b) or (j<a) )
			return neutral;
		if( (a<=i) and (j<=b) )
			return st[node];			
		int m = (i+j)/2;		
		int l = (node<<1);
		int r = l + 1;		
		return join( query(l, i, m, a, b), query(r, m+1, j, a, b) );
	}
	void update(int node, int i, int j, int idx, Node value){
		if(i == j){
			st[node] = value;
			return;
		}		
		int m = (i+j)/2;		
		int l = (node<<1);
		int r = l + 1;		
		if(idx <= m)
			update(l, i, m, idx, value);
		else
			update(r, m+1, j, idx, value);		
		st[node] = join(st[l], st[r]);
	}
public:
  template <class MyIterator>
	SegTree(MyIterator begin, MyIterator end){
    n = end-begin;
    v = vector<int>(begin, end);
    st.resize(4*n + 5);
    build(1, 0, n-1);
  }
	//0-indexed [a, b]
	Node query(int a, int b){
    return query(1, 0, n-1, a, b);
	}	
	//0-indexed
  void update(int idx, int value){
    update(1, 0, n-1, idx, value);
  }
};