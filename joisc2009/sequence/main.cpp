#include "util/common.h"

/*
m個の連続した整数の偶奇を各ビットに割り当てて整数で管理
dp[i][j] = ビットiを2^jだけずらしたときのビット
dp2[i][j] = ビットiから2^j個の範囲の奇数の数

dp[i][j] = dp[dp[i][j-1]][j-1];

dp2[i][j] = dp2[dp[i][j-1]][j-1] + dp2[i][j-1];
*/

int main() {
  size_t m, p, q;
  cin >> m >> p >> q;
  --p;
  --q;
  vector<size_t> as(m);
  util::cin(as);
}