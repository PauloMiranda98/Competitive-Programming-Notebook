#include <bits/stdc++.h>
using namespace std;

typedef int f_type;
struct Node{
  f_type value;
  Node *l, *r;
  Node(f_type x = 0): value(x){
    l = r = nullptr;
  }
};
inline bool heapMin(f_type a, f_type b){
  return a > b;
}
inline bool heapMax(f_type a, f_type b){
  return a < b; 
}
struct RandomizedHeap{
  Node *root;
  int sz;
  RandomizedHeap(){
    srand(time(NULL));
    root = nullptr;
    sz = 0;
  }
  void rdFree(Node *n){
    if(n == nullptr) return;
    rdFree(n->l); rdFree(n->r);
    delete n;
  }
  ~RandomizedHeap(){
    rdFree(root);
  }
  Node* merge(Node *t1, Node *t2) {
    if(!t1 || !t2)
      return t1 ? t1 : t2;
    if(heapMin(t1->value, t2->value))
      swap(t1, t2);
    if(rand() & 1)
      swap(t1->l, t1->r);
    t1->l = merge(t1->l, t2);
    return t1;
  } 
  //Can be performed in O(logn) on average.
  void merge(RandomizedHeap &oth){
    root = merge(root, oth.root);
    sz += oth.sz;
    oth.root = nullptr;
  }
  int top(){
    return (root != nullptr) ? root->value : 0;
  }
  void pop(){
    if(root == nullptr) return;
    Node *l = root->l;
    Node *r = root->r;
    delete root;
    root = merge(l, r);
    sz--;
  } 
  void push(int x){
    Node *nw = new Node(x);
    root = merge(root, nw);
    sz++;
  }
  int size(){
    return sz;
  }
};
