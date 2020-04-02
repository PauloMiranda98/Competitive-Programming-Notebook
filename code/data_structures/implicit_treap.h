#include <bits/stdc++.h>
using namespace std;
class ImplicitTreap{
private:
	typedef int t_treap;
	const t_treap neutral = 0;
	inline t_treap join(t_treap a, t_treap b, t_treap c){
		return a + b + c;
	}
	struct Node{
		int y, size;
		t_treap v, op_value;
		bool rev;
		Node *l, *r;
		Node(t_treap _v){
			v = op_value = _v;
			y = rand();
			size = 1;
			l = r = NULL;
			rev = false;
		}
	};
	Node *root;
	int size(Node *t) { return t ? t->size : 0; }
	t_treap op_value(Node *t) { return t ? t->op_value : neutral; }
	Node *refresh(Node *t){
		if (t == NULL)
			return t;
		t->size = 1 + size(t->l) + size(t->r);
		t->op_value = join(t->v, op_value(t->l), op_value(t->r));
		if (t->l != NULL)
			t->l->rev ^= t->rev;
		if (t->r != NULL)
			t->r->rev ^= t->rev;
		if (t->rev){
			swap(t->l, t->r);
			t->rev = false;
		}
		return t;
	}
	void split(Node *&t, int k, Node *&a, Node *&b){
		refresh(t);
		Node *aux;
		if (!t){
			a = b = NULL;
		}else if (size(t->l) < k){
			split(t->r, k - size(t->l) - 1, aux, b);
			t->r = aux;
			a = refresh(t);
		}else{
			split(t->l, k, a, aux);
			t->l = aux;
			b = refresh(t);
		}
	}
	Node *merge(Node *a, Node *b){
		refresh(a);
		refresh(b);
		if (!a || !b)
			return a ? a : b;
		if (a->y < b->y){
			a->r = merge(a->r, b);
			return refresh(a);
		}else{
			b->l = merge(a, b->l);
			return refresh(b);
		}
	}
	Node *at(Node *t, int n){
		if (!t)
			return t;
		refresh(t);
		if (n < size(t->l))
			return at(t->l, n);
		else if (n == size(t->l))
			return t;
		else
			return at(t->r, n - size(t->l) - 1);
	}
	void del(Node *&t){
		if (!t)
			return;
		if (t->l)
			del(t->l);
		if (t->r)
			del(t->r);
		delete t;
		t = NULL;
	}
public:
	ImplicitTreap() : root(NULL){
		srand(time(NULL));
	}
	~ImplicitTreap() { clear(); }
	void clear() { del(root); }
	int size() { return size(root); }
	//0-indexed
	bool insert(int n, int v){
		Node *a, *b;
		split(root, n, a, b);
		root = merge(merge(a, new Node(v)), b);
		return true;
	}
	//0-indexed
	bool erase(int n){
		Node *a, *b, *c, *d;
		split(root, n, a, b);
		split(b, 1, c, d);
		root = merge(a, d);
		if (c == NULL)
			return false;
		delete c;
		return true;
	}
	//0-indexed
	t_treap at(int n){
		Node *ans = at(root, n);
		return ans ? ans->v : -1;
	}
	//0-indexed [l, r]
	t_treap query(int l, int r){
		if (l > r)
			swap(l, r);
		Node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r - l + 1, b, c);
		t_treap ans = op_value(b);
		root = merge(a, merge(b, c));
		return ans;
	}
	//0-indexed [l, r]
	void reverse(int l, int r){
		if (l > r)
			swap(l, r);
		Node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r - l + 1, b, c);
		if (b != NULL)
			b->rev ^= 1;
		root = merge(a, merge(b, c));
	}
};
