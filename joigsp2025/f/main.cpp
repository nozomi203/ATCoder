#include <atcoder/dsu>

#include "util/common.h"

int main() {
  s64 h, w, n;
  cin >> h >> w >> n;
  vector<pair<s64, s64>> rcs(n);
  util::cin(rcs);

  vector<vector<pair<s64, s64>>> vs(w + 1);
  for (s64 i = 0; i < n; ++i) {
    const auto [r, c] = rcs[i];
    vs[c].push_back(make_pair(r, i));
  }
  for (auto& v : vs) sort(v.begin(), v.end());

  vector<tuple<s64, s64, s64>> dfts;

  for (s64 i = 1; i <= w; ++i) {
    const auto& v = vs[i];
    for (s64 j = 0; j < v.size(); ++j) {
      const auto [r, idx] = v[j];
      if (j + 1 < v.size()) {
        const auto [nr, nidx] = v[j + 1];
        dfts.push_back(make_tuple(nr - r - 1, idx, nidx));
      }
      if (i > 1) {
        const auto& pv = vs[i - 1];
        auto it = lower_bound(pv.begin(), pv.end(), pair<s64, s64>(r, 0));
        if (it != pv.end()) {
          auto [nr, nidx] = *it;
          dfts.push_back(make_tuple(nr - r, idx, nidx));
        }
      }
      if (i + 1 <= w) {
        const auto& nv = vs[i + 1];
        auto it = lower_bound(nv.begin(), nv.end(), pair<s64, s64>(r, 0));
        if (it != nv.end()) {
          auto [nr, nidx] = *it;
          dfts.push_back(make_tuple(nr - r, idx, nidx));
        }
      }
    }
  }

  s64 ans = 0;
  atcoder::dsu uf(n);
  sort(dfts.begin(), dfts.end());
  for (auto [dist, from, to] : dfts) {
    if (uf.same(from, to)) continue;
    uf.merge(from, to);
    ans = max(ans, dist);
  }

  cout << (uf.groups().size() == 1 ? ans : -1) << endl;
}