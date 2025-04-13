#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  vector<vector<s64>> c(5, vector<s64>(n + 1));
  for (s64 i{0}; i < 5; ++i) {
    string s;
    cin >> s;
    for (s64 j{0}; j < n; ++j) {
      switch (s[j]) {
        case 'R':
          c[i][j + 1] = 0;
          break;
        case 'B':
          c[i][j + 1] = 1;
          break;
        case 'W':
          c[i][j + 1] = 2;
          break;
        case '#':
          c[i][j + 1] = 3;
          break;
      }
    }
  }
  constexpr auto inf = numeric_limits<s64>::max();
  // dp[i][j] = minimum count of operation when col i is painted with color j
  vector<vector<s64>> dp(n + 1, vector<s64>(4, inf));
  fill(dp[0].begin(), dp[0].end(), 0);
  for (s64 i{1}; i <= n; ++i) {
    for (s64 j{0}; j < 3; ++j) {
      s64 cnt{0};
      for (s64 k{0}; k < 5; ++k) {
        if (c[k][i] != j) ++cnt;
      }
      s64 min_elem{inf};
      for (s64 k{0}; k < 3; ++k) {
        if (k == j) continue;
        min_elem = min(min_elem, dp[i - 1][k]);
      }
      dp[i][j] = min_elem == inf ? min_elem : min_elem + cnt;
    }
  }

  cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}
