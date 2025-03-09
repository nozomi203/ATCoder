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
  s64 N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<pair<s64, s64>> queries(Q);
  for (s64 i{0}; i < Q; ++i) {
    cin >> queries[i].first >> queries[i].second;
    queries[i].first--;
    queries[i].second--;
  }

  vector<s64> idxs_1, idxs_s, idxs_2;
  for (s64 i{0}; i < N; ++i) {
    if (S[i] == '1') idxs_1.push_back(i);
    if (S[i] == '/') idxs_s.push_back(i);
    if (S[i] == '2') idxs_2.push_back(i);
  }

  vector<s64> answers;
  for (const auto [l, r] : queries) {
    const auto [w_ok, w_ng] =
        util::binary_search<s64>(-1, r - l + 1, [&](s64 w) -> bool {
          if (w < 0) return true;
          if (w == 0) {
            const auto [oks, ngs] = util::binary_search<s64>(
                -1, idxs_s.size(), [&](s64 val) -> bool {
                  if (val < 0) return true;
                  if (val >= idxs_s.size()) return false;
                  return idxs_s[val] < l;
                });
            return ngs < idxs_s.size() && idxs_s[ngs] <= r;
          }

          const auto [ok1, ng1] =
              util::binary_search<s64>(-1, idxs_1.size(), [&](s64 val) -> bool {
                if (val < 0) return true;
                if (val >= idxs_1.size()) return false;
                return idxs_1[val] < l;
              });
          if (ng1 + w - 1 >= idxs_1.size()) return false;
          const auto idx_1 = idxs_1[ng1 + w - 1];

          const auto [oks, ngs] =
              util::binary_search<s64>(-1, idxs_s.size(), [&](s64 val) -> bool {
                if (val < 0) return true;
                if (val >= idxs_s.size()) return false;
                return idxs_s[val] <= idx_1;
              });
          if (ngs >= idxs_s.size()) return false;
          const auto idx_s = idxs_s[ngs];

          const auto [ok2, ng2] =
              util::binary_search<s64>(-1, idxs_2.size(), [&](s64 val) -> bool {
                if (val < 0) return true;
                if (val >= idxs_2.size()) return false;
                return idxs_2[val] <= idx_s;
              });
          if (ng2 + w - 1 >= idxs_2.size()) return false;
          return idxs_2[ng2 + w - 1] <= r;
        });

    answers.push_back(w_ok < 0 ? 0 : 2 * w_ok + 1);
  }

  for (auto ans : answers) cout << ans << endl;
}
