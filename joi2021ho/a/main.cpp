#include "util/common.h"
/*
kを固定して考える。
a[i] >= a[i+1]であるとき、i+1はiよりも(a[i] - a[i+1] +
1回多く水をかけてもらう必要がある
*/

int main() {
  size_t n;
  cin >> n;
  vector<size_t> as(n);
  util::cin(as);

  vector<size_t> dp(n), dp2(n);
  for (size_t i = 1; i < n; ++i) {
    if (as[i] > as[i - 1]) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = dp[i - 1] + (as[i - 1] - as[i] + 1);
    }
  }
  for (s64 i = n - 2; i >= 0; --i) {
    if (as[i] > as[i + 1]) {
      dp2[i] = dp2[i + 1];
    } else {
      dp2[i] = dp2[i + 1] + (as[i + 1] - as[i] + 1);
    }
  }

  size_t ans = numeric_limits<size_t>::max();
  for (size_t i = 0; i < n; ++i) {
    ans = min(ans, max(dp[i], dp2[i]));
  }
  cout << ans << endl;
}