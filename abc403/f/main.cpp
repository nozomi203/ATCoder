#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n;
  cin >> n;
  vector<string> dp(n + 1), dp2(n + 1);
  for (s64 i{1}; i <= n; i = i * 10 + 1) dp[i] = dp2[i] = to_string(i);
  for (s64 i{0}; i <= n; ++i) {
    for (s64 j{1}; j < i; ++j) {
      if (dp[i].empty() || dp[i].size() > dp[j].size() + dp[i - j].size() + 1)
        dp[i] = dp[j] + '+' + dp[i - j];
      if (dp2[i].empty() || dp2[i].size() > dp[j].size() + dp[i - j].size() + 3)
        dp2[i] = '(' + dp[j] + '+' + dp[i - j] + ')';
      if (i % j == 0) {
        if (dp[i].empty() ||
            dp[i].size() > dp2[i / j].size() + dp2[j].size() + 1)
          dp[i] = dp2[i / j] + '*' + dp2[j];
        if (dp2[i].empty() ||
            dp2[i].size() > dp2[i / j].size() + dp2[j].size() + 1)
          dp2[i] = dp2[i / j] + '*' + dp2[j];
      }
    }
  }

  cout << dp[n] << endl;
}