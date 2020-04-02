#include "../../code/data_structures/treap.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXX = 1000000000;
const int MAXOP = 100000;
enum op{
  INSERT = 0,
  ERASE = 1,
  COUNT = 2,
  NTH = 3
};

int randWithNeg(){
  if (rand() % 2)
    return (rand() % MAXX);
  else
    return -(rand() % MAXX);
}

void testTreap(){
  ordered_set st;
  Treap tp;
  int prev = 0;
  for (int k = 0; k < MAXOP; k++){
    int op = rand() % 4;
    if (op == INSERT){
      int x = randWithNeg();
      st.insert(x);
      tp.insert(x);
      prev = x;
    }else if (op == ERASE){
      int x = randWithNeg();
      st.erase(x);
      tp.erase(x);
      st.erase(prev);
      tp.erase(prev);
    }else if (op == COUNT){
      int x = randWithNeg();
      assert((st.find(x) != st.end()) == tp.count(x));
      assert((st.find(prev) != st.end()) == tp.count(prev));
    }else if (op == NTH){
      if (st.size() == 0)
        continue;
      int x = rand() % st.size();
      assert((*st.find_by_order(x)) == tp.nth(x + 1));
    }
    assert(st.size() == tp.size());
  }
  st.clear();
  tp.clear();
  assert(st.size() == tp.size());
}

int main(){
  testTreap();
  return 0;
}