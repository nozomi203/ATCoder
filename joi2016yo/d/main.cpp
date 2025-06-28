#include "util/common.h"

int main() {
  int64_t n, t, q;
  cin >> n >> t >> q;
  vector<pair<int64_t, size_t>> ads(n);
  util::cin(ads);
  vector<tuple<int64_t, size_t, size_t>> adrs(n);
  for (size_t i = 0; i < n; ++i) {
    auto& [a, d, idx] = adrs[i];
    tie(a, d) = ads[i];
    idx = i;
  }
  vector<size_t> xs(q);
  util::cin(xs);

  sort(adrs.begin(), adrs.end());

  constexpr auto inf = numeric_limits<int64_t>::max();
  vector<int64_t> ttss(n, inf);  // time to stop per resident
  vector<int64_t> hes;
  for (size_t i = 0; i < n - 1; ++i) {
    auto [a0, d0, r0] = adrs[i];
    auto [a1, d1, r1] = adrs[i + 1];
    if (d0 == 1 && d1 == 2) hes.push_back(i);
  }

  for (auto he : hes) {
    auto hw = he + 1;
    auto [ae, de, re] = adrs[he];
    auto [aw, dw, rw] = adrs[hw];
    assert(de == 1 && dw == 2);
    ttss[re] = ttss[rw] = (aw - ae + 1) / 2;

    while (--he >= 0) {
      auto [aep, dep, rep] = adrs[he + 1];
      auto [aec, dec, rec] = adrs[he];
      if (dec != 1) break;
      ttss[rec] = ttss[rep] + (aep - aec);
    }
    while (++hw < n) {
      auto [aep, dep, rep] = adrs[hw - 1];
      auto [aec, dec, rec] = adrs[hw];
      if (dec != 2) break;
      ttss[rec] = ttss[rep] + (aec - aep);
    }
  }

  for (auto x : xs) {
    auto [a, d] = ads[x - 1];
    cout << (a + (d == 1 ? 1 : -1) * min(t, ttss[x - 1])) << endl;
  }
}