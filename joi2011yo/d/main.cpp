#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<u64> a(n + 1);
  for (s64 i{1}; i <= n; ++i) cin >> a[i];
  vector<vector<u64>> dp(n + 1, vector<u64>(21));
  dp[0][0] = 1;
  dp[1][a[1]] = 1;
  for (s64 i{2}; i <= n; ++i) {
    for (s64 j{0}; j <= 20; ++j) {
      if (j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= 20) dp[i][j] += dp[i - 1][j + a[i]];
    }
  }
  cout << dp[n - 1][a[n]] << endl;
}