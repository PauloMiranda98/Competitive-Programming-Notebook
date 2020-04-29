#include "../../code/strings/min_cyclic_string.h"
string brute(string s){
  int n = s.size();
  string mn = s;
  s += s;
  for(int i=0; i<n; i++)
    mn = min(mn, s.substr(i, n));  
  return mn;
}
void test(){
  srand(time(0));
  int n = 1000;
  string s(n, 0);
  for (int i = 0; i < n; i++)
    s[i] = 'a' + rand() % 26;  
  assert(min_cyclic_string(s) == brute(s));
}
int main(){
  for(int i=0; i<10; i++)
    test();
  return 0;
}