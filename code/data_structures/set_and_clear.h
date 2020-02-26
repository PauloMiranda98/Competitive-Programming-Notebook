#include <bits/stdc++.h>
using namespace std;
class SetAndClear{
private:
  typedef long long ll;
  typedef pair<ll, ll> pii;
	struct cmp{
		bool operator()(pii a, pii b){
			return a.second < b.second;		
		}
	};
	std::set<pii, cmp> st;
	ll ans;
public:
	SetAndClear(ll first, ll last){
		ans = last - first + 1LL;
    clear(first, last);
	}
	//set [a, b]
	void set(ll a, ll b){
		auto p = st.upper_bound(pii(0, a-1LL));
		if( (p == st.end()) or (p->first > b) ){
			return;
		}else{
			ll x = p->first;
			ll y = p->second;
			ans += (y - x + 1LL);
			p = st.erase(p);		
			if(x<=(a - 1LL)){						
				ans -= (a - x);					
				st.insert(pii(x, a - 1LL));
			}
			if( (b + 1LL) <= y){
				ans -= (y - b);				
				st.insert(pii(b + 1LL, y));					
			}			
			while( (p != st.end()) and (p->first <= b) ){
				x = p->first;
				y = p->second;
				ans += (y - x + 1LL);
				if(y > b){
					ans -= (y - b);					
					st.erase(p);
					st.insert(pii(b + 1LL, y));
					break;
				}else{
					p = st.erase(p);
				}
			}			
		}		
	}
	//clear [a, b]
	void clear(ll a, ll b){
		auto p = st.upper_bound(pii(0, a-1LL));
		if( (p == st.end()) or (p->first > b) ){
			ans -= (b - a + 1LL);
			st.insert(pii(a, b));
		}else{
			ll x = p->first;
			ll y = p->second;
			ans += (y - x + 1LL);
			p = st.erase(p);
			a = min(x, a);
			b = max(y, b);				
			while( (p != st.end()) and (p->first <= b) ){
				x = p->first;
				y = p->second;
				ans += (y - x + 1LL);
				a = min(x, a);
				b = max(y, b);				
				p = st.erase(p);
			}			
			ans -= (b - a + 1LL);
			st.insert(pii(a, b));									
		}		
	}	
	ll count(){
		return ans;
	}
};