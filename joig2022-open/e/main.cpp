#include "util/common.h"

/*
dp[i] = 種類iの絵を末端に飾ったときの価値の総和の最大値
*/

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> avs(n);
  util::cin(avs);

  const auto ninf = numeric_limits<s64>::lowest();

  s64 mina = 0;
  s64 maxsumv = ninf;
  s64 maxsumv_sub = ninf;
  vector<s64> dp(m + 1, ninf);
  for (auto [a, v] : avs) {
    s64 sumv = a == mina ? maxsumv_sub : maxsumv;
    dp[a] = sumv == ninf ? v
  }
}