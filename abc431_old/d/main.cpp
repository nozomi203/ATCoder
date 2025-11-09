#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<tuple<s64, s64, s64>> whbs(n);
  util::cin(whbs);

  s64 sumw = 0;
  for (s64 i = 0; i < n; ++i) sumw += get<0>(whbs[i]);

  // dp[i][j] =
  // i番目までのパーツを使って頭に合計wの重さのパーツを付けたときのうれしさの合計の最大値
  vector<vector<s64>> dp(n, vector<s64>(sumw + 1, -1));

  {
    auto [w, h, b] = whbs.front();
    dp[0][0] = b;
    dp[0][w] = h;
  }
  for (s64 i = 1; i < n; ++i) {
    for (s64 j = 0; j <= sumw; ++j) {
      auto [w, h, b] = whbs[i];
      if (j >= w && dp[i - 1][j - w] >= 0)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + h);
      if (dp[i - 1][j] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + b);
    }
  }

  s64 ans = 0;
  for (s64 i = 0; i <= sumw; ++i) {
    if (i > sumw - i) continue;
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << endl;
}