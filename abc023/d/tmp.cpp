#line 2 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\binary_search.h"
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
#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
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
  constexpr s64 inf = 10e16;
  vector<pair<s64, s64>> hss(n);
  for (s64 i{0}; i < n; ++i) cin >> hss[i].first >> hss[i].second;
  auto [score_ok, score_ng] =
      util::binary_search<s64>(inf, 0, [&](s64 val) -> bool {
        vector<s64> cnt(n, 0);
        for (s64 i{0}; i < n; ++i) {
          const auto [h, s] = hss[i];
          if (val < h) return false;
          s64 idx = (val - h) / s;
          if (idx >= n) continue;
          cnt[idx]++;
        }
        s64 sum{0};
        for (s64 i{0}; i < n; ++i) {
          sum += cnt[i];
          if (sum > i + 1) return false;
        }
        return true;
      });

  cout << score_ok << endl;
}
