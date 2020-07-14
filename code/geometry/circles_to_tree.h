#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; 
struct Circle{
  int x, y, r, id;
  Circle(){}
  Circle(int x1, int y1, int r1, int id1): x(x1), y(y1), r(r1), id(id1){}
};
// a^2 + b^2 == c^2
double findB(double a, double c){
  return sqrt(c*c - a*a);
}
//- There is no intersection between the circles
//- The parent of circle i will be the smallest circle that includes i
namespace CirclesToTree{
  int X = 0;
  int n;
  vector<Circle> vc;  
  vector<int> p;
  struct SetElement{
    int id;
    int side; //Up:1, Down:-1 
    SetElement(int id1, int side1): id(id1), side(side1){};
    double getY(int x = X) const{
      return vc[id].y + side*findB(vc[id].x - x, vc[id].r);
    }
    bool operator <(const SetElement &o) const{
      auto l = getY(), r = o.getY();
      if(abs(l-r)<1e-9)
        return vc[id].r*side < vc[o.id].r*o.side;
      else
        return l < r;
    }
  };
  long long pw2(int a){
    return a*1LL*a;
  }
  bool contains(int big, int small){
    if(big == -1 or small == -1) return false;
    Circle &s = vc[small], &b = vc[big];
    if(s.r > b.r) return false;
    return pw2(s.x-b.x) + pw2(s.y-b.y) <= pw2(b.r-s.r);
  }
  void updateParent(int id, int par){
    if(par != -1 and p[id] == -1) p[id] = par; 
  }
//Public
  vector<vector<int>> solve(vector<Circle> circles){
    vc = circles; n = vc.size();
    p.assign(n, -1);
    vector<vector<int>> adj(n, vector<int>());
    vector<pii> events;
    for(auto c: vc){
      events.emplace_back(c.x-c.r, ~c.id);
      events.emplace_back(c.x+c.r, c.id);
    }
    sort(events.begin(), events.end());
    set<SetElement> st;
    for(auto e: events){
      X = e.first;
      int id = e.second;
      if(id < 0){
        id = ~id;
        auto it = st.lower_bound(SetElement(id, -2));
        if(it != st.end()){
          int id2 = it->id;
          if(contains(id2, id)) updateParent(id, id2);
          if(contains(p[id2], id)) updateParent(id, p[id2]);
        }
        if(it != st.begin()){
          it--;
          int id2 = it->id;
          if(contains(id2, id)) updateParent(id, id2);
          if(contains(p[id2], id)) updateParent(id, p[id2]);
        }
        st.emplace(id, 1);
        st.emplace(id, -1);
        if(p[id] != -1){
          adj[p[id]].push_back(id);
        }
      }else{
        st.erase(SetElement(id, 1));
        st.erase(SetElement(id, -1));
      }
    }
    return adj;
  }
};
