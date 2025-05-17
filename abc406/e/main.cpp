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
    reverse(ones.begin(), ones.end());
    for (u64 j{0}; j <= min(k, ones.size()); ++j) {
      if (j == 0) {
        auto add = cmb(ones[0], k);
        ans += add;
      } else if (j == k) {
        ans += 1;
      } else {
        auto add = cmb(ones[j], k - j);
        ans += add;
      }
    }
    cout << ans.val() << endl;
  }
}
