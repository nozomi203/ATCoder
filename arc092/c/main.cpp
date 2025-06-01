#include <atcoder/maxflow>

#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  vector<pair<size_t, size_t>> abs(n), cds(n);
  for (size_t i{0}; i < n; ++i) cin_pair(abs[i]);
  for (size_t i{0}; i < n; ++i) cin_pair(cds[i]);

  atcoder::mf_graph<size_t> mfg(2 * n + 2);

  for (size_t i{0}; i < n; ++i) {
    mfg.add_edge(2 * n, i, 1);
    mfg.add_edge(i + n, 2 * n + 1, 1);
  }

  for (size_t i{0}; i < n; ++i) {
    const auto [a, b] = abs[i];
    for (size_t j{0}; j < n; ++j) {
      const auto [c, d] = cds[j];
      if (a < c && b < d) {
        mfg.add_edge(i, j + n, 1);
      }
    }
  }

  cout << mfg.flow(2 * n, 2 * n + 1) << endl;
}