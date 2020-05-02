#include "../../code/strings/suffix_automaton.h"
string brute(string s, string t){
  int n = s.size();
  string ans;
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      if( (j-i+1) > ans.size() and t.find(s.substr(i, j-i+1)) != -1)
        ans = s.substr(i, j-i+1);      
    }
  }
  return ans;
}
void test(){
  srand(time(0));
  int n = 500;
  string s(n, 0), t(n, 0);
  for (int i = 0; i < n; i++){
    s[i] = 'a' + rand() % 26; 
    t[i] = 'a' + rand() % 26;
  } 
  SuffixAutomaton sa(s);
  assert(sa.lcs(t) == brute(t, s));
}
int main(){
  for(int i=0; i<10; i++)
    test();
  return 0;
}