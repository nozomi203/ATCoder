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
  for (auto& [p, q, r] : pqrs) p = idx_map[p];

  // 台風の範囲を上書き
  for (auto it_ab = abs.begin(); it_ab != abs.end();) {
    auto& [a, b] = *it_ab;
    {
      auto it = idx_map.lower_bound(a);
      if (it == idx_map.end()) {
        it_ab = abs.erase(it_ab);
        continue;
      }
      a = it->second;
    }
    {
      auto it = idx_map.upper_bound(b);
      if (it == idx_map.begin()) {
        it_ab = abs.erase(it_ab);
        continue;
      }
      b = prev(it)->second;
    }
    ++it_ab;
  }

  // 現実的な範囲になったのでlst
  atcoder::lazy_segtree<size_t,
                        [](size_t s0, size_t s1) -> size_t { return s0 + s1; },
                        []() -> size_t { return 0; }, size_t,
                        [](size_t f, size_t s) -> size_t { return f + s; },
                        [](size_t f0, size_t f1) -> size_t { return f0 + f1; },
                        []() -> size_t { return 0; }>
      lst(idx_map.size());

  for (auto [a, b] : abs) {
    lst.apply(a, b + 1, 1);
  }

  for (auto [p, q, r] : pqrs) {
    cout <<
  }
}