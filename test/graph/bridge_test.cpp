#include "../../code/graph/bridge.h"

void test1(){
  Bridge::init(8);
  Bridge::addEdge(0, 1);
  Bridge::addEdge(1, 2);
  Bridge::addEdge(1, 3);
  Bridge::addEdge(2, 3);
  Bridge::addEdge(3, 4);
  Bridge::addEdge(6, 7);
  auto ret = Bridge::findBridges();
  for(auto &p: ret)
    if(p.first > p.second) swap(p.first, p.second);
  sort(ret.begin(), ret.end());
  vector<pii> ans = {pii(0, 1), pii(3, 4), pii(6, 7)};
  assert(ret == ans);
}

void test2(){ //AC: https://vjudge.net/problem/UVA-796
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while(cin >> n){
    Bridge::init(n);
    for(int i=0; i<n; i++){
      int a, k;
      char c;
      cin >> a >> c >> k >> c;
      while(k--){
        int b;
        cin >> b;
        if(a < b)
          Bridge::addEdge(a, b);
      }
    }    
    auto ans = Bridge::findBridges();
    for(pii &p: ans)
      if(p.first > p.second) swap(p.first, p.second);
    sort(ans.begin(), ans.end());
    cout << ans.size() << " critical links" << endl;
    for(pii p: ans)
      cout << p.first << " - " << p.second << endl;
    cout << endl;
  }
}

int main(){ 
  test1();
  //test2();
  return 0; 
}