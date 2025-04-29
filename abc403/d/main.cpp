#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, d;
  cin >> n >> d;
  constexpr auto a_max = 1000000;
  vector<s64> cnts(a_max + 1, 0);
  for (s64 i{0}; i < n; ++i) {
    s64 a;
    cin >> a;
    ++cnts[a];
  }

  if (d == 0) {
    s64 ans{0};
    for (auto cnt : cnts)
      if (cnt) ans += cnt - 1;
    cout << ans << endl;
    return 0;
  }

  // minimum count of deletion to achieve restriction
  vector<vector<s64>> dp(
      d, vector<s64>(a_max / d + 1, numeric_limits<s64>::max()));
  for (s64 i{0}; i < d; ++i) {
    dp[i][0] = 0;
    if (i + d > a_max) continue;
    dp[i][1] = min(cnts[i + d], cnts[i]);
    for (s64 j{2}; j <= (a_max - i) / d; ++j) {
      dp[i][j] = min(dp[i][j - 1] + cnts[i + d * j],
                     dp[i][j - 2] + cnts[i + d * (j - 1)]);
    }
  }

  s64 ans{0};
  for (s64 i{0}; i < d; ++i) {
    ans += dp[i][(a_max - i) / d];
  }
  cout << ans << endl;
}