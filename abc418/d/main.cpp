#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string s;
  cin >> s;

  /* dp[i] = s[i]で終わる部分文字列のうち、美しい文字列の数 */
  vector<s64> dp(n);
  dp[0] = s[0] == '1' ? 1 : 0;
  for (s64 i = 1; i < n; ++i) {
    if (s[i] == '1') {
      dp[i] = 1 + dp[i - 1];
    } else {
      dp[i] = i - dp[i - 1];
    }
  }
  s64 sum = 0;
  for (s64 i = 0; i < n; ++i) sum += dp[i];
  cout << sum << endl;
}