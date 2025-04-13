#include <atcoder/modint>

#include "util/common.h"
int main() {
  s64 n, k;
  cin >> n >> k;
  vector<s64> plns(n + 1);
  for (s64 i{0}; i < k; ++i) {
    s64 a, b;
    cin >> a >> b;
    plns[a] = b;
  }

  // dp[i][j][k] = i日目にjのパスタを予定しており、jがk日連続している場合の数
  vector<vector<vector<s64>>> dp(n + 1,
                                 vector<vector<s64>>(4, vector<s64>(3, 0)));
  for (s64 i{1}; i <= 3; ++i) {
    if (plns[1] && plns[1] != i) continue;
    dp[1][i][1] = 1;
  }
  for (s64 i{2}; i <= n; ++i) {
    for (s64 j{1}; j <= 3; ++j) {
      if (plns[i] && plns[i] != j) continue;
      for (s64 k{1}; k <= 3; ++k) {
        if (k == j) continue;
        for (s64 l{1}; l <= 2; ++l) {
          dp[i][j][1] += dp[i - 1][k][l];
          dp[i][j][1] = dp[i][j][1] % 10000;
        }
      }
      dp[i][j][2] = dp[i - 1][j][1];
    }
  }

  s64 ans{0};
  for (s64 i{1}; i <= 3; ++i) {
    for (s64 j{1}; j <= 2; ++j) {
      ans += dp[n][i][j];
      ans = ans % 10000;
    }
  }
  cout << ans << endl;
}