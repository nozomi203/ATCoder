#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> d(n + 1);
  vector<s64> c(m + 1);
  for (s64 i{1}; i <= n; ++i) cin >> d[i];
  for (s64 i{1}; i <= m; ++i) cin >> c[i];
  constexpr auto inf = numeric_limits<s64>::max();
  // dp[i][k] = minimum degree of fatigue when ioi arrived town i in day j
  vector<vector<s64>> dp(n + 1, vector<s64>(m + 1, inf));
  fill(dp[0].begin(), dp[0].end(), 0);
  for (s64 i{1}; i <= n; ++i) {
    s64 prv_min{dp[i - 1][0]};
    for (s64 j{1}; j <= m; ++j) {
      dp[i][j] = prv_min == inf ? inf : prv_min + d[i] * c[j];
      prv_min = min(prv_min, dp[i - 1][j]);
    }
  }

  cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}
