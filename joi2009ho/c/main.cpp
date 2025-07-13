#include "util/common.h"

int main() {
  s64 n, m, h, k;
  cin >> n >> m >> h >> k;
  vector<s64> ss(n + 1);
  util::cin(ss.begin() + 1, ss.end());
  vector<pair<s64, s64>> abs(m);
  util::cin(abs);

  vector<vector<s64>> conns(n + 1, vector<s64>(h + 1, -1));
  for (auto [a, b] : abs) {
    conns[a][b] = a + 1;
    conns[a + 1][b] = a;
  }

  vector<vector<s64>> roots(n + 1, vector<s64>(h + 1));
  for (s64 i = 1; i <= n; ++i) roots[i][0] = i;
  for (s64 j = 0; j < h; ++j) {
    for (s64 i = 1; i <= n; ++i) {
      if (conns[i][j] != -1) {
        roots[conns[i][j]][j + 1] = roots[i][j];
      } else {
        roots[i][j + 1] = roots[i][j];
      }
    }
  }
  /*
  dp[i][j] = i本目の長さjから辿ったときの得点
  */
  vector<vector<s64>> dp(n + 1, vector<s64>(h + 1));
  for (s64 i = 1; i <= n; ++i) dp[i][h] = ss[i];
  for (s64 j = h - 1; j >= 0; --j) {
    for (s64 i = 1; i <= n; ++i) {
      if (conns[i][j] != -1) {
        dp[i][j] = dp[conns[i][j]][j + 1];
      } else {
        dp[i][j] = dp[i][j + 1];
      }
    }
  }
  s64 sum = 0;
  for (s64 i = 1; i <= k; ++i) sum += dp[i][0];
  s64 min_diff = 0;
  for (auto [a, b] : abs) {
    auto a0 = a;
    auto a1 = a + 1;
    if (roots[a0][b] <= k && roots[a1][b] <= k) continue;
    if (roots[a0][b] > k && roots[a1][b] > k) continue;
    if (roots[a1][b] <= k) swap(a0, a1);  // a0 should be in range
    s64 diff = dp[roots[a1][b]][0] - dp[roots[a0][b]][0];
    min_diff = min(min_diff, diff);
  }
  cout << sum + min_diff << endl;
}