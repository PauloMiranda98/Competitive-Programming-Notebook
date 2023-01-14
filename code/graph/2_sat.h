#include "strongly_connected_component.h"
using namespace std;
struct SAT{
  typedef pair<int, int> pii;
  vector<pii> edges;
  int n;
  SAT(int size){
    n = 2 * size;
  }
  vector<bool> solve2SAT(){
    vector<bool> vAns(n / 2, false);
    vector<int> comp = SCC::scc(n, edges);
    for (int i = 0; i < n; i += 2){
      if (comp[i] == comp[i + 1])
        return vector<bool>();
      vAns[i / 2] = (comp[i] > comp[i + 1]);
    }
    return vAns;
  }
  int v(int x){
    if (x >= 0)
      return (x << 1);
    x = ~x;
    return (x << 1) ^ 1;
  }
  void add(int a, int b){
    edges.push_back(pii(a, b));
  }
  void addOr(int a, int b){
    add(v(~a), v(b));
    add(v(~b), v(a));
  }
  void addImp(int a, int b){
    addOr(~a, b);
  }
  void addEqual(int a, int b){
    addOr(a, ~b);
    addOr(~a, b);
  }
  void addDiff(int a, int b){
    addEqual(a, ~b);
  }
  
  // Using maxterms
  void addTruthTable(int a, int b, bool v00, bool v01, bool v10, bool v11){
    if(!v00)
      addOr(a, b);
    if(!v01)
      addOr(a, ~b);
    if(!v10)
      addOr(~a, b);
    if(!v11)
      addOr(~a, ~b);
  }
};
