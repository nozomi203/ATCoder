#include "util/common.h"
/*
ABをAの昇順にソート
Amaxを固定し、(S + Amin)を最大化する
AminとしてAiを選んだとする。
AminをAi-1に変更すると変化量はBi-1 - (Ai -Ai-1)
*/

int main() {
  size_t n;
  cin >> n;
  vector<pair<s64, s64>> abs(n);
  util::cin(abs);
  sort(abs.begin(), abs.end());

  vector<s64> sumbs(n);
  sumbs[0] = abs[0].second;
  for (size_t i = 1; i < n; ++i) {
    sumbs[i] = sumbs[i - 1] + abs[i].second;
  }

  s64 ans = numeric_limits<s64>::lowest();
  /*s+aminの最大値*/
  vector<s64> dp(n);
  for (size_t i = 0; i < n; ++i) {
    const s64 amax = abs[i].first;
    dp[i] = abs[i].first + abs[i].second;
    if (i > 0) dp[i] = max(dp[i], dp[i - 1] + abs[i].second);
    ans = max(ans, dp[i] + abs[i].first);
  }
  cout << ans << endl;
}