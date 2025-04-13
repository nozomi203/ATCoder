#include <atcoder/modint>

#include "util/common.h"
int main() {
  s64 n, k;
  cin >> n >> k;
  vector<s64> plns(n + 1);
  for (s64 i{0}; i < k; ++i) {
    s64 a, b;
    cin >> a >> b;
    plns[a] = b;
  }

  // dp[i][j][k] = i日目にjのパスタを予定しており、jがk日連続している場合の数
  vector<vector<vector<s64>>> dp(n + 1,
                                 vector<vector<s64>>(4, vector<s64>(4, 0)));
  for (s64 i{1}; i <= n; ++i) {
    for (s64 j{1}; j <= 3; ++j) {
      if (plns[i] && plns[i] != j) continue;
      for (s64 k{1}; k <= 3; ++k) {
      }
    }
  }
}