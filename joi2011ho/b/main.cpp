#include "util/common.h"

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<pair<s64, s64>> cgs(n);
  util::cin(cgs);
  vector<vector<s64>> sumss(11, vector<s64>(1, 0));
  for (auto [c, g] : cgs) {
    sumss[g].push_back(c);
  }
  for (auto& sums : sumss) sort(sums.begin() + 1, sums.end(), greater());
  for (auto& sums : sumss) {
    for (s64 i = 1; i < sums.size(); ++i) {
      sums[i] += sums[i - 1];
    }
  }

  /*
  dp[i][j] = ジャンルiまでの中でj冊の本を選んで打った時の買い取り額の最大値
  */
  vector<vector<s64>> dp(11, vector<s64>(k + 1, -1));
  for (s64 i = 0; i <= 10; ++i) dp[i][0] = 0;
  for (s64 j = 1; j <= min<s64>(k, sumss[1].size() - 1); ++j)
    dp[1][j] = sumss[1][j] + j * (j - 1);

  for (s64 i = 2; i < 11; ++i) {
    for (s64 j = 1; j <= k; ++j) {
      for (s64 l = 0; l <= j; ++l) {
        if (dp[i - 1][l] == -1) continue;
        if (sumss[i].size() - 1 < j - l) continue;

        dp[i][j] = max<s64>(
            dp[i][j], dp[i - 1][l] + sumss[i][j - l] + (j - l) * (j - l - 1));
      }
    }
  }

  cout << dp[10][k] << endl;
}