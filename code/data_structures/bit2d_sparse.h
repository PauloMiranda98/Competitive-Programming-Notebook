#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;
const int MAXN = 200001;
// Time complexity : O(Q * log(N)^2)
// Space complexity : O(Q * log(N))
namespace Bit2d{
  OST bit[MAXN];
  void add(int x, int y){
    for(int i = x; i < MAXN; i += i & -i)
      bit[i].insert(mp(y, x));
  }
  void remove(int x, int y){
    for(int i = x; i < MAXN; i += i & -i)
      bit[i].erase(mp(y, x));
  }
  int get(int x, int y){
    int ans = 0;
    for(int i = x; i > 0; i -= i & -i)
      ans += bit[i].order_of_key(mp(y+1, 0));
    return ans;
  }
	int get(int a1, int b1, int a2, int b2){
		return get(a2, b2) - get(a2, b1 - 1) - get(a1 - 1, b2) + get(a1 - 1, b1 - 1);
	}
};