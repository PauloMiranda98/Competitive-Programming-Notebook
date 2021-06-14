#include "../../code/data_structures/policy_based_tree.h"

void orderedSetTest(){
  ordered_set<int> st;
  st.insert(4);
  st.insert(1);
  st.insert(3);
  assert(*st.find_by_order(0) == 1);
  assert(*st.find_by_order(1) == 3);
  assert(*st.find_by_order(2) == 4);

  assert(st.order_of_key(1) == 0);
  assert(st.order_of_key(3) == 1);
  assert(st.order_of_key(4) == 2);
}

void orderedMapTest(){
  ordered_map<int, int> mp;
  mp[4] = 1;
  mp[1] = -2;
  mp[3] = 0;
  assert(mp.find_by_order(0)->first == 1);
  assert(mp.find_by_order(0)->second == -2);
  assert(mp.find_by_order(1)->first == 3);
  assert(mp.find_by_order(1)->second == 0);
  assert(mp.find_by_order(2)->first == 4);
  assert(mp.find_by_order(2)->second == 1);

  assert(mp.order_of_key(1) == 0);
  assert(mp.order_of_key(3) == 1);
  assert(mp.order_of_key(4) == 2);
}

int main(){
  orderedSetTest();
  orderedMapTest();
  return 0;
}
