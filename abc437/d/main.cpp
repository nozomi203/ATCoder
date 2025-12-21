#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n), bs(m);
  util::cin(as);
  util::cin(bs);
  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());

  vector<s64> sumbs(m);
  sumbs[0] = bs[0];
  for (s64 i = 1; i < m; ++i) sumbs[i] = sumbs[i - 1] + bs[i];

  mint ans = 0;
  for (auto a : as) {
    auto it = lower_bound(bs.begin(), bs.end(), a);
    if (it == bs.end()) {
      s64 add = a * m - sumbs.back();
      ans += add;
    } else {
      const size_t idx = std::distance(bs.begin(), it);

      const auto sumbl = idx > 0 ? sumbs[idx - 1] : 0;
      const auto sumbr = sumbs.back() - sumbl;
      const auto numbl = idx;
      const auto numbr = m - numbl;
      s64 addl = a * numbl - sumbl;
      s64 addr = sumbr - a * numbr;
      ans += addl;
      ans += addr;
    }
  }
  cout << ans.val() << endl;
}