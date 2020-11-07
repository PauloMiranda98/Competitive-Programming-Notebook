#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Job {
  int t, c, idx;
  Job(int t1=0, int c1=0, int i=0):t(t1), c(c1), idx(i){}
};
//Penalty functions fi(t) = c[i]*t
bool cmp1(Job a, Job b){
  return a.c*(ll)b.t > b.c*(ll)a.t;
}
//Penalty functions fi(t) = c[i]*e^(alfa*t)
const double alfa = 2;
const double EPS = 1e-9;
bool cmp2(Job a, Job b){
  return (1 - exp(alfa*a.t))/a.c > (1 - exp(alfa*b.t))/b.c + EPS;
}