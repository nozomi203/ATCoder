#include <atcoder/modint>

#include "util/bit.h"
#include "util/common.h"

using mint = atcoder::modint998244353;

mint cmb(u64 n, u64 k) {
  if (n < k) return 0;
  mint ret = 1;
  for (u64 i{1}; i <= n; ++i) ret *= i;
  for (u64 i{1}; i <= k; ++i) ret /= i;
  for (u64 i{1}; i <= n - k; ++i) ret /= i;
  return ret;
}

int main() {
  u64 t;
  cin >> t;
  vector<pair<u64, u64>> nks(t);
  for (u64 i{0}; i < t; ++i) cin >> nks[i].first >> nks[i].second;

  for (auto [n, k] : nks) {
    mint ans = 0;
    vector<u64> ones;
    for (u64 i{0}; i < 64; ++i) {
      if (n & (1ULL << i)) ones.push_back(i);
    }

    vector<vector<pair<mint, mint>>> dp(64, vector<pair<mint, mint>>(k + 1));
    for (s64 i{0}; i < 64; ++i) dp[i][0].second = 1;
    for (s64 i{1}; i < 64; ++i) {
      for (s64 j{1}; j <= k; ++j) {
        if (i < j) break;
        dp[i][j].second = dp[i - 1][j].second + dp[i - 1][j - 1].second;
        dp[i][j].first = dp[i - 1][j].first + dp[i - 1][j - 1].first +
                         (1ULL << (i - 1)) * dp[i - 1][j - 1].second;
      }
    }
    /*
    20=10100
    1100=12
    1010=10
    1001=9
    0110=6
    0101=5
    0011=3
    */
    reverse(ones.begin(), ones.end());
    mint cmn{0};
    for (u64 j{0}; j <= min(k, ones.size()); ++j) {
      if (j == 0) {
        auto add = cmn + dp[ones[0]][k].first;
        ans += add;
      } else if (j == k) {
        ans += cmn;
      } else if (j < ones.size()) {
        auto add = cmn * dp[ones[j]][k - j].second + dp[ones[j]][k - j].first;
        ans += add;
      }
      cmn += (1ULL << (ones[j]));
    }
    cout << ans.val() << endl;
  }
}
