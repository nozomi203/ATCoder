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
  for (s64 j = 1; j <= h; ++j) {
    for (s64 i = 1; i <= n; ++i) {
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
}