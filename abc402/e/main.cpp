#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, x;
  cin >> n >> x;
  vector<s64> s(n), c(n), p(n);
  for (s64 i{0}; i < n; ++i) cin >> s[i] >> c[i] >> p[i];

  // dp[i][j] = expected value of score when mr.takahashi used j yen within ith
  // probrem.
  vector<vector<double>> dp((1 << n), vector<double>(x + 1, 0.0));

  for (s64 j{1}; j <= x; ++j) {
    for (s64 i{0}; i < (1 << n); ++i) {
      for (s64 k{0}; k < n; ++k) {
        if (!(i & (1 << k))) continue;
        auto j_prv = j - c[k];
        if (j_prv < 0) continue;
        auto i_prv = i & ~(1 << k);
        auto v = (p[k] / 100.0) * (dp[i_prv][j_prv] + s[k]) +
                 (1 - p[k] / 100.0) * dp[i][j_prv];

        dp[i][j] = max(dp[i][j], v);
      }
    }
  }
  double ans{0.0};
  for (s64 j{0}; j <= x; ++j) ans = max(dp[(1 << n) - 1][j], ans);
  cout << fixed << setprecision(15) << ans << endl;
}