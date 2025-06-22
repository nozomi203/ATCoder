#include <atcoder/modint>

#include "util/common.h"
int main() {
  size_t w, h;
  cin >> w >> h;

  constexpr size_t mod = 100000;
  /*
  dp[i][j][k] = 交差点(i, j)に
  {0:東に1,1:東に連続2以上,2:北に1,3:北に連続2以上}進んで到着する場合の数
  */
  vector<vector<array<size_t, 4>>> dp(
      w, vector<array<size_t, 4>>(h, {0, 0, 0, 0}));

  dp[1][0][0] = 1;
  for (size_t i{2}; i < w; ++i) dp[i][0][1] = 1;
  dp[0][1][2] = 1;
  for (size_t j{2}; j < h; ++j) dp[0][j][3] = 1;

  dp[1][1][0] = 1;
  dp[1][1][2] = 1;
  for (size_t i{2}; i < w; ++i) {
    dp[i][1][1] = 1;
    dp[i][1][2] = 1;
  }
  for (size_t j{2}; j < h; ++j) {
    dp[1][j][0] = 1;
    dp[1][j][3] = 1;
  }

  for (size_t i{2}; i < w; ++i) {
    for (size_t j{2}; j < h; ++j) {
      dp[i][j][0] += dp[i - 1][j - 1][2] + dp[i - 1][j - 1][3];
      dp[i][j][1] += dp[i - 2][j][0] + dp[i - 2][j][1] + dp[i - 2][j][3];
      dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1];
      dp[i][j][3] += dp[i][j - 2][1] + dp[i][j - 2][2] + dp[i][j - 2][3];
      dp[i][j][0] %= mod;
      dp[i][j][1] %= mod;
      dp[i][j][2] %= mod;
      dp[i][j][3] %= mod;
    }
  }
  cout << (dp[w - 1][h - 1][0] + dp[w - 1][h - 1][1] + dp[w - 1][h - 1][2] +
           dp[w - 1][h - 1][3]) %
              mod
       << endl;
}