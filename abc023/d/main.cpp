#include "util/binary_search.h"
#include "util/common.h"
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