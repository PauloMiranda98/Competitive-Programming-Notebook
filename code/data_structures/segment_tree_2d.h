#include <bits/stdc++.h>
using namespace std;
//Procurar uma versão mais otimizada
struct SegTree2D{
private:
  int n, m;
  typedef int Node;
  Node neutral = -0x3f3f3f3f;
  vector<vector<Node>> seg;
  Node join(Node a, Node b){
    return max(a, b);
  }
public:
  SegTree2D(int n1, int m1){
    n = n1, m = m1;
    seg.assign(2 * n, vector<Node>(2 * m, 0));
  }
  void update(int x, int y, int val){
    assert(0 <= x && x < n && 0 <= y && y < m);
    x += n, y += m;
    seg[x][y] = val;
    for (int j = y / 2; j > 0; j /= 2)
      seg[x][j] = join(seg[x][2 * j], seg[x][2 * j + 1]);
    for (x /= 2; x > 0; x /= 2){
      seg[x][y] = join(seg[2 * x][y], seg[2 * x + 1][y]);
      for (int j = y / 2; j > 0; j /= 2){
        seg[x][j] = join(seg[x][2 * j], seg[x][2 * j + 1]);
      }
    }
  }
  vector<int> getCover(int l, int r, int N){
    l = std::max(0, l);
    r = std::min(N, r);
    vector<int> ans;
    for (l += N, r += N; l < r; l /= 2, r /= 2){
      if (l & 1)
        ans.push_back(l++);
      if (r & 1)
        ans.push_back(--r);
    }
    return ans;
  }
  Node query(int x1, int y1, int x2, int y2){
    auto c1 = getCover(x1, x2 + 1, n);
    auto c2 = getCover(y1, y2 + 1, m);
    Node ans = neutral;
    for (auto i : c1){
      for (auto j : c2){
        ans = join(ans, seg[i][j]);
      }
    }
    return ans;
  }
};
