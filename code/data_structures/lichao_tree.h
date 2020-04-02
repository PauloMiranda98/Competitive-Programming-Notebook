#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
class LiChaoTree{
private:
	typedef int t_line;
	struct Line{
		t_line k, b;
		Line() {}
		Line(t_line k, t_line b) : k(k), b(b) {}
	};
	int n_tree, min_x, max_x;
	vector<Line> li_tree;
	t_line f(Line l, int x){
		return l.k * x + l.b;
	}
	void add(Line nw, int v, int l, int r){
		int m = (l + r) / 2;
		bool lef = f(nw, l) > f(li_tree[v], l);
		bool mid = f(nw, m) > f(li_tree[v], m);
		if (mid)
			swap(li_tree[v], nw);
		if (r - l == 1)
			return;
		else if (lef != mid)
			add(nw, 2 * v, l, m);
		else
			add(nw, 2 * v + 1, m, r);
	}
	int get(int x, int v, int l, int r){
		int m = (l + r) / 2;
		if (r - l == 1)
			return f(li_tree[v], x);
		else if (x < m)
			return max(f(li_tree[v], x), get(x, 2 * v, l, m));
		else
			return max(f(li_tree[v], x), get(x, 2 * v + 1, m, r));
	}
public:
	LiChaoTree(int mn_x, int mx_x){
		min_x = mn_x;
		max_x = mx_x;
		n_tree = max_x - min_x + 5;
		li_tree.resize(4 * n_tree, Line(0, -INF));
	}
	void add(t_line k, t_line b){
		add(Line(k, b), 1, min_x, max_x);
	}
	t_line get(int x){
		return get(x, 1, min_x, max_x);
	}
};
