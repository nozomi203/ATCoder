#include <atcoder/dsu>

#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  struct edge {
    s64 u;
    s64 v;
    s64 c;
  };

  vector<edge> edges(m);
  for (s64 i{0}; i < m; ++i) cin >> edges[i].u >> edges[i].v >> edges[i].c;

  sort(edges.begin(), edges.end(),
       [](const edge& el, const edge& er) { return el.c < er.c; });

  atcoder::dsu dsu(n + 1);
  s64 ans{0};
  for (const auto& e : edges) {
    if (dsu.leader(e.u) != dsu.leader(e.v)) {
      dsu.merge(e.u, e.v);
      ans += e.c;
    }
  }

  cout << ans << endl;
}