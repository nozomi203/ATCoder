#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  // sum[i][j] = count of i in range [0,j];
  vector<vector<s64>> sum(m, vector<s64>(n, 0));
  for (s64 i{0}; i < m; ++i) {
    if (a[0] == i) sum[i][0] = 1;
    for (s64 j{1}; j < n; ++j) {
      sum[i][j] = sum[i][j - 1];
      if (a[j] == i) ++sum[i][j];
    }
  }

  constexpr auto inf = numeric_limits<s64>::max();
  vector<s64> cnt((1 << m), 0);
  for (s64 i{1}; i < (1 << m); ++i) {
    for (s64 j{0}; j < m; ++j) {
      if (i & (1 << j)) {
        cnt[i] += sum[j][n - 1];
      }
    }
  }

  // dp[i][j] = minimum count of operation to sort bitset i, j to be the last.
  vector<vector<s64>> dp((1 << m), vector<s64>(m, inf));

  for (s64 j{0}; j < m; ++j) {
    dp[1 << j][j] = sum[j][n - 1] - sum[j][sum[j][n - 1] - 1];
  }
  for (s64 i{1}; i < (1 << m); ++i) {
    for (s64 j{0}; j < m; ++j) {
      if (!(i & (1 << j))) continue;
      const auto b_prv = i & ~(1 << j);
      for (s64 k{0}; k < m; ++k) {
        if (j == k) continue;
        if (!(i & (1 << k))) continue;
        if (dp[b_prv][k] == inf) continue;
        dp[i][j] = min(dp[i][j], dp[b_prv][k] + sum[j][n - 1] -
                                     (sum[j][cnt[b_prv] + sum[j][n - 1] - 1] -
                                      sum[j][cnt[b_prv] - 1]));
      }
    }
  }

  cout << *min_element(dp[(1 << m) - 1].begin(), dp[(1 << m) - 1].end())
       << endl;
}