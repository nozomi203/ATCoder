#include "util/common.h"

/*
dp[i] =
瓶入りコーラがi本残っている時に、そこから飲むことができる瓶入りコーラの最大数
dp[n-1]を求めたい。nが大きくなるのでどうするか
dp[i] = max(dp[i-a+b] + a)
*/

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> abs(m);
  util::cin(abs);
}