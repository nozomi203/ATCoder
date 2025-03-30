#line 1 "main.cpp"
#include <atcoder/dsu>

#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "main.cpp"

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
