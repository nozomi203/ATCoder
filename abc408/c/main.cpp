#include "util/common.h"

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<pair<size_t, size_t>> lrs(m);
  for (size_t i{0}; i < m; ++i) cin_pair(lrs[i]);
  vector<int64_t> imos(n + 2);
  for (auto [l, r] : lrs) {
    ++imos[l];
    --imos[r + 1];
  }
  for (size_t i{0}; i <= n; ++i) imos[i + 1] += imos[i];
  int64_t ans{numeric_limits<int64_t>::max()};
  for (size_t i{1}; i <= n; ++i) ans = min(ans, imos[i]);
  cout << ans << endl;
}