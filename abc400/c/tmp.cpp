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
  s64 ans{0};
  for (s64 a{2}; a <= n; a *= 2) {
    auto [ok, ng] =
        util::binary_search<s64>(0, (s64)sqrt(n) + 1, [&](s64 val) -> bool {
          return (val * 2 + 1) * (val * 2 + 1) <= n / a;
        });
    ans += ok + 1;
  }

  cout << ans << endl;
}
