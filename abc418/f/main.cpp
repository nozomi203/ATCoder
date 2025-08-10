#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<pair<size_t, s64>> xys(q);

  vector<s64> as(n, -1);
  map<size_t, pair<mint, mint>> dp;

  for (auto& [x, y] : xys) {
    --x;
    auto it = dp.find(x);
    if (it == dp.end()) {
      it = dp.emplace(x).first;
    }
    assert(it != dp.end());
    auto pit = prev(it);
    auto nit = next(it);
  }
}