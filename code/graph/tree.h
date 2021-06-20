#include "../data_structures/rmq.h"
// build: O(N), queries: O(1)
template<typename T> class Tree{
private:
  typedef pair<int, T> Edge;
  vector<vector<Edge>> adj;
  vector<int> v, level, in;
  vector<T> sum;
  RMQ<T> *rmq = nullptr;
  int n;
  void dfs(int u, int p, int d, T s){
    in[u] = v.size();
    v.push_back(u);
    level.push_back(d);
    sum[u] = s;
    for (auto [to, w] : adj[u]) if(to != p){
      dfs(to, u, d + 1, s + w);
      v.push_back(u);
      level.push_back(d);
    }
  }
public:  
  ~Tree(){
    if(rmq != nullptr)
      delete rmq;
  }
  void init(int n1){
    n = n1;
    adj.assign(n, vector<Edge>());
    in.resize(n);
    sum.resize(n);
  }
  void addEdge(int a, int b, T w = 1){
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
  void build(int root = 0){
    v.clear(); level.clear();
    dfs(root, -1, 0, 0);
    if(rmq != nullptr)
      delete rmq;
    rmq = new RMQ<int>(level);
  }
  //O(1)
  int lca(int a, int b){
    a = in[a], b = in[b];
    if(a > b)
      swap(a, b);
    return v[rmq->getPos(a, b)];
  }
  //O(1)
  T dist(int a, int b){
    return sum[a] + sum[b] - 2*sum[lca(a, b)];
  }
};