#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\binary_search.h"
#include <cmath>
#include <concepts>
#include <functional>

namespace util {

template <std::signed_integral Int>
inline std::pair<Int, Int> binary_search(Int ok, Int ng,
                                         std::function<bool(Int value)> check) {
  while (std::abs(ok - ng) > 1) {
    auto mid = (ok + ng) / 2;
    check(mid) ? ok = mid : ng = mid;
  }
  return {ok, ng};
}
}  // namespace util
#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 3 "main.cpp"

int main() {
  s64 n;
  cin >> n;

  // x^3 - y^3 = (x - y)(x^2 + xy + y^)
  for (s64 a{1}; a <= 1000000; ++a) {
    // a = x - y;
    if (n % a) continue;
    // b = x^2 + xy+ y^2 = (x - y)^2 + 3xy
    s64 b = n / a;
    if (b <= a * a) continue;
    // c = 3xy
    s64 c = b - a * a;
    if (c % 3) continue;
    // c = xy
    c /= 3;
    auto [ok, ng] = util::binary_search<s64>(
        0ll, sqrt(c), [&](s64 y) -> bool { return y * (y + a) < c; });
    if (ng * (ng + a) == c) {
      cout << ng + a << " " << ng << endl;
      return 0;
    } else {
      continue;
    }
  }

  cout << -1 << endl;
}
