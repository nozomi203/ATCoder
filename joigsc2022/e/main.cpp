#include "util/common.h"

int main() {
  size_t n, l;
  cin >> n >> l;
  vector<size_t> as(n);
  util::cin(as);
  for (size_t i = 1; i < n; ++i) as[i] += as[i - 1];

  vector<pair<size_t, size_t>> dp(n);
  for (s64 i = n - 1; i >= 0; --i) {
    auto it = upper_bound(as.begin() + i, as.end(), i ? as[i - 1] + l : l);
    const auto idx = distance(as.begin(), it);
    if (idx == n) {
      dp[i].first = 1;
      dp[i].second = as[idx - 1] - (i ? as[i - 1] : 0);
    } else {
      dp[i].first = dp[idx].first + 1;
      dp[i].second = dp[idx].second;
    }
  }
  for (size_t i = 0; i < n; ++i) {
    const auto [x, y] = dp[i];
    cout << x << " " << y << endl;
  }
}