#include <atcoder/all>

#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> abs(m + 1);
  for (s64 i{1}; i <= m; ++i) cin >> abs[i].first >> abs[i].second;

  s64 q;
  cin >> q;
  vector<pair<s64, s64>> xys(q + 1);
  for (s64 i{1}; i <= q; ++i) cin >> xys[i].first >> xys[i].second;

  vector<pair<s64, s64>> lrs(q + 1, make_pair(0, m + 1));

  while (any_of(next(lrs.begin()), lrs.end(),
                [](pair<s64, s64>& lr) { return lr.second - lr.first > 1; })) {
    vector<vector<s64>> mid_idxs(m + 2);
    for (s64 idx{1}; idx <= q; ++idx) {
      mid_idxs[(lrs[idx].first + lrs[idx].second) / 2].push_back(idx);
    }

    atcoder::dsu uf(n + 1);
    for (s64 i{0}; i < m + 2; ++i) {
      if (i == 0) {
        for (auto mid_idx : mid_idxs[i]) {
          lrs[mid_idx].first = (lrs[mid_idx].first + lrs[mid_idx].second) / 2;
        }
        continue;
      }
      if (i == m + 1) {
        for (auto mid_idx : mid_idxs[i]) {
          lrs[mid_idx].second = (lrs[mid_idx].first + lrs[mid_idx].second) / 2;
        }
        continue;
      }

      uf.merge(abs[i].first, abs[i].second);
      for (auto mid_idx : mid_idxs[i]) {
        if (uf.same(xys[mid_idx].first, xys[mid_idx].second)) {
          lrs[mid_idx].second = (lrs[mid_idx].first + lrs[mid_idx].second) / 2;
        } else {
          lrs[mid_idx].first = (lrs[mid_idx].first + lrs[mid_idx].second) / 2;
        }
      }
    }
  }

  for (s64 i{1}; i <= q; ++i) {
    cout << (lrs[i].second == m + 1 ? -1 : lrs[i].second) << endl;
  }
}