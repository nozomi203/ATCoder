
#include "util/common.h"
/*

4匹以上のグループは存在するのか？
存在したとする。
それぞれのビーバーをb0 b1 b2 b3とする
距離をd0 d1 d2とする
リーダーが
b0
コスト d0*3+d1*2+d2

b1
コスト d0 + d1*2+d2

b2
コスト d0+d1*2+d2

b3
コスト d0+d1*2+d2*3

いずれの場合も
b0 b1 | b2 b3 このように分割すれば低コスト

グループは最大でも3匹
また、3匹のときのリーダーは真ん中

dp[i] = iまでをグループ化したときの最小移動量

 */
int main() {
  s64 n;
  cin >> n;
  vector<s64> xs(n + 1);
  util::cin(xs.begin() + 1, xs.end());
  util::sort(xs);

  constexpr auto inf = numeric_limits<s64>::max();
  vector<s64> dp(n + 1, inf);
  dp[0] = 0;
  for (s64 i = 1; i <= n; ++i) {
    if (i >= 2 && dp[i - 2] != inf) {
      dp[i] = min(dp[i], dp[i - 2] + xs[i] - xs[i - 1]);
    }

    if (i >= 3 && dp[i - 3] != inf) {
      dp[i] = min(dp[i], dp[i - 3] + xs[i] - xs[i - 2]);
    }
  }

  cout << dp[n] << endl;
}