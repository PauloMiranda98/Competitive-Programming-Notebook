#include "../../code/strings/suffix_tree.h"

void test1(){
  SuffixTree::init();
  string s = "paulomiranda";
  SuffixTree::add_string(s);
  for(int i=0; i<(int)s.size(); i++){
    for(int j=0; j<(int)s.size(); j++){
      string q = s.substr(i, j-i+1);
      assert(SuffixTree::match(q) == true);
    }
  }
  srand(98);
  for(int i=0; i<=100; i++){
    string t(5, 'a');
    for(int j=0; j<5; j++)
      t[j] = rand()%26;
    bool ans = (s.find(t) != -1);
    assert(SuffixTree::match(t) == ans);
  }
}

void test2(){
  SuffixTree::init();
  string s = "paulomiranda"; 
  string s1 = "paulo", s2 ="miranda";
  SuffixTree::add_string(s1);
  SuffixTree::add_string(s2);
  for(int i=0; i<(int)s.size(); i++){
    for(int j=0; j<(int)s.size(); j++){
      string q = s.substr(i, j-i+1);
      bool ans = false;
      ans |= (s1.find(q) != -1);
      ans |= (s2.find(q) != -1);
      assert(SuffixTree::match(q) == ans);
    }
  }
  srand(98);
  for(int i=0; i<=100; i++){
    string t(5, 'a');
    for(int j=0; j<5; j++)
      t[j] = rand()%26;
    bool ans = false;
    ans |= (s1.find(t) != -1);
    ans |= (s2.find(t) != -1);
    assert(SuffixTree::match(t) == ans);
  }
}

int main() {
  test1();
  test2();
  return 0;
}
