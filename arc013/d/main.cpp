#include <atcoder/maxflow>

#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  vector<tuple<size_t, size_t, size_t>> xyzs(n);
  for (size_t i{0}; i < n; ++i) cin_tuple(xyzs[i]);

  set<size_t> s;
  set<pair<size_t, size_t>> sp;

  const auto add = [&](size_t x1, size_t y1, size_t z1, size_t x2, size_t y2,
                       size_t z2) -> void {
    const size_t v1 = x1 * y1 * z1;
    const size_t v2 = x2 * y2 * z2;
    s.emplace(v1);
    s.emplace(v2);
    sp.emplace(make_pair(v1, v2));
  };
  for (const auto& [x, y, z] : xyzs) {
    for (size_t i{1}; i < x; ++i) add(i, y, z, x - i, y, z);
    for (size_t i{1}; i < y; ++i) add(x, i, z, x, y - i, z);
    for (size_t i{1}; i < z; ++i) add(x, y, i, x, y, z - i);
  }
  atcoder::mf_graph<size_t> mfg(16002);
  for (auto v : s) {
    mfg.add_edge(0, v, 1);
    mfg.add_edge(v + 8000, 16001, 1);
  }
  for (auto [v1, v2] : sp) {
    mfg.add_edge(v1, v2 + 8000, 1);
  }

  cout << s.size() * 2 - mfg.flow(0, 16001) << endl;
}