#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> svs(n);
  util::cin(svs);
  vector<s64> cs(m);
  util::cin(cs);

  sort(svs.begin(), svs.end(),
       [](const auto& l, const auto& r) { return l.second < r.second; });
  sort(cs.begin(), cs.end());

  vector<s64> ps(n);
  for (size_t i = 0; i < n; ++i) {
    auto it = lower_bound(cs.begin(), cs.end(), svs[i].first);
    ps[i] = distance(cs.begin(), it);
  }
}