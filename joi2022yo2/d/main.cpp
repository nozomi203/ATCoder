#include "util/common.h"

/*
飴は必ず2個以上選ぶことができる
dp[i][j] = 最後に選んだのがi,その前に選んだのがjであるときの美味しさの総和の最大
*/

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<s64> as(n);
  util::cin(as);

  vector<vector<size_t>> dp(n, vector<size_t>(n, 0)),
      dp2(n, vector<size_t>(n, 0));
  for (s64 i = 1; i < n; ++i) {
    for (s64 j = 0; j < i; ++j) {
      dp[i][j] = as[i] + as[j];
      if (i - k >= 0 && j > 0)
        dp[i][j] = max(dp[i][j], dp2[j][min(i - k, j - 1)] + as[i]);
      dp2[i][j] = (j > 0) ? max(dp2[i][j - 1], dp[i][j]) : dp[i][j];
    }
  }

  size_t ans = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}