#include "util/bipartite_graph.h"
#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<size_t> a(m), b(m);
  for (s64 i{0}; i < m; ++i) cin >> a[i] >> b[i];
  vector<vector<size_t>> g(n);
  for (s64 i{0}; i < m; ++i) {
    g[a[i] - 1].push_back(b[i] - 1);
    g[b[i] - 1].push_back(a[i] - 1);
  }

  const auto get = [&]() -> size_t {
    const auto [suc, v] = util::bipartition(g);
    if (suc) {
      array<size_t, 2> cnts{0, 0};
      for (auto e : v) ++cnts[e];

      size_t ret{0};
      for (size_t i{0}; i < n; ++i) {
        if (v[i]) continue;
        ret += cnts[1] - g[i].size();
      }

      return ret;
    } else {
      return n * (n - 1) / 2 - m;
    }
  };

  cout << get() << endl;
}