#include <atcoder/maxflow>

#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xrs(n);
  util::cin(xrs);

  map<s64, s64> dsts;
  for (auto [x, r] : xrs) {
    dsts.emplace(x + r, 0);
    dsts.emplace(x - r, 0);
  }
  s64 idx = 0;
  for (auto& [k, v] : dsts) v = idx++;

  const s64 numdsts = dsts.size();
  atcoder::mf_graph<s64> mf(1 + n + numdsts + 1);

  for (s64 i = 0; i < n; ++i) {
    auto [x, r] = xrs[i];
    mf.add_edge(0, i + 1, 1);
    mf.add_edge(i + 1, dsts[x - r] + n + 1, 1);
    mf.add_edge(i + 1, dsts[x + r] + n + 1, 1);
  }

  for (s64 i = 0; i < numdsts; ++i) {
    mf.add_edge(i + n + 1, n + numdsts + 1, 1);
  }

  const s64 flow = mf.flow(0, n + numdsts + 1);

  cout << flow << endl;
}