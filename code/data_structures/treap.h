#include <bits/stdc++.h>
using namespace std;
class Treap {
private:
  typedef int t_treap;
  struct Node {
    t_treap x, y, size;
    Node *l, *r;
    Node(t_treap _x) : x(_x), y(rand()), size(1), l(NULL), r(NULL){}	
  };
	Node* root;
	int size(Node* t) { return t ? t->size : 0; }
	Node* refresh(Node* t) {
		if (!t) return t;
		t->size = 1 + size(t->l) + size(t->r);
		return t;
	}
	void split(Node* &t, t_treap k, Node* &a, Node* &b) {
		Node* aux;
		if(!t){
      a = b = NULL;
		}else if(t->x < k) {
			split(t->r, k, aux, b);
			t->r = aux;
			a = refresh(t);
		}else{
			split(t->l, k, a, aux);
			t->l = aux;
			b = refresh(t);
		}
	}
	Node* merge(Node* a, Node* b) {
		if (!a || !b) return a ? a : b;
		if (a->y < b->y) {
			a->r = merge(a->r, b);
			return refresh(a);
		}
		else {
			b->l = merge(a, b->l);
			return refresh(b);
		}
	}
	Node* count(Node* t, t_treap k) {
		if (!t) return NULL;
		else if (k < t->x) return count(t->l, k);
		else if (k == t->x) return t;
		else return count(t->r, k);
	}
	Node* nth(Node* t, int n) {
		if (!t) return NULL;
		if (n <= size(t->l)) return nth(t->l, n);
		else if (n == size(t->l) + 1) return t;
		else return nth(t->r, n-size(t->l)-1);
	}
	void del(Node* &t) {
		if (!t) return;
		if (t->l) del(t->l);
		if (t->r) del(t->r);
		delete t;
		t = NULL;
	}
public:
	Treap() : root(NULL) {}
	~Treap() { clear(); }
	void clear() { del(root); }
	int size() { return size(root); }
	bool count(t_treap k) { return count(root, k) != NULL; }
	bool insert(t_treap k) {
		if (count(k)) return false;
		Node *a, *b;
		split(root, k, a, b);
		root = merge(merge(a, new Node(k)), b);
		return true;
	}
	bool erase(t_treap k) {
		Node * f = count(root, k);
		if (!f) return false;
		Node *a, *b, *c, *d;
		split(root, k, a, b);
		split(b, k+1, c, d);
		root = merge(a, d);
		delete f;
		return true;
	}
  //1-indexed
	t_treap nth(int n) {
		Node* ans = nth(root, n);
		return ans ? ans->x : -1;
	}
};