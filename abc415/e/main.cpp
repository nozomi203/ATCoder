#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<vector<s64>> ass(h, vector<s64>(w));
  util::cin(ass);
  vector<s64> ps(h + w - 1);
  util::cin(ps);

  const s64 sump = accumulate(ps.begin(), ps.end(), 0LL);

  const auto check = [&](s64 x) -> bool {
    /* dp[i][j] = マス(i,j)にいるときのコインの最大値 */
    constexpr auto ninf = numeric_limits<s64>::lowest();
    vector<vector<s64>> dp(h, vector<s64>(w, ninf));
    dp[0][0] = x + ass[0][0] - ps[0];
    for (s64 i = 1; i < h; ++i) {
      dp[i][0] = dp[i - 1][0] >= 0 ? dp[i - 1][0] + ass[i][0] - ps[i] : ninf;
    }
    for (s64 j = 1; j < w; ++j) {
      dp[0][j] = dp[0][j - 1] >= 0 ? dp[0][j - 1] + ass[0][j] - ps[j] : ninf;
    }
    for (s64 i = 1; i < h; ++i) {
      for (s64 j = 1; j < w; ++j) {
        const auto p = ps[i + j];
        if (dp[i - 1][j] >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + ass[i][j] - p);
        }
        if (dp[i][j - 1] >= 0) {
          dp[i][j] = max(dp[i][j], dp[i][j - 1] + ass[i][j] - p);
        }
      }
    }
    return dp[h - 1][w - 1] >= 0;
  };

  const auto get = [&]() -> s64 {
    if (check(0)) return 0;
    s64 xl = 0, xr = sump;
    while (xr - xl > 1) {
      s64 x = (xl + xr) / 2;
      if (check(x)) {
        xr = x;
      } else {
        xl = x;
      }
    }
    return xr;
  };
  cout << get() << endl;
}