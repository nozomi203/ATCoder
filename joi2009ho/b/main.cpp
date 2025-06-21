#include "util/common.h"

int main() {
  s64 d, n, m;
  cin >> d >> n >> m;
  vector<s64> ds(n), ks(m);
  for (s64 i{1}; i < n; ++i) cin >> ds[i];
  for (s64 i{0}; i < m; ++i) cin >> ks[i];
  sort(ds.begin(), ds.end());
  s64 ans{0};
  for (s64 i{0}; i < m; ++i) {
    const auto k = ks[i];
    auto it = lower_bound(ds.begin(), ds.end(), k);
    const auto d0 = it != ds.begin() ? *prev(it) : *it;
    const auto d1 = it != ds.end() ? *it : d;
    ans += min(abs(d0 - k), abs(d1 - k));
  }
  cout << ans << endl;
}