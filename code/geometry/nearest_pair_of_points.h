#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y, id;
  pt(){}
  pt(int _x, int _y, int _id=-1):x(_x), y(_y), id(_id){}
};
namespace NearestPairOfPoints{
  struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
      return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
  };
  struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
      return a.y < b.y;
    }
  };
  int n;
  vector<pt> v;
  vector<pt> t;
  double mindist;
  pair<int, int> best_pair;
  void upd_ans(const pt & a, const pt & b) {
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
      mindist = dist;
      best_pair = {a.id, b.id};
    }
  }
  void rec(int l, int r) {
    if (r - l <= 3) {
      for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
          upd_ans(v[i], v[j]);
        }
      }
      sort(v.begin() + l, v.begin() + r, cmp_y());
      return;
    }
    int m = (l + r) >> 1;
    int midx = v[m].x;
    rec(l, m);
    rec(m, r);
    merge(v.begin() + l, v.begin() + m, v.begin() + m, v.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, v.begin() + l);
    int tsz = 0;
    for (int i = l; i < r; ++i) {
      if (abs(v[i].x - midx) < mindist) {
        for (int j = tsz - 1; j >= 0 && v[i].y - t[j].y < mindist; --j)
          upd_ans(v[i], t[j]);
        t[tsz++] = v[i];
      }
    }
  }
  pair<int, int> solve(vector<pt> _v){
    v = _v;
    n = v.size();
    t.resize(n);
    sort(v.begin(), v.end(), cmp_x());
    mindist = 1E20;
    rec(0, n);
    return best_pair;
  }
};
