#include "util/common.h"

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<pair<s64, s64>> xhs(n);
  util::cin(xhs);
  vector<s64> ts(q);
  util::cin(ts);
  sort(xhs.begin(), xhs.end());
  {
    vector<pair<s64, s64>> xhstmp;
    xhstmp.reserve(n);
    for (size_t i = 0; i < n; ++i) {
      const auto [x, h] = xhs[i];
      if (xhstmp.empty() || xhstmp.back().second <= h)
        xhstmp.push_back(make_pair(x, h));
    }
    swap(xhstmp, xhs);
  }

  vector<s64> thresholds(xhs.size());
  thresholds[0] = xhs[0].first;
  for (s64 i = 1; i < xhs.size(); ++i) {
    const auto [xp, hp] = xhs[i - 1];
    const auto [xc, hc] = xhs[i];
    thresholds[i] = xc + hp;
  }

  for (auto t : ts) {
    auto it = upper_bound(thresholds.begin(), thresholds.end(), t);
    if (it == thresholds.begin()) {
      cout << 0 << endl;
    } else {
      const auto idx = distance(thresholds.begin(), it - 1);
      const auto [x, h] = xhs[idx];
      cout << min(h, t - x) << endl;
    }
  }
}