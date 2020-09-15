#include "../../code/strings/hashing.h"
void test(){
  srand(time(0));
  int n = 500;
  string s(n, 0), t(n, 0);
  for (int i = 0; i < n; i++){
    s[i] = 'a' + rand() % 26; 
    t[i] = 'a' + rand() % 26; 
  } 
  StringHashing sh_s(s), sh_t(t);
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      bool a = sh_s.getValue(i, j) == sh_t.getValue(i, j);
      bool b = s.substr(i, j-i+1) == t.substr(i, j-i+1);
      assert(a == b);
    }
  }
}
int main(){
  for(int i=0; i<5; i++)
    test();
  return 0;
}