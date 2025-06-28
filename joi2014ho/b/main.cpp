#include "util/common.h"

int main() {
  size_t m, n;
  cin >> m >> n;
  vector<int64_t> ps(m);
  util::cin(ps);
  vector<pair<int64_t, int64_t>> ces(n);
  util::cin(ces);

  /*
  dp[i][j] =
  i番目までの箱の中から饅頭をちょうどj個詰められるように箱を購入したときの費用の最小
  */
  constexpr int64_t vmax = numeric_limits<int64_t>::max();
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 10000 + 1, vmax));
  for (size_t i = 0; i <= n; ++i) dp[i][0] = 0;
  for (size_t i = 1; i <= n; ++i) {
    for (size_t j = 1; j <= m + 10000; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= ces[i - 1].first) {
        if (dp[i - 1][j - ces[i - 1].first] != vmax) {
          dp[i][j] = min(dp[i][j],
                         dp[i - 1][j - ces[i - 1].first] + ces[i - 1].second);
        }
      }
    }
  }

  sort(ps.begin(), ps.end(), greater());
  vector<int64_t> sump(m + 1);
  for (size_t i = 0; i < m; ++i) {
    sump[i + 1] += ps[i] + sump[i];
  }
  int64_t ans = 0;
  for (size_t i = 0; i <= m + 10000; ++i) {
    if (dp[n][i] == vmax) continue;
    int64_t prft = sump[min(i, m)] - dp[n][i];
    ans = max(ans, prft);
  }
  cout << ans << endl;
}