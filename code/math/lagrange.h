#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
struct PointValue{
  ld x, y;
  PointValue(ld x0=0, ld y0=0): x(x0), y(y0){}
};
void mul(vector<ld> &A, int x0){ // multiply A(x) by (x - x0)
  int n = A.size();
  A.push_back(0);
  auto B = A;  
  for(int i=n; i>=1; i--){
    A[i] = A[i-1];
  }
  A[0] = 0;
  for(int i=0; i<n+1; i++)
    A[i] -= B[i]*x0;
}
void div(vector<ld> &A, int x0){ // multiply A(x) by (x - x0)
  int g = (int)A.size() - 1;
  vector<ld> aux(g);
  for(int i=g; i>=1; i--){
    aux[i-1] = A[i];
    A[i-1] += x0*aux[i-1];
  }
  A = aux;
}
// Change Polynomial Representation from Point-Value to Coefficient 
// O(n^2)
vector<ld> LagrangeInterpolation(vector<PointValue> vp){
  vector<ld> A(1, 1);
  int n = vp.size();
  for(int i=0; i<n; i++)
    mul(A, vp[i].x);
  vector<ld> ans(n, 0);
  for(int i=0; i<n; i++){
    ld x = vp[i].x, y = vp[i].y;
    div(A, x);
    ld d = 1;
    for(int j=0; j<n; j++){
      if(j != i)
        d *= (x - vp[j].x);
    }
    for(int j=0; j<n; j++)
      ans[j] += A[j]*(y/d);
    mul(A, vp[i].x);
  }
  return ans;
}
