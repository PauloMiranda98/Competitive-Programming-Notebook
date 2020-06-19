#include "../../code/data_structures/implicit_treap.h"

void testInsert(){
  ITreap::init();
  ITreap::insert(0, 10);
  ITreap::insert(1, 20);
  ITreap::insert(2, 30);
  ITreap::insert(1, 5);

  assert(ITreap::nth(0) == 10);
  assert(ITreap::nth(1) == 5);
  assert(ITreap::nth(2) == 20);
  assert(ITreap::nth(3) == 30);
}

void testErase(){
  ITreap::init();
  ITreap::insert(0, 10);
  ITreap::insert(1, 5);
  ITreap::insert(2, 20);
  ITreap::insert(3, 30);

  ITreap::erase(2);

  assert(ITreap::nth(0) == 10);
  assert(ITreap::nth(1) == 5);
  assert(ITreap::nth(2) == 30);
}

void testQuery(){
  ITreap::init();
  ITreap::insert(0, 10);
  ITreap::insert(1, 20);
  ITreap::insert(2, 30);
  ITreap::insert(3, 5);

  assert(ITreap::query(0, 2) == 60);
  assert(ITreap::query(1, 1) == 20);
  assert(ITreap::query(2, 3) == 35);
}

void testReverse(){
  ITreap::init();
  ITreap::insert(0, 10);
  ITreap::insert(1, 20);
  ITreap::insert(2, 30);
  ITreap::insert(3, 5);

  ITreap::reverse(1, 3);

  assert(ITreap::nth(0) == 10);
  assert(ITreap::nth(1) == 5);
  assert(ITreap::nth(2) == 30);
  assert(ITreap::nth(3) == 20);

  ITreap::reverse(1, 2);

  assert(ITreap::nth(0) == 10);
  assert(ITreap::nth(1) == 30);
  assert(ITreap::nth(2) == 5);
  assert(ITreap::nth(3) == 20);
}

int main(){
  testInsert();
  testErase();
  testQuery();
  testReverse();
  return 0;
}
