#line 1 "main.cpp"

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
#line 4 "main.cpp"

int main() {
  s64 n, m, k;
  cin >> n >> m >> k;
  vector<pair<s64, s64>> vips(n);  // value index pair
  {
    for (s64 i{0}; i < n; ++i) {
      cin >> vips[i].first;
      vips[i].second = i;  // store index
    }
    sort(vips.begin(), vips.end());
  }

  vector<s64> a_sums(n + 1, 0);
  {
    for (s64 i{1}; i <= n; ++i) a_sums[i] = a_sums[i - 1] + vips[i - 1].first;
  }

  const s64 k_rem = k - a_sums[n];

  // get minimum vote to guarantee candidate i's victory
  const auto get = [&](s64 i) -> s64 {
    // check if candidate i's victory is guaranteed when he/she gets
    // <val> votes
    const auto check = [&](s64 idx, s64 vote) -> bool {
      const auto sum_vote = vips[idx].first + vote;
      const auto it = lower_bound(
          vips.begin(), vips.end(), sum_vote + 1,
          [](const auto& vip, s64 v) -> bool { return vip.first < v; });
      const auto idx_sup_min = distance(vips.begin(), it);
      const auto num_sup = distance(it, vips.end());
      if (num_sup >= m) return false;
      const auto num_rem = m - num_sup;
      if (idx < n - m) {
        return (sum_vote + 1) * num_rem -
                   (a_sums[idx_sup_min] - a_sums[idx_sup_min - num_rem]) >
               k_rem - vote;
      } else {
        if (idx_sup_min - num_rem - 1 < 0) return true;
        return (sum_vote + 1) * num_rem -
                   (a_sums[idx_sup_min] - a_sums[idx_sup_min - num_rem - 1] -
                    vips[idx].first) >
               k_rem - vote;
      }
    };

    if (check(i, 0)) return 0;        // already guaranteed
    if (!check(i, k_rem)) return -1;  // impossible

    const auto [ok, ng] = util::binary_search<s64>(
        k_rem, 0, [&](s64 val) -> bool { return check(i, val); });
    return ok;
  };

  vector<s64> answers(n);
  for (s64 i{0}; i < n; ++i) {
    answers[vips[i].second] = get(i);
  }

  for (s64 i{0}; i < n; ++i) {
    cout << answers[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
}
