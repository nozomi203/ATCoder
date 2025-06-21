#include <atcoder/modint>
#include <atcoder/segtree>

#include "util/common.h"
using mint = atcoder::static_modint<1234567>;

int main() {
  size_t n, p;
  cin >> n >> p;
  vector<size_t> hs(n + 1);
  util::cin(hs.begin() + 1, hs.end());
  vector<size_t> sum_hs(n + 1);
  for (size_t i{1}; i <= n; ++i) sum_hs[i] = sum_hs[i - 1] + hs[i];

  using segtree =
      atcoder::segtree<mint, [](mint s0, mint s1) -> mint { return s0 + s1; },
                       []() -> mint { return 0; }>;
  segtree st(n + 1);
  st.set(n, 1);
  for (s64 i{n - 1}; i >= 0; --i) {
    auto it = upper_bound(sum_hs.begin(), sum_hs.end(), sum_hs[i] + p);
    const size_t r = distance(sum_hs.begin(), it);
    st.set(i, st.prod(i + 1, r));
  }
  cout << st.get(0).val() << endl;
}