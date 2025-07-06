#include <atcoder/fenwicktree>

#include "util/common.h"
int main() {
  s64 n, m, q;
  cin >> n >> m >> q;
  vector<pair<s64, s64>> pas(n + 1);
  util::cin(pas.begin() + 1, pas.end());
  vector<tuple<s64, s64, s64>> tlrs(q);
  util::cin(tlrs);

  vector<vector<s64>> idxs(m + 1);
  atcoder::fenwick_tree<s64> ft(n + 1);
  for (s64 i = 1; i <= n; ++i) {
    auto [p, a] = pas[i];
    idxs[a].push_back(i);
    ft.add(i, p);
  }

  vector<s64> anss(q);
  vector<vector<s64>> cstms(m + 1);
  for (s64 i = 0; i < q; ++i) {
    auto [t, l, r] = tlrs[i];
    cstms[t].push_back(i);
  }

  for (s64 i = 1; i <= m; ++i) {
    for (auto idx : idxs[i]) {
      ft.add(idx, -pas[idx].first / 2);
    }

    for (auto cstm : cstms[i]) {
      auto [t, l, r] = tlrs[cstm];
      anss[cstm] = ft.sum(l, r + 1);
    }

    for (auto idx : idxs[i]) {
      ft.add(idx, pas[idx].first / 2);
    }
  }

  for (auto ans : anss) cout << ans << endl;
}