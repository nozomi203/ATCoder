#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> heights(N + 1);
  for (s64 n = 1; n <= N; ++n) cin >> heights[n];
  // dp[i][j] = i番目のビルから間隔jで連続する同じ高さのビルの最大数
  vector<vector<s64>> dp(N + 1, vector<s64>(N, 1));

  s64 ans{1};

  for (s64 i = 1; i <= N; ++i) {
    for (s64 j = 1; j < N; ++j) {
      if (j >= i) break;
      if (heights[i - j] == heights[i]) {
        dp[i][j] = dp[i - j][j] + 1;
        ans = max(ans, dp[i][j]);
      }
    }
  }

  cout << ans << endl;
}