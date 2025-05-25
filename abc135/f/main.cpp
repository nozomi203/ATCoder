#include <string>

#include "util/common.h"
#include "util/rolling_hash.h"
#include "util/topological_sort.h"

int main() {
  string s, t;
  cin >> s >> t;
  const size_t ssz{s.size()};
  const size_t sz = (1 + (t.size() - 1) / s.size()) * 2;
  s.reserve(sz);
  for (size_t i{0}; i < sz - 1; ++i) s.append(s, 0, ssz);

  util::rolling_hash rhs(s, 1007), rht(t, 1007);
  vector<bool> ok(ssz);
  for (size_t i{0}; i < s.size() - t.size(); ++i) {
    if (rhs.get_hash(i, i + t.size()) == rht.get_hash()) {
      ok[i % ssz] = true;
    }
  }

  vector<vector<size_t>> g(ssz);
  for (size_t i{0}; i < ssz; ++i)
    if (ok[i]) g[i].push_back((i + t.size()) % ssz);

  const auto [b, v] = util::topological_sort(g);
  if (!b) {
    cout << -1 << endl;
    return 0;
  }
  vector<size_t> cnts(ssz);
  for (size_t i{0}; i < ssz; ++i) {
    for (auto nxt : g[v[i]]) {
      cnts[nxt] = max(cnts[nxt], cnts[v[i]] + 1);
    }
  }

  cout << *max_element(cnts.begin(), cnts.end()) << endl;
}