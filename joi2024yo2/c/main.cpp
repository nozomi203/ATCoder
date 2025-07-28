#include "util/common.h"

/*
GRBBRG
*/

s64 toidx(char c) {
  switch (c) {
    case 'R':
      return 0;
    case 'G':
      return 1;
    case 'B':
      return 2;
    default:
      return -1;
  }
}

int main() {
  s64 n;
  string s;
  s64 a, b, c;

  cin >> n;
  cin >> s;
  cin >> a >> b >> c;

  /* dp[i][j] =
   * i番目までのライトを末尾の色がjになるように条件を満たしたときに払う金額の最小
   */
  constexpr auto inf = numeric_limits<s64>::max();
  vector<array<s64, 4>> dp(n);
  dp[0][0] = toidx(s[0]) == 0 ? 0 : c;
  dp[0][1] = inf;
  dp[0][2] = inf;
  dp[0][3] = a;
  for (s64 i = 1; i < n; ++i) {
    dp[i][0] = (toidx(s[i]) == 0 ? 0 : c) + min(dp[i - 1][3], dp[i - 1][2]);
    dp[i][1] =
        dp[i - 1][0] != inf ? dp[i - 1][0] + (toidx(s[i]) == 1 ? 0 : c) : inf;
    dp[i][2] =
        dp[i - 1][1] != inf ? dp[i - 1][1] + (toidx(s[i]) == 2 ? 0 : c) : inf;
    dp[i][3] = dp[i - 1][3] + a;
  }

  s64 ans = min(a, b) * n;
  for (s64 i = 0; i < n; ++i) {
    if (dp[i][2] == inf) continue;
    s64 cost = dp[i][2] + b * (n - i - 1);
    ans = min(ans, cost);
  }
  cout << ans << endl;
}