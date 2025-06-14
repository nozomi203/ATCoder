#include "util/common.h"

/*
dp[i][h] = i番目のモンスターを倒した時点で体力hである場合の魔力の最大値
i番目のモンスターを倒した時点で体力hであるためには、i番目のモンスターを倒す前に体力h+a[i]で魔法を使わずに戦うか、
倒す前に体力hで魔法を使って戦うかしかない
dp[i][h] = dp[i-1][h] - b[i] or dp[i-1][h+a[i]]
*/

int main() {
  s64 n, h, m;
  cin >> n >> h >> m;
  vector<pair<s64, s64>> abs(n + 1);
  for (size_t i{1}; i <= n; ++i) cin_pair(abs[i]);
  vector<vector<s64>> dp(n + 1, vector<s64>(h + 1, -1));
  dp[0][h] = m;
  for (size_t i{1}; i <= n; ++i) {
    for (size_t j{0}; j <= h; ++j) {
      dp[i][j] = dp[i - 1][j] - abs[i].second;
      if (j + abs[i].first <= h) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j + abs[i].first]);
      }
    }
  }

  for (s64 i{n}; i >= 0; --i) {
    if (any_of(dp[i].begin(), dp[i].end(),
               [](s64 mleft) { return mleft >= 0; })) {
      cout << i << endl;
      break;
    }
  }
}
