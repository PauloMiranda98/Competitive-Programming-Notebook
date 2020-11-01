#include "../../code/strings/z_function.h"

string s;
int bruteForceZ(int j){
  int i = 0, n = s.size();
  while((j < n) and (s[i] == s[j])){
    i++;
    j++;
  }
  return i;
}
void test1(){
  srand(2020);
  int n = 1000;
  s.resize(n);
  for(int i=0; i<n; i++)
    s[i] = 'a' + (rand()%15);
  auto z = z_function(s);
  for(int i=1; i<n; i++){
    assert(z[i] == bruteForceZ(i));
  }
}

void test2(){ // AC: https://cses.fi/problemset/task/1733/
  string t;
  cin >> t;
  auto z = z_function(t);
  int n = t.size();
  vector<int> ans;
  for(int i=1; i<n; i++){
    if(z[i] == (n-i))
      ans.push_back(i);
  }
  ans.push_back(n);
  for(int x: ans)
    cout << x << " ";
  cout << endl;  
}

int main() {
  for(int i=0; i<5; i++)
    test1();
    
//  test2();
  return 0;
}
