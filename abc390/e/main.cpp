#include "util/common.h"

int main() {
  s64 N, X;
  cin >> N >> X;
  // dp[i][j] = カロリーがiになるように栄養jを摂取したときの摂取量の最大値
  vector<array<s32, 3>> dp(
      X + 1, {numeric_limits<s32>::lowest(), numeric_limits<s32>::lowest(),
              numeric_limits<s32>::lowest()});
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  for (s64 i = 1; i <= N; ++i) {
    s32 V, A, C;
    cin >> V >> A >> C;
    --V;

    for (s64 j = C; j <= X; ++j) {
      dp[j][V] = max(dp[j][V], dp[j - C][V] + A);
    }
  }

  for (s64 i = 1; i <= X; ++i) {
    for (s64 j = 0; j < 3; ++j) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }

  array<s32, 3> carories{0, 0, 0};
  for (s64 i = 0; i < X; ++i) {
    if (dp[carories[0]][0] <= dp[carories[1]][1] &&
        dp[carories[0]][0] <= dp[carories[2]][2])
      ++carories[0];
    else if (dp[carories[1]][1] <= dp[carories[0]][0] &&
             dp[carories[1]][1] <= dp[carories[2]][2])
      ++carories[1];
    else
      ++carories[2];
  }

  cout << min(dp[carories[0]][0], min(dp[carories[1]][1], dp[carories[2]][2]))
       << endl;
}