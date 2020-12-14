#include <bits/stdc++.h>
#include "../data_structures/union_find_with_rollback.h"
using ll = long long;
struct Edge { int a, b; ll w; };
struct Node { /// lazy skew heap node
  Edge key;
  Node *l, *r;
  ll delta;
  void prop() {
    key.w += delta;
    if (l) l->delta += delta;
    if (r) r->delta += delta;
    delta = 0;
  }
  Edge top() { prop(); return key; }
};
Node *merge(Node *a, Node *b) {
  if (!a || !b) return a ?: b;
  a->prop(), b->prop();
  if (a->key.w > b->key.w) swap(a, b);
  swap(a->l, (a->r = merge(b, a->r)));
  return a;
}
void pop(Node*& a) { a->prop(); a = merge(a->l, a->r); }
void free(vector<Node*> &v){
  for(auto &x: v)
    delete x;
}
// O(M * log(N))
pair<ll, vector<int>> dmst(int n, int r, vector<Edge>& g) {
  RollbackUF uf(n);
  vector<Node*> heap(n);
  vector<Node*> vf;
  for (Edge e : g){ 
    Node* node = new Node{e};
    vf.push_back(node);
    heap[e.b] = merge(heap[e.b], node);
  }
  ll res = 0;
  vector<int> seen(n, -1), path(n), par(n);
  seen[r] = r;
  vector<Edge> Q(n), in(n, {-1, -1}), comp;
  deque<tuple<int, int, vector<Edge>>> cycs;
  for(int s = 0; s < n; ++s) {
    int u = s, qi = 0, w;
    while (seen[u] < 0) {
      if (!heap[u]){
        free(vf);
        return {-1,{}};
      }
      Edge e = heap[u]->top();
      heap[u]->delta -= e.w, pop(heap[u]);
      Q[qi] = e, path[qi++] = u, seen[u] = s;
      res += e.w, u = uf.find(e.a);
      if (seen[u] == s) { /// found cycle, contract
        Node* cyc = 0;
        int end = qi, time = uf.time();
        do cyc = merge(cyc, heap[w = path[--qi]]);
        while (uf.unite(u, w));
        u = uf.find(u), heap[u] = cyc, seen[u] = -1;
        cycs.push_front({u, time, {&Q[qi], &Q[end]}});
      }
    }
    for(int i = 0; i < qi; ++i) in[uf.find(Q[i].b)] = Q[i];
  }
  for (auto& [u, t, c] : cycs) { // restore sol (optional)
    uf.rollback(t);
    Edge inEdge = in[u];
    for (auto& e : c) in[uf.find(e.b)] = e;
    in[uf.find(inEdge.b)] = inEdge;
  }
  for(int i = 0; i < n; ++i) par[i] = in[i].a;
  free(vf);
  return {res, par};
} 
//Careful with overflow
pair<ll, vector<int>> dmstAnyRoot(int n, vector<Edge> v) {
  ll maxEdge = 1000000010;
  ll INF = n*maxEdge;
  for(int i=0; i<n; i++)
    v.push_back(Edge({n, i, INF}));
  auto [ans, dad] = dmst(n+1, n, v);
  if(ans >= 0 and ans < 2*INF){
    for(int i=0; i<n; i++)
      if(dad[i] == n)
        dad[i] = -1;
    dad.pop_back();
    return {ans - INF, dad};
  }else{
    return {-1, {}};
  }
}