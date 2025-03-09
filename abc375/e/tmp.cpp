#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> abs(n + 1);
  for (s64 i{1}; i <= n; ++i) cin >> abs[i].first >> abs[i].second;
  const auto get = [&]() -> s64 {
    const s64 sum =
        accumulate(abs.begin(), abs.end(), 0,
                   [](s64 acc, const auto& ab) { return acc + ab.second; });
    if (sum % 3 != 0) {
      return -1;
    }
    constexpr auto inf = numeric_limits<s64>::max();
    vector<vector<vector<s64>>> dp(
        n + 1, vector<vector<s64>>(sum / 3 + 1, vector<s64>(sum / 3 + 1, inf)));
    dp[0][0][0] = 0;
    for (s64 i{1}; i <= n; ++i) {
      for (s64 j{0}; j <= sum / 3; ++j) {
        for (s64 k{0}; k <= sum / 3; ++k) {
          const auto [a, b] = abs[i];
          if (a == 1) {
            dp[i][j][k] = dp[i - 1][j][k] < inf ? dp[i - 1][j][k] + 1 : inf;
            if (j >= b && dp[i - 1][j - b][k] < inf)
              dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - b][k]);
            if (k >= b && dp[i - 1][j][k - b] < inf)
              dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - b] + 1);
          } else if (a == 2) {
            dp[i][j][k] = dp[i - 1][j][k] < inf ? dp[i - 1][j][k] + 1 : inf;
            if (j >= b && dp[i - 1][j - b][k] < inf)
              dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - b][k] + 1);
            if (k >= b && dp[i - 1][j][k - b] < inf)
              dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - b]);
          } else {
            dp[i][j][k] = dp[i - 1][j][k] < inf ? dp[i - 1][j][k] : inf;
            if (j >= b && dp[i - 1][j - b][k] < inf)
              dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - b][k] + 1);
            if (k >= b && dp[i - 1][j][k - b] < inf)
              dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - b] + 1);
          }
        }
      }
    }

    return dp[n][sum / 3][sum / 3] == inf ? -1 : dp[n][sum / 3][sum / 3];
  };

  cout << get() << endl;
}
