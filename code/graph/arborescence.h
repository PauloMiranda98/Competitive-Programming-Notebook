#include <bits/stdc++.h>
#include "../data_structures/union_find.h"

using namespace std;
/**
 * Source: https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence.cc
 * Description: Edmonds' algorithm for finding the weight of the minimum spanning
 * tree/arborescence of a directed graph, given a root node. If no MST exists, returns -1.
 * Time: O(E \log V)
 */
typedef long long ll;
namespace Arborescence{
  struct Edge { int a, b; ll w; };
  struct Heap {
    Edge key;
    Heap *l, *r;
    ll delta;
    void prop() {
      key.w += delta;
      if (l) l->delta += delta;
      if (r) r->delta += delta;
      delta = 0;
    }
    Edge top() { prop(); return key; }
  };
  Heap *merge(Heap *a, Heap *b) {
    if (!a || !b) return a ?: b;
    a->prop(), b->prop();
    if (a->key.w > b->key.w) swap(a, b);
    swap(a->l, (a->r = merge(b, a->r)));
    return a;
  }
  void pop(Heap*& a) { a->prop(); a = merge(a->l, a->r); }

//public
  vector<Edge> g;
  void init(){
    g.clear();
  }
  void addEdge(int u, int to, ll w) {
    Edge e;
    e.a = u, e.b = to, e.w = w;
    g.push_back(e);
  }
  ll dmst(int n, int root) {
    UnionFind uf(n);
    vector<Heap*> heap(n);
    vector<Heap*> vp;
    for (Edge e : g){ 
      Heap* h = new Heap{e};
      vp.push_back(h);
      heap[e.b] = merge(heap[e.b], h);
    }
    ll res = 0;
    vector<int> seen(n, -1), path(n);
    seen[root] = root;
    for(int s=0; s<n; s++) {
      int u = s, qi = 0, w;
      while (seen[u] < 0) {
        path[qi++] = u, seen[u] = s;
        if (!heap[u]){
          for(Heap *h: vp)
            delete h;          
          return -1;
        }
        Edge e = heap[u]->top();
        heap[u]->delta -= e.w, pop(heap[u]);
        res += e.w; u = uf.find(e.a);
        if (seen[u] == s) {
          Heap* cyc = 0;
          do cyc = merge(cyc, heap[w = path[--qi]]);
          while (uf.join(u, w));
          u = uf.find(u);
          heap[u] = cyc, seen[u] = -1;
        }
      }
    }
    for(Heap *h: vp)
      delete h;
    return res;
  }
  //Careful with overflow
  ll dmstAnyRoot(int n) {
    ll maxEdge = 1000000010;    
    ll INF = n*maxEdge;
    for(int i=0; i<n; i++)
      addEdge(n, i, INF);
    ll ans = dmst(n+1, n);
    if(ans >= 0 and ans < 2*INF)
      return ans - INF;
    else
      return -1;
  }  
};