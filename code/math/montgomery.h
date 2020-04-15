#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
using i128 = __int128_t;
struct u256{
  u128 high, low;
  static u256 mult(u128 x, u128 y){
    u64 a = x >> 64, b = x;
    u64 c = y >> 64, d = y;
    u128 ac = (u128)a * c;
    u128 ad = (u128)a * d;
    u128 bc = (u128)b * c;
    u128 bd = (u128)b * d;
    u128 carry = (u128)(u64)ad + (u128)(u64)bc + (bd >> 64u);
    u128 high = ac + (ad >> 64u) + (bc >> 64u) + (carry >> 64u);
    u128 low = (ad << 64u) + (bc << 64u) + bd;
    return {high, low};
  }
};
//x_m := x*r mod n
struct Montgomery{
  u128 mod, inv, r2;
  //the N will be an odd number
  Montgomery(u128 n) : mod(n), inv(1), r2(-n % n){
    for (int i = 0; i < 7; i++)
      inv *= 2 - n * inv;
    for (int i = 0; i < 4; i++){
      r2 <<= 1;
      if (r2 >= mod)
        r2 -= mod;
    }
    for (int i = 0; i < 5; i++)
      r2 = mult(r2, r2);
  }
  u128 init(u128 x){
    return mult(x, r2);
  }
  u128 reduce(u256 x){
    u128 q = x.low * inv;
    i128 a = x.high - u256::mult(q, mod).high;
    if (a < 0)
      a += mod;
    return a;
  }
  u128 mult(u128 a, u128 b){
    return reduce(u256::mult(a, b));
  }
};