#include "util/common.h"

u64 get_digit(u64 v) {
  u64 ret{0};
  while (v) {
    v /= 10;
    ++ret;
  }
  return ret;
}
u64 mul(u64 a, u64 b, u64 k) {
  u64 ret{0};
  u64 digit{0};
  u64 ten{1};
  while (b) {
    u64 v = b % 10;
    b /= 10;
    u64 w = a * v;
    if (get_digit(w) >= k + 1 - digit) return 1;
    w *= ten;
    ret += w;
    if (get_digit(ret) >= k + 1) return 1;
    ten *= 10;
    ++digit;
  }
  return ret;
}

int main() {
  u64 n, k;
  cin >> n >> k;
  vector<u64> as(n);
  for (u64 i{0}; i < n; ++i) cin >> as[i];

  u64 v{1};
  for (auto a : as) {
    v = mul(v, a, k);
  }
  cout << v << endl;
}