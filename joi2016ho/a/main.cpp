#include "util/common.h"
#include "util/sparse_table.h"
/*
dp?  dp[i] = iこ目までのオレンジを箱詰めするときのコストの最小値
dp[i] = min(
dp[i-1] + ([i,i+1)を1つの箱にした時のコスト),
dp[i-2] + ([i-1,i+1)を1つの箱にした時のコスト),
...,
dp[0] + ([1,i+1)を1つの箱にした時のコスト)
)
*/

int main() {
  int64_t n, m, k;
  cin >> n >> m >> k;
  vector<int64_t> as(n + 1);
  util::cin(as.begin() + 1, as.end());
  vector<int64_t> dp(n + 1, numeric_limits<int64_t>::max());
  dp[0] = 0;
  for (int64_t i = 1; i <= n; ++i) {
    int64_t amin = as[i], amax = as[i];
    for (int64_t j = 1; j <= m; ++j) {
      if (i - j < 0) break;
      dp[i] = min(dp[i], dp[i - j] + k + j * (amax - amin));
      amin = min(amin, as[i - j]);
      amax = max(amax, as[i - j]);
    }
  }
  cout << dp[n] << endl;
}