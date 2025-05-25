#include "util/common.h"

int main() {
  s64 t;
  cin >> t;

  for (size_t i{0}; i < t; ++i) {
    s64 n;
    cin >> n;
    vector<s64> a(2 * n);
    for (s64 i{0}; i < 2 * n; ++i) cin >> a[i];
    vector<s64> dp(2 * n, -1);
    dp[2 * n - 1] = -1;
    dp[2 * n - 2] = a[2 * n - 2];
    for (s64 i{2 * n - 3}; i >= 0; --i) {
      if (dp[i + 1] >= 0) dp[i] = max(dp[i], a[i] + dp[i + 1]);
      if (dp[i + 2] >= 0) dp[i] = max(dp[i], a[i] + dp[i + 2]);
    }
    cout << dp[0] << endl;
  }
}