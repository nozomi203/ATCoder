#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  vector<vector<s64>> dp;
  dp.reserve(n);

  for (s64 i{0}; i < n; ++i) {
    const auto v = a[i];
    auto it = lower_bound(
        dp.begin(), dp.end(), v,
        [](const vector<s64>& vec, s64 val) { return vec.back() >= val; });
    if (it == dp.end()) {
      auto& vec = dp.emplace_back();
      vec.push_back(v);
    } else {
      auto& vec = *it;
      vec.push_back(v);
    }
  }
  cout << dp.size() << endl;
}