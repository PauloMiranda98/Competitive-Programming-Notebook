#include <bits/stdc++.h>
using namespace std;
int f(int x);
typedef pair<int, int> pii;
pii floydCycleFinding(int x0){
  int tortoise = f(x0), hare = f(f(x0));
  while(tortoise != hare){
    tortoise = f(tortoise);
    hare = f(f(hare));
  }
  int mu = 0;
  hare = x0;
  while(tortoise != hare){
    tortoise = f(tortoise);
    hare = f(hare);
    mu++;
  } 
  int lambda = 1;
  hare = f(tortoise);
  while(tortoise != hare){
    hare = f(hare);
    lambda++;
  }
  return pii(mu, lambda);
}
