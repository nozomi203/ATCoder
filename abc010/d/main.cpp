#include <atcoder/maxflow>

#include "util/common.h"

int main() {
  s64 n, g, e;
  cin >> n >> g >> e;
  vector<s64> p(g);
  for (s64 i{0}; i < g; ++i) cin >> p[i];
  vector<pair<s64, s64>> abs(e);
  for (s64 i{0}; i < e; ++i) cin >> abs[i].first >> abs[i].second;

  atcoder::mf_graph<u64> mfg(n + 1);
  for (size_t i{0}; i < g; ++i) mfg.add_edge(p[i], n, 1);
  for (auto [a, b] : abs) {
    mfg.add_edge(a, b, 1);
  }
  const auto f = mfg.flow(0, n);
  cout << f << endl;
}