#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int BLOCK_SIZE = 2800; // (2*N)^(2/3)
const int MAXN = 100010;
int v[MAXN];
void remove(int x);
void add(int x);
void clearAnswer();
int getAnswer();
struct Query{
  int l, r, t;
  bool operator<(const Query &oth) const{
    if (l / BLOCK_SIZE != oth.l / BLOCK_SIZE)
      return l < oth.l;
    if (r / BLOCK_SIZE != oth.r / BLOCK_SIZE)
      return r < oth.r;
    return t < oth.t;
  }
};
struct Update{
  int pos, newV, oldV, t;
};
//O(Q * N^(2/3)): N=10^5 -> 1.5s
vector<int> mo_s_algorithm(vector<Query> vq, vector<Update> vu){
  vector<pii> answers;
  sort(all(vq));
  clearAnswer();
  int L = 0, R = 0, T = 0, szT = vu.size();
  add(v[0]);
  for(Query q : vq){
    while(q.l < L) add(v[--L]);
    while(R < q.r) add(v[++R]);
    while(L < q.l) remove(v[L++]);
    while(q.r < R) remove(v[R--]);
    while(T < szT and vu[T].t <= q.t){
      Update &u = vu[T++];
      if(L <= u.pos and u.pos <= R){
        remove(u.oldV);
        add(u.newV);
      }
      v[u.pos] = u.newV;
    }
    while(T > 0 and vu[T-1].t > q.t){
      Update &u = vu[--T];
      if(L <= u.pos and u.pos <= R){
        remove(u.newV);
        add(u.oldV);
      }
      v[u.pos] = u.oldV;
    }
    answers.emplace_back(q.t, getAnswer());
  }
  sort(all(answers));
  vector<int> ret;
  for(auto [t, x]: answers) 
    ret.push_back(x);
  return ret;
}