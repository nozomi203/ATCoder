#include "util/common.h"

int main() {
  s64 n, m, s;
  cin >> n >> m >> s;

  constexpr size_t mod = 100000;
  /*
  dp[i][j][k] = iまでの数からj個選んで合計kにするときの場合の数
  */
  vector<vector<size_t>> dp(n * n + 1, vector<size_t>(s + 1));
  dp[0][0] = 1;
  for (s64 i = 1; i <= m; ++i) {
    for (s64 j = n * n; j >= 0; --j) {
      for (s64 k = s; k >= 0; --k) {
        if (j > 0 && k >= i) {
          dp[j][k] += dp[j - 1][k - i];
          dp[j][k] %= mod;
        }
      }
    }
  }
  const size_t ans = dp[n * n][s];
  cout << ans << endl;
}