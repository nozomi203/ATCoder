#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> c(n);
  for (s64 i{0}; i < n; ++i) cin >> c[i];
  constexpr auto ninf = numeric_limits<s64>::lowest();
  s64 cnt{0};
  vector<s64> dp;
  for (s64 i{0}; i < n; ++i) {
    const auto v = c[i];
    if (dp.empty() || dp.back() < v) {
      dp.push_back(v);
    } else {
      const auto it = lower_bound(dp.begin(), dp.end(), v);
      if (*it > v) *it = v;
    }
  }
 cout << n - dp.size() << endl; 
}