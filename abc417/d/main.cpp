#include "util/common.h"

/*
テンションは最大でも±5*10^6
テンションが5*10^6以上なら下がる一方
*/

int main() {
  s64 n;
  cin >> n;
  vector<tuple<s64, s64, s64>> pabs(n);
  util::cin(pabs);
  s64 q;
  cin >> q;
  vector<s64> xs(q);
  util::cin(xs);

  s64 maxpa = 0;
  for (auto [p, a, b] : pabs) maxpa = max<s64>(maxpa, p + a);

  vector<vector<s64>> dp(n, vector<s64>(maxpa + 1));
  for (s64 i = n - 1; i >= 0; --i) {
    const auto [p, a, b] = pabs[i];
    for (s64 j = 0; j <= maxpa; ++j) {
      if (j <= p) {
        dp[i][j] = i + 1 < n ? dp[i + 1][j + a] : j + a;
      } else {
        dp[i][j] =
            i + 1 < n ? dp[i + 1][max<s64>(j - b, 0)] : max<s64>(j - b, 0);
      }
    }
  }

  vector<s64> sumbs(n);
  for (size_t i = 0; i < n; ++i) {
    auto [p, a, b] = pabs[i];
    sumbs[i] = i ? (sumbs[i - 1] + b) : b;
  }

  const auto get = [&](s64 x) -> s64 {
    if (x <= maxpa) return dp[0][x];

    auto it = lower_bound(sumbs.begin(), sumbs.end(), x - maxpa);
    const size_t nidx = distance(sumbs.begin(), it);
    if (nidx >= n - 1) {
      return max<s64>(x - sumbs.back(), 0);
    } else {
      return dp[nidx + 1][max<s64>(x - *it, 0)];
    }
  };
  for (auto x : xs) {
    cout << get(x) << endl;
  }
}