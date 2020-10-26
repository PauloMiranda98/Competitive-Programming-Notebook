#include "../../code/graph/articulation_point.h"

void test1(){
  AP::init(8);
  AP::addEdge(0, 1);
  AP::addEdge(1, 2);
  AP::addEdge(1, 3);
  AP::addEdge(2, 3);
  AP::addEdge(3, 4);
  AP::addEdge(6, 7);
  auto ret = AP::findArticulationPoint();
  vector<bool> ans = {0, 1, 0, 1, 0, 0, 0, 0};
  assert(ret == ans);
}

void test2(){ //AC: https://vjudge.net/problem/UVA-315
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;
    AP::init(n);
    cin.ignore();
    while(true){
      string line;
      getline(cin, line);
      if(line == "0")
        break;
      stringstream ss;
      ss << line;
      int a;
      ss >> a;
      int b;
      while(ss>>b)
        AP::addEdge(a-1, b-1);
    }
    auto isAP = AP::findArticulationPoint();
    int ans = 0;
    for(bool b: isAP)
      ans += b;
    cout << ans << endl;
  }
}

int main(){ 
  test1();
  //test2();
  return 0; 
}
