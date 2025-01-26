#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\binary_search.h"
#include <cmath>
#include <concepts>
#include <functional>

namespace util {

template <std::integral Int>
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
  s64 N, M;
  cin >> N >> M;
  vector<s64> P(N);
  for (s64 i = 0; i < N; ++i) cin >> P[i];

  const auto get_num = [&](s64 value) -> s64 {
    s64 num{0};
    for (s64 i = 0; i < N; ++i) {
      num += (value + P[i]) / (2LL * P[i]);
    }
    return num;
  };
  const auto get_sum = [&](s64 value) -> s64 {
    s64 sum{0};
    for (s64 i = 0; i < N; ++i) {
      s64 num = (value + P[i]) / (2LL * P[i]);
      sum += P[i] * num * num;
    }
    return sum;
  };
  const auto check_sum = [&](s64 value) -> s64 {
    s64 sum{0};
    for (s64 i = 0; i < N; ++i) {
      s64 num = (value + P[i]) / (2LL * P[i]);
      if (sqrt(P[i]) * num > sqrt(M)) return false;
      sum += P[i] * num * num;
      if (sum > M) return false;
    }
    return true;
  };

  auto [ok, ng] = util::binary_search<s64>(
      0, M + 1, [&](auto value) -> bool { return check_sum(value); });

  s64 ans = get_num(ok);
  s64 sum = get_sum(ok);
  for (s64 i = 0; i < N; ++i) {
    if (sum + ok + 1 > M) break;
    if ((ok + 1 + P[i]) % (2 * P[i]) == 0) {
      sum += ok + 1;
      ++ans;
    }
  }
  cout << ans << endl;
}
