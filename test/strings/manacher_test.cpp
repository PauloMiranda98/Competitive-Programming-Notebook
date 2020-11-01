#include "../../code/strings/manacher.h"
string s;
bool isPalindrome(int i, int j){
  while(i < j)
    if(s[i++] != s[j--])
      return false;
  return true;
}
void test1(){
  srand(2020);
  int n = 1000;
  s.resize(n);
  for(int i=0; i<n; i++)
    s[i] = 'a' + (rand()%26);
  Palindrome p(s);
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      assert(isPalindrome(i, j) == p.isPalindrome(i, j));
    }
  }
}

void test2(){ // AC: https://cses.fi/problemset/task/1111
  string t;
  cin >> t;
  auto man = manacher(t);
  int i = max_element(man.begin(), man.end()) - man.begin();
  int p = i/2, sz = man[i];
  if(i%2 == 0){
    cout << s.substr(p - sz/2, sz) << endl;
  }else{
    cout << s.substr(p - sz/2 + 1, sz) << endl;
  }
}

int main() {
  test1();
//  test2();
  return 0;
}
