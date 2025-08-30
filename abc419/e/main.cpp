#include "util/common.h"

/*

A[i]への操作回数をB[i]とする。
B[0]~B[l-1]が分かっているとき、B[i](i>=l)は

dp[i][j] = k = i + m * xに対し、A[k] = j (mod m)となる操作の最小値
dp2[i][j] = iまでの操作を確定させたとき、A[0] ~
A[i]の和をmで割ったあまりがjとなる操作の最小値

求める答えはdp2[l-1][0]

A[i]をiの昇順に見ていく。(0 <= i < l)
A[i]をmで割ったあまりがkになるようにする場合、そのためのコストはdp[i][k]

任意のjに対して、
dp2[i][(j + k)%m] = min( , dp2[i-1][j] + dp[i][k]
*/

int main() {
  s64 n, m, l;
  cin >> n >> m >> l;
  vector<s64> as(n);
  util::cin(as);

  constexpr auto inf = numeric_limits<s64>::max();
  vector<vector<s64>> dp(l, vector<s64>(m, inf));
  for (s64 i = 0; i < l; ++i) {
    for (s64 j = 0; j < m; ++j) {
      s64 val = 0;
      for (s64 k = i; k < n; k += l) {
        val += (j + m - (as[k] % m)) % m;
      }
      dp[i][j] = val;
    }
  }

  vector<vector<s64>> dp2(l, vector<s64>(m, inf));
  for (s64 j = 0; j < m; ++j) {
    dp2[0][j] = dp[0][j];
  }
  for (s64 i = 1; i < l; ++i) {
    for (s64 j = 0; j < m; ++j) {
      for (s64 k = 0; k < m; ++k) {
        if (dp2[i - 1][j] == inf) continue;
        dp2[i][(j + k) % m] =
            min(dp2[i][(j + k) % m], dp2[i - 1][j] + dp[i][k]);
      }
    }
  }

  cout << dp2[l - 1][0] << endl;
}