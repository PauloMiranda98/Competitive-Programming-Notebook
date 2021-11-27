#include <bits/stdc++.h>

using namespace std;
struct tipo{
  int a, b;
};
struct classcomp {
  bool operator() (const tipo& lhs, const tipo& rhs) const{
    return lhs.a < rhs.a;
  }
};
priority_queue<tipo, vector<tipo>, classcomp> st;
priority_queue<int, vector<int>, greater<int>> stMin;
