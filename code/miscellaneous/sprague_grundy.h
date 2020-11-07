#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int version;
int used[MAXN];
int mex() {
  for(int i=0; ; ++i)
    if(used[i] != version)
      return i;
}
int g[MAXN];
// Can remove 1, 2 and 3
void grundy(){
  //Base case depends on the problem
  g[0] = 0; 
  g[1] = 1;
  g[2] = 2;
  //Inductive case
  for(int i=3; i<MAXN; i++){
    version++;
    used[g[i-1]] = version;
    used[g[i-2]] = version;
    used[g[i-3]] = version;
    g[i] = mex();
  }
}
string solve(vector<int> v){
  grundy();
  int ans = 0;
  for(int x: v)
    ans ^= g[x];
  return ((ans != 0) ? "First" : "Second");
}
