#include <bits/stdc++.h>
using namespace std;
struct SplayTree{
	struct Node{
		int x, y, s;
		Node *p = 0;
		Node *l = 0;
		Node *r = 0;
		Node(int v){
			x = v;
			y = v;
			s = 1;
		}
		void upd(){
			s = 1;
			y = x;
			if(l) {
				y += l->y;
				s += l->s;
			}
			if(r) {
				y += r->y;
				s += r->s;
			}
		}
		int left_size(){
			return l ? l->s : 0;
		}
	};
	Node *root = 0;
	void rot(Node *c) {
		auto p = c->p;
		auto g = p->p;
		if(g)(g->l == p ? g->l : g->r) = c;
		if(p->l == c) {
			p->l = c->r;
			c->r = p;
			if(p->l) p->l->p = p;
		}else{
			p->r = c->l;
			c->l = p;
			if(p->r) p->r->p = p;
		}
		p->p = c;
		c->p = g;
		p->upd();
		c->upd();
	}
	void splay(Node *c) {
		while(c->p) {
			auto p = c->p;
			auto g = p->p;
			if(g) rot((g->l == p) == (p->l == c) ? p : c);
			rot(c);
		}
		c->upd();
		root = c;
	}
	Node* join(Node *l, Node *r) {
		if(not l) return r;
		if(not r) return l;
		while(l->r) l = l->r;
		splay(l);
		r->p = l;
		l->r = r;
		l->upd();
		return l;
	}
	pair<Node*, Node*> split(Node *p, int idx) {
		if(not p)
			return make_pair(nullptr, nullptr);
		if(idx < 0)
			return make_pair(nullptr, p);
		if(idx >= p->s)
			return make_pair(p, nullptr);
		for(int lf = p->left_size(); idx != lf; lf = p->left_size()) {
			if(idx < lf)
				p = p->l;
			else
				p = p->r, idx -= lf+1;
		}
		splay(p);
		Node *l = p;
		Node *r = p->r;
		if(r) {
			l->r = r->p = 0;
			l->upd();
		}
		return make_pair(l, r);
	}
	Node* get(int idx) {
		auto p = root;
		for(int lf = p->left_size(); idx != lf; lf = p->left_size()) {
			if(idx < lf)
				p = p->l;
			else
				p = p->r, idx -= lf+1;
		}
		splay(p);
		return p;
	}
	int insert(int idx, int x) {
		Node *l, *r;
		tie(l, r) = split(root, idx-1);
		int v = l ? l->y : 0;
		root = join(l, join(new Node(x), r));
		return v;
	}
	void erase(int idx) {
		Node *l, *r;
		tie(l, r) = split(root, idx);
		root = join(l->l, r);
		delete l;
	}
	int rank(int idx) {
		Node *l, *r;
		tie(l, r) = split(root, idx);
		int x = (l && l->l ? l->l->y : 0);
		root = join(l, r);
		return x;
	}
	int operator[](int idx) {
		return rank(idx);
	}
	~SplayTree() {
		if(!root)
			return;
		vector<Node*> nodes {root};
		while(nodes.size()) {
			auto u = nodes.back();
			nodes.pop_back();
			if(u->l) nodes.emplace_back(u->l);
			if(u->r) nodes.emplace_back(u->r);
			delete u;
		}
	}
};
class Wavelet{
private:
	int A, Z;
	Wavelet *l = 0;
	Wavelet *r = 0;
	SplayTree b;
public:	
	Wavelet(int min_value, int max_value) {
		A = min_value;
		Z = max_value;
		b.insert(0, 0);
	}
	~Wavelet() {
		delete l;
		delete r;
	}
	//0-indexed
	void insert(int idx, int x) {
		if(A >= Z)
			return;
		int M = (A + Z - 1) / 2;    
		if(x <= M) {
			l = l ?: new Wavelet(A, M);
			l->insert(b.insert(idx, 1), x);
		}else{
			r = r ?: new Wavelet(M+1, Z);
			r->insert(idx - b.insert(idx, 0), x);
		}
	}
	//0-indexed
	void erase(int idx) {
		if(A == Z)
			return;
		auto p = b.get(idx);
		int lf = p->l ? p->l->y : 0;
		int x = p->x;
		b.erase(idx);
		if(x == 1)
			l->erase(lf);
		else
			r->erase(idx-lf);
	}
	//kth [l, r[
	int kth(int L, int R, int k) {
		if(A == Z)
			return A;
		int x = b.rank(L);
		int y = b.rank(R);
		if(k <= y-x)
			return l->kth(x, y, k);
		else
			return r->kth(L-x, R-y, k-(y-x));
	}
	//0-indexed
	int get(int idx){
		return kth(idx, idx+1, 1);
	}
};
