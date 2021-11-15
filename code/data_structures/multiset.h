#include <bits/stdc++.h>
using namespace std;
template<class T>
class MultiSet{
  map<T, int> mp;
  int sz = 0;
public:
  MultiSet(){}
  void insert(T x){
    sz++;
    mp[x]++;
  }
  void erase(T x){
    sz--;
    mp[x]--;
    if(mp[x] == 0){
      mp.erase(x);
    }
  }
  int count(T x){
    auto it = mp.find(x);
    if(it == mp.end())
      return 0;
    return it->second;
  }
  int min(){
    return mp.begin()->first;
  }
  int max(){
    return mp.rbegin()->first;
  }
  int size(){
    return sz;
  }
};
