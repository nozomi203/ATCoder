#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;

  vector<pair<s64, s64>> xds;
  vector<vector<s64>> idxss(n);
  for (s64 i = 0; i < n; ++i) {
    s64 k;
    cin >> k;
    for (s64 j = 0; j < k; ++j) {
      s64 x, d;
      cin >> x >> d;
      const auto idx = xds.size();
      xds.push_back(make_pair(x, d));
      idxss[i].push_back(idx);
    }
  }

  constexpr auto inf = numeric_limits<s64>::max();
  /*
  dp[i][j] = minimum cost to reach i with j times of skip
  */
  vector<vector<s64>> dp(xds.size(), vector<s64>(m + 1, inf));
  for (s64 idx : idxss[0]) dp[idx][0] = 0;
  if (m) {
    for (s64 idx : idxss[1]) dp[idx][1] = 0;
  }
  for (s64 i = 1; i < n; ++i) {
    for (s64 to : idxss[i]) {
      const auto [xt, dt] = xds[to];
      for (s64 j = 0; j <= m; ++j) {
        for (s64 from : idxss[i - 1]) {
          if (dp[from][j] == inf) continue;
          const auto [xf, df] = xds[from];
          const auto d = (df + dt) * abs(xf - xt);
          dp[to][j] = min(dp[to][j], dp[from][j] + d);
        }
        if (i > 1 && j > 0) {
          for (s64 from : idxss[i - 2]) {
            if (dp[from][j - 1] == inf) continue;
            const auto [xf, df] = xds[from];
            const auto d = (df + dt) * abs(xf - xt);
            dp[to][j] = min(dp[to][j], dp[from][j - 1] + d);
          }
        }
      }
    }
  }

  s64 ans = inf;
  for (s64 idx : idxss[n - 1]) {
    ans = min(ans, *min_element(dp[idx].begin(), dp[idx].end()));
  }

  if (m > 0) {
    for (s64 idx : idxss[n - 2]) {
      ans = min(ans, *min_element(dp[idx].begin(), dp[idx].end() - 1));
    }
  }

  cout << ans << endl;
}