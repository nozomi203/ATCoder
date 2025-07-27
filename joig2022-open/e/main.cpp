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

  s64 maxa = -1;
  s64 maxsumv = 0;
  s64 maxa_sub = -2;
  s64 maxsumv_sub = 0;
  vector<s64> dp(m + 1, 0);
  for (auto [a, v] : avs) {
    s64 sumv = a == maxa ? maxsumv_sub : maxsumv;
    sumv =  sumv + v;
    if (dp[a] < sumv) {
      dp[a] = sumv;
      if (maxsumv < dp[a]) {
        if (maxa != a) {
          if (maxsumv_sub < maxsumv) {
            maxsumv_sub = maxsumv;
            maxa_sub = maxa;
          }
        }
        maxa = a;
        maxsumv = dp[a];
      } else if (maxsumv_sub < dp[a]) {
        if (maxa != a) {
          maxsumv_sub = dp[a];
          maxa_sub = maxa;
        }
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;
}