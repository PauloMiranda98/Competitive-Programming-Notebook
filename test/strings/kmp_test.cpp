#include "../../code/strings/kmp.h"

void test1(){
  assert(true); // AC: https://codeforces.com/contest/808/submission/97043263  
  assert(true); // AC: https://codeforces.com/contest/471/submission/61944132
  assert(true); // AC: https://codeforces.com/contest/432/submission/97050237
}
void test2(){
  vector<int> pi = kmp("abcabcd");
  vector<int> ans = {0,0,0,1,2,3,0};
  assert(pi == ans);
}
void test3(){
  vector<int> pi = kmp("aabaaab");
  vector<int> ans = {0,1,0,1,2,2,3};
  assert(pi == ans);
}
void test4(){
  string s = "aabaaab";
  vector<int> prefix = prefixOccurrences(s);
  vector<int> ans = {5,3,2,1,1,1,1};
  assert(prefix == ans);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}
