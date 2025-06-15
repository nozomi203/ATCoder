
#include <atcoder/segtree>

#include "util/common.h"

int main() {
  size_t n, d;
  cin >> n >> d;
  vector<vector<size_t>> vss(d, vector<size_t>(n));
  for (size_t i{0}; i < d; ++i) {
    for (size_t j{0}; j < n; ++j) {
      cin >> vss[i][j];
    }
  }

  /*
  dp[i][j][k] = i日目に店舗jからk日連続で商品を購入した場合の合計金額の最小
  */
  constexpr auto inf = numeric_limits<size_t>::max();
  using segtree =
      atcoder::segtree<size_t, [](size_t s0, size_t s1) { return min(s0, s1); },
                       []() { return inf; }>;
  vector<segtree> sts(3, segtree(vector<size_t>(n, 0)));
  for (size_t i{0}; i < d; ++i) {
    vector<vector<size_t>> vs(3, vector<size_t>(n, inf));
    for (size_t k{0}; k < n; ++k) {
      for (size_t j{0}; j < 3; ++j) {
        if (sts[j].prod(0, i) != inf)
          vs[0][k] = min(vs[0][k], sts[j].prod(0, i) + vss[i][k]);
        if (sts[j].prod(k + 1, n) != inf)
          vs[0][k] = min(vs[0][k], sts[j].prod(k + 1, n) + vss[i][k]);
      }
    }
    for (size_t k{0}; k < n; ++k) {
      if (sts[0].get(k) != inf) vs[1][k] = sts[0].get(k) + vss[i][k] * 9 / 10;
      if (sts[1].get(k) != inf) vs[2][k] = sts[1].get(k) + vss[i][k] * 7 / 10;
    }

    for (size_t j{1}; j < 3; ++j) {
      for (size_t k{0}; k < n; ++k) {
        sts[j].set(k, vs[j][k]);
      }
    }
  }

  cout << min({sts[0].all_prod(), sts[1].all_prod(), sts[2].all_prod()})
       << endl;
}