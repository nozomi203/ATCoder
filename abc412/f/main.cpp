#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

int main() {
  s64 n, c;
  cin >> n >> c;
  vector<s64> as(n + 1);
  util::cin(as.begin() + 1, as.end());
  ++as[c];
  vector<pair<s64, s64>> ais(n + 1);
  for (size_t i = 0; i <= n; ++i) {
    ais[i].first = as[i];
    ais[i].second = i;
  }
  sort(ais.begin(), ais.end());
  for (s64 i = 0; i <= n; ++i) {
    if (ais[i].second == c) {
      c = i;
      break;
    }
  }

  const mint s = accumulate(as.begin(), as.end(), 0) - 1;

  vector<mint> acums(n + 1);
  for (s64 i = 0; i <= n; ++i) acums[i] += ais[i].first;
  for (s64 i = 1; i <= n; ++i) acums[i] += acums[i - 1];

  vector<mint> dp(n + 1);
  mint sum = 0;
  for (s64 i = n; i > 0; --i) {
    dp[i] = 1;
    dp[i] += sum;
    dp[i] /= (1 - acums[i - 1] / s);

    sum += dp[i] * ais[i].first / s;
  }

  cout << dp[c].val() << endl;
}