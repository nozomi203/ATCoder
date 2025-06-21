#include <atcoder/modint>

#include "util/common.h"
int main() {
  size_t w, h;
  cin >> w >> h;

  constexpr size_t mod = 100000;
  /*
  dp[i][j][k] = 交差点(i, j)に{0:東1:北}に進んで到着する場合の数
  */
  vector<vector<array<size_t, 2>>> dp(w + 1,
                                      vector<array<size_t, 2>>(h + 1, {0, 0}));

  for (size_t i{0}; i <= w; ++i) dp[i][0][0] = 1;
  for (size_t j{0}; j <= h; ++j) dp[0][j][1] = 1;

  for (size_t i{1}; i <= w; ++i) {
    for (size_t j{1}; j <= h; ++j) {
      dp[i][j][0] += dp[i - 1][j][0];
      dp[i][j][0] %= mod;
      dp[i][j][1] += dp[i][j - 1][1];
      dp[i][j][1] %= mod;
    }
  }
  cout << (dp[w][h][0] + dp[w][h][1]) % mod << endl;
}