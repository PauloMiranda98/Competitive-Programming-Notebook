#include <bits/stdc++.h>
using namespace std;
class RangeColor{
private:
	typedef long long ll;
	struct Node{
		ll l, r;
		int color;
		Node(){}
		Node(ll l, ll r, int color):l(l), r(r), color(color){}
	};
	struct cmp{
		bool operator()(Node a, Node b){
			if(a.r == b.r) return a.l < b.l;
			return a.r < b.r;		
		}
	};
	std::set<Node, cmp> st;
	vector<ll> ans;
public:
	RangeColor(ll first, ll last, int maxColor){
		ans.resize(maxColor + 1);
		ans[0] = last - first + 1LL;
		st.insert(Node(first, last, 0));
	}
	//set newColor in [a, b]
	void set(ll a, ll b, int newColor){
		auto p = st.upper_bound(Node(0, a-1LL, -1));
		assert(p != st.end());		
		ll l = p->l;
		ll r = p->r;
		int oldColor = p->color;		
		ans[oldColor] -= (r - l + 1LL);
		p = st.erase(p);		
		if(l < a){						
			ans[oldColor] += (a - l);					
			st.insert(Node(l, a - 1LL, oldColor));
		}
		if(b < r){
			ans[oldColor] += (r - b);				
			st.insert(Node(b + 1LL, r, oldColor));					
		}			
		while( (p != st.end()) and (p->l <= b) ){
			l = p->l;
			r = p->r;
			oldColor = p->color;			
			ans[oldColor] -= (r - l + 1LL);
			if(b < r){
				ans[oldColor] += (r - b);					
				st.insert(Node(b + 1LL, r, oldColor));
				st.erase(p);
				break;
			}else{
				p = st.erase(p);
			}
		}
		ans[newColor] += (b - a + 1LL);
		st.insert(Node(a, b, newColor));
	}
	ll countColor(int x){
		return ans[x];
	}
};