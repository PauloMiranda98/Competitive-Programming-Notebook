#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r){
  return uniform_int_distribution<int>(l, r)(rng);
}
inline double rand(double l, double r){
  return uniform_real_distribution<double>(l, r)(rng);
}
mt19937_64 rng_64((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline int64_t rand(int64_t l, int64_t r){
  return uniform_int_distribution<int64_t>(l, r)(rng_64);
}
void randomShuffle(vector<int> v){
  shuffle(v.begin(), v.end(), rng);
}
