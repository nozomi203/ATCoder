#include <atcoder/dsu>

#include "util/common.h"
/*
dsuを使って縮約を管理する
縮約が起きた場合、縮約後のグループのリーダーに対する辺のみ残しておく
*/

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<pair<size_t, size_t>> uvs(m + 1);
  util::cin(uvs.begin() + 1, uvs.end());
  size_t q;
  cin >> q;
  vector<size_t> xs(q);
  util::cin(xs);

  map<size_t, set<size_t>> g;
  for (auto [u, v] : uvs) {
    g[u].insert(v);
    g[v].insert(u);
  }

  size_t cnt{m};
  atcoder::dsu dsu(n + 1);
  for (auto x : xs) {
    auto [u, v] = uvs[x];
    u = dsu.leader(u);
    v = dsu.leader(v);
    if (u != v) {
      const auto w = dsu.merge(u, v);
      if (w == v) swap(u, v);  // guarantee u to be a leader
      --cnt;
      for (auto x : g[v]) {
        if (x == u) continue;
        g[u].insert(x);
        g[x].erase(v);
        if (!g[x].insert(u).second) --cnt;
      }
      g[v].clear();
    }
    cout << cnt << endl;
  }
}