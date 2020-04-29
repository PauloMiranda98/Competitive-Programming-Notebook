#include <bits/stdc++.h>
using namespace std;
const int BLOCK_SIZE = 700;
void remove(int idx);
void add(int idx);
void clearAnswer();
int getAnswer();
struct Query{
  int l, r, idx;
  bool operator<(Query other) const{
    if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
      return l < other.l;
    return (l / BLOCK_SIZE & 1) ? (r < other.r) : (r > other.r);
  }
};
vector<int> mo_s_algorithm(vector<Query> queries){
  vector<int> answers(queries.size());
  sort(queries.begin(), queries.end());
  clearAnswer();
  int L = 0, R = 0;
  add(0);
  for(Query q : queries){
    while(q.l < L) add(--L);
    while(R < q.r) add(++R);
    while(L < q.l) remove(L++);
    while(q.r < R) remove(R--);
    answers[q.idx] = getAnswer();
  }
  return answers;
}