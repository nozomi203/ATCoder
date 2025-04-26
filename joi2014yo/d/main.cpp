#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string str;
  cin >> str;
  vector<s64> s(n);
  for (s64 i{0}; i < n; ++i) {
    char c = str[i];
    s[i] = c == 'J' ? 0 : c == 'O' ? 1 : 2;
  }
  // dp[i][j] = number of possible schedule when j joined in day i
  vector<vector<s64>> dp(n, vector<s64>((1 << 3)));
  for (s64 j{1}; j < (1 << 3); ++j) {
    if (!(j & (1 << s[0]))) continue;
    if (!(j & (1 << 0))) continue;
    ++dp[0][j];
  }
  for (s64 i{1}; i < n; ++i) {
    for (s64 j{1}; j < (1 << 3); ++j) {
      if (!(j & (1 << s[i]))) continue;
      for (s64 k{1}; k < (1 << 3); ++k) {
        if (j & k) {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] = dp[i][j] % 10007;
        }
      }
    }
  }
  s64 ans{0};
  for (s64 j{1}; j < (1 << 3); ++j) {
    ans += dp[n - 1][j];
    ans = ans % 10007;
  }

  cout << ans << endl;
}