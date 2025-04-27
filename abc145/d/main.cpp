#include <bits/stdc++.h>

#include <atcoder/modint>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 x, y;
  cin >> x >> y;
  // (1,2) * s + (2,1) * t = (x,y)
  const auto get = [&]() -> s64 {
    if ((2 * y - x) % 3) return 0;
    if ((2 * x - y) % 3) return 0;
    const s64 s{(2 * y - x) / 3}, t{(2 * x - y) / 3};
    if (s < 0 || t < 0) return 0;
    using mint = atcoder::modint1000000007;
    mint a(1), b(1), c(1);
    for (s64 i{2}; i <= s + t; ++i) a *= i;
    for (s64 i{2}; i <= s; ++i) b *= i;
    for (s64 i{2}; i <= t; ++i) c *= i;
    return (a / (b * c)).val();
  };

  cout << get() << endl;
}