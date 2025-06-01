
#include <atcoder/segtree>

#include "util/common.h"

int main() {
  int32_t n, d, r;
  cin >> n >> d >> r;
  vector<int32_t> hs(n);
  for (size_t i{0}; i < n; ++i) cin >> hs[i];

  vector<pair<size_t, size_t>> v(n);
  for (size_t i{0}; i < n; ++i) v[i] = make_pair(hs[i], i);
  sort(v.begin(), v.end());

  atcoder::segtree<int32_t,
                   [](int32_t l, int32_t r) -> int32_t { return max(l, r); },
                   []() -> int32_t { return -1; }>
      st(std::vector<int32_t>(n, -1));

  vector<size_t> cnts(n);
  for (auto [h, i] : v) {
    if (h >= d + 1) st.set(v[h - d - 1].second, cnts[v[h - d - 1].second]);
    const int32_t range_l = max<int32_t>(0, i - r);
    const int32_t range_r = min<int32_t>(i + r + 1, n);
    auto q = st.prod(range_l, range_r);
    cnts[i] = q < 0 ? 0 : q + 1;
  }

  cout << *max_element(cnts.begin(), cnts.end()) << endl;
}