#include <bits/stdc++.h>
using namespace std;
const int K = 26;
struct Automaton{
  int n;
  vector<array<int, K>> to;
  vector<bool> accept;
  Automaton(int sz, bool acceptAll=true){
    to.assign(sz, {0});
    accept.assign(sz, acceptAll);
    n = sz;
  }
};
const int INTERSECT=0, UNION=1;
Automaton join(Automaton a, Automaton b, int op=INTERSECT){
  Automaton ret(a.n * b.n);
  for(int i=0; i<a.n; i++){
    for(int j=0; j<b.n; j++){
      int st = i * b.n + j;
      if(op == INTERSECT)
        ret.accept[st] = a.accept[i] and b.accept[j];
      else
        ret.accept[st] = a.accept[i] or b.accept[j];
      for(int k=0; k<K; k++)
        ret.to[st][k] = a.to[i][k] * b.n + b.to[j][k];
    }
  }
  return ret;
}