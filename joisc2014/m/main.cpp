#include "util/common.h"

/*
dp
i番目までのストラップを使った時の嬉しさの総和を求めたい
新しいストラップをどこにつけるか。これは端子を持つならルート、持たないなら今ある端子のどれかにつける
→端子の数も分からないといけない
dp[i][j] = iまでのストラップを使い端子がj個空いている時の嬉しさの総和
端子はありすぎても意味がない。n個以上空いていれば、残ったすべてのストラップをつけられる→n個目以降の端子はふさぐと考える
*/

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> abs(n);
  util::cin(abs);
  sort(abs.begin(), abs.end(), greater());

  constexpr auto ninf = numeric_limits<s64>::lowest();
  vector<vector<s64>> dp(n + 1, vector<s64>(n + 1, ninf));
  dp[0][1] = 0;
  for (s64 i = 0; i < n; ++i) {
    const auto [a, b] = abs[i];
    for (s64 j = 0; j <= n; ++j) {
      /* i+1番目のストラップを使わない */
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      /* i+1番目のストラップを使う */
      if (j - 1 + a >= 0 && dp[i][j] != ninf) {
        dp[i + 1][min(n, j - 1 + a)] =
            max(dp[i + 1][min(n, j - 1 + a)], dp[i][j] + b);
      }
    }
  }

  cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}