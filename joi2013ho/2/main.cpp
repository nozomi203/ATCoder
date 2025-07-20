#include "util/common.h"

/*

ある列車が完成したとき、そこからさらに2文字は追加しないといけない

*/
#define ASSUMED_SOLUTION 0;

int main() {
  s64 m, n;
  cin >> m >> n;
  string s, t;
  cin >> s >> t;

#if ASSUMED_SOLUTION
  vector<vector<array<s64, 2>>> dp(m + 1, vector<array<s64, 2>>(n + 1));
  for (size_t i = 0; i <= m; ++i) {
    for (size_t j = 0; j <= n; ++j) {
      if (t[j - 2] == 'O') {
        dp[i][j][0] = dp[i][j - 1][1] + 1;
      } else {
      }
      if (s[i - 2] == 'O') {
        dp[i][j][0] = dp[i - 1][j][1] + 1;
      } else {
      }
    }
  }
#else
  /*dp[i][j] = sのi文字目、tのj文字目が末尾となるようにした場合の列車の最大長*/
  vector<vector<s64>> dp(m + 1, vector<s64>(n + 1, 0));
  for (size_t i = 1; i <= m; ++i) {
    if (s[i - 1] == 'I') {
      dp[i][0] = 1;
      if (i > 1 && s[i - 2] == 'O' && dp[i - 2][0] > 0) {
        dp[i][0] = max(dp[i][0], dp[i - 2][0] + 2);
      }
    }
  }
  for (size_t j = 1; j <= n; ++j) {
    if (t[j - 1] == 'I') {
      dp[0][j] = 1;
      if (j > 1 && t[j - 2] == 'O' && dp[0][j - 2] > 0) {
        dp[0][j] = max(dp[0][j], dp[0][j - 2] + 2);
      }
    }
  }
  for (size_t i = 1; i <= m; ++i) {
    for (size_t j = 1; j <= n; ++j) {
      if ((s[i - 1] == 'I' && t[j - 1] == 'O') ||
          (s[i - 1] == 'O' && t[j - 1] == 'I')) {
        if (dp[i - 1][j - 1] > 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
        }
        if (dp[i - 1][0] > 0) dp[i][j] = max(dp[i][j], dp[i - 1][0] + 2);
        if (dp[0][j - 1] > 0) dp[i][j] = max(dp[i][j], dp[0][j - 1] + 2);
      }
      if (i > 1 && s[i - 1] == 'I' && s[i - 2] == 'O') {
        if (dp[i - 2][j] > 0) {
          dp[i][j] = max(dp[i][j], dp[i - 2][j] + 2);
        }
        if (dp[0][j] > 0) {
          dp[i][j] = max(dp[i][j], dp[0][j] + 2);
        }
      }
      if (j > 1 && t[j - 1] == 'I' && t[j - 2] == 'O') {
        if (dp[i][j - 2] > 0) {
          dp[i][j] = max(dp[i][j], dp[i][j - 2] + 2);
        }
        if (dp[i][0] > 0) {
          dp[i][j] = max(dp[i][j], dp[i][0] + 2);
        }
      }
    }
  }

  s64 ans = 0;
  for (size_t i = 0; i <= m; ++i) {
    for (size_t j = 0; j <= n; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
#endif
}