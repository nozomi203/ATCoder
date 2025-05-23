#include <atcoder/fenwicktree>

#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> a(n);
  constexpr size_t val_max = 2 * 100001;
  vector<vector<s64>> val2idxs(val_max);
  atcoder::fenwick_tree<s64> ft(val_max);
  s64 ans{0};
  for (s64 i = 0; i < n; ++i) {
    cin >> a[i];
    val2idxs[a[i]].push_back(i);
    ans += ft.sum(a[i] + 1, val_max);
    ft.add(a[i], 1);
  }
  cout << ans << endl;
  for (s64 c = {1}; c < m; ++c) {
    const auto& idxs = val2idxs[m - c];
    for (s64 i{0}; i < idxs.size(); ++i) {
      const s64 idx = idxs[i];
      ans -= (n - idx - idxs.size() + i);
      ans += (idx - i);
    }
    cout << ans << endl;
  }
}