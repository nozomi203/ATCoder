#include "util/common.h"

int main() {
  s64 d, n;
  cin >> d >> n;
  vector<s64> t(d + 1);
  for (s64 i{1}; i <= d; ++i) cin >> t[i];

  vector<s64> a(n + 1), b(n + 1), c(n + 1);
  for (s64 i{1}; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
  // i日目に服jを着た時の派手さの絶対値の合計の最大
  vector<vector<s64>> dp(d + 1, vector<s64>(n + 1));

  for (s64 i{2}; i <= d; ++i) {
    for (s64 j{1}; j <= n; ++j) {
      if (t[i] < a[j] || t[i] > b[j]) continue;
      for (s64 k{1}; k <= n; ++k) {
        if (t[i - 1] < a[k] || t[i - 1] > b[k]) continue;
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(c[j] - c[k]));
      }
    }
  }
  cout << *max_element(dp[d].begin(), dp[d].end()) << endl;
}