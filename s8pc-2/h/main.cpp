#include <atcoder/lazysegtree>

#include "util/common.h"

int main() {
  size_t n, q;
  cin >> n >> q;

  vector<tuple<size_t, size_t, size_t>> qlrs(q);
  for (size_t i{0}; i < q; ++i) cin_tuple(qlrs[i]);

  struct work {
    size_t len;
    size_t cnt;
  };

  atcoder::lazy_segtree<work,
                        [](const work& w0, const work& w1) -> work {
                          return work{w0.len + w1.len, w0.cnt + w1.cnt};
                        },
                        []() -> work { return work{1, 0}; }, size_t,
                        [](size_t f, const work& w) -> work {
                          return work{w.len, f % 2 ? w.len - w.cnt : w.cnt};
                        },
                        [](size_t f0, size_t f1) -> size_t { return f0 + f1; },
                        []() -> size_t { return 0; }>
      lst(n);

  for (auto [q, l, r] : qlrs) {
    if (q == 1) {
      lst.apply(l, r, 1);
    } else {
      cout << lst.prod(l, r).cnt << endl;
    }
  }
}