#include "../../code/data_structures/randomized_heap.h"

void test1(){
  RandomizedHeap rd;
  priority_queue<int, vector<int>, greater<int>> pq;
  srand(98);
  for(int i=0; i<50000; i++){
    int op = rand()%3;
    assert(pq.size() == rd.size());

    if(op == 0){
      int x = rand();
      pq.push(x);
      rd.push(x);
    }else if(op == 1){
      if(pq.size() > 0){
        pq.pop();
        rd.pop();
      }
    }else if(op == 2){
      if(pq.size() > 0)
        assert(pq.top() == rd.top());
    }
  }  
}
int main() {  
  
  return 0;
}

