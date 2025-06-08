#include <atcoder/lazysegtree>

/*
観測点の数が多いので、観測点毎の被害を記録するのは現実的でない
台風毎に被害を与えた範囲を記録しておき、それを効率よく数えあげられるようにしたい
台風の範囲[l,r]が与えられた時、その台風が観測点pに被害を与えられているかを取得したい
pの個数と値は事前に分かっている
a<=i && i<=bを満たすpの個数->a-i<= 0 && b-i>= 0を満たすpの個数
*/

#include "util/common.h"

int main() {
  size_t n, m, k;
  cin >> n >> m >> k;
  vector<pair<size_t, size_t>> abs(n);
  for (size_t i{0}; i < n; ++i) cin_pair(abs[i]);
  vector<tuple<size_t, size_t, size_t>> pqrs(m);
  for (size_t i{0}; i < m; ++i) cin_tuple(pqrs[i]);

  // 次元圧縮
  map<size_t, size_t> idx_map;
  {
    for (auto [p, q, r] : pqrs) idx_map.emplace(p, 0);
    size_t idx{0};
    for (auto& [k, v] : idx_map) v = idx++;
  }

  // クエリ上書き
  for (auto& [p, q, r] : pqrs) {
    p = idx_map[p];
    --q;
    --r;
  }

  constexpr size_t invalid = numeric_limits<size_t>::max();
  // 台風の範囲を上書き
  for (auto& [a, b] : abs) {
    {
      auto it = idx_map.lower_bound(a);
      a = it == idx_map.end() ? invalid : it->second;
    }
    {
      auto it = idx_map.upper_bound(b);
      b = it == idx_map.begin() ? invalid : prev(it)->second;
    }
  }

  // 現実的な範囲になったのでlst
  atcoder::lazy_segtree<size_t,
                        [](size_t s0, size_t s1) -> size_t { return s0 + s1; },
                        []() -> size_t { return 0; }, size_t,
                        [](size_t f, size_t s) -> size_t { return f + s; },
                        [](size_t f0, size_t f1) -> size_t { return f0 + f1; },
                        []() -> size_t { return 0; }>
      lst(idx_map.size());

  vector<vector<size_t>> list(n);
  map<pair<size_t, size_t>, size_t> values;
  for (auto [p, q, r] : pqrs) {
    if (q > 0) list[q - 1].push_back(p);
    list[r].push_back(p);
  }

  for (size_t i{0}; i < n; ++i) {
    const auto [a, b] = abs[i];
    if (a == invalid || b == invalid) continue;
    lst.apply(a, b + 1, 1);
    for (auto k : list[i]) {
      values[make_pair(i, k)] = lst.prod(k, k + 1);
    }
  }

  for (auto [p, q, r] : pqrs) {
    size_t ans = values[make_pair(r, p)];
    if (q > 0) ans -= values[make_pair(q - 1, p)];
    cout << ans << endl;
  }
}