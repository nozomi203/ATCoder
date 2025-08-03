#include <atcoder/lazysegtree>
#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

int main() {
  size_t n, m;
  cin >> n >> m;

  struct node {
    mint val;
    size_t range;
  };
  vector<node> as(n + 1);
  for (size_t i = 1; i <= n; ++i) {
    size_t a;
    cin >> a;
    as[i].val = a;
    as[i].range = 1;
  }
  vector<pair<s64, s64>> lrs(m);
  util::cin(lrs);

  using lazysegtree =
      atcoder::lazy_segtree<node,
                            [](node s0, node s1) -> node {
                              return node{s0.val + s1.val, s0.range + s1.range};
                            },
                            []() -> node { return node{0, 0}; }, optional<mint>,
                            [](optional<mint> f, node s) -> node {
                              return f ? node{*f * s.range, s.range} : s;
                            },
                            [](optional<mint> f0, optional<mint> f1)
                                -> optional<mint> { return f0 ? f0 : f1; },
                            []() -> optional<mint> { return nullopt; }>;

  lazysegtree lst(as);
  for (auto [l, r] : lrs) {
    const auto sum = lst.prod(l, r + 1);
    lst.apply(l, r + 1, sum.val / (r - l + 1));
  }

  for (size_t i = 1; i <= n; ++i) {
    cout << lst.get(i).val.val();
    cout << " ";
  }
  cout << endl;
}