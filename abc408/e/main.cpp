#include "util/common.h"

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<pair<uint32_t, uint32_t>>> g(n);
  for (size_t i{0}; i < m; ++i) {
    uint32_t u, v, w;
    cin >> u >> v >> w;
    g[u - 1].push_back(make_pair(v - 1, w));
    g[v - 1].push_back(make_pair(u - 1, w));
  }

  const auto check = [&](uint32_t mask) -> bool {
    const size_t mask_inv{~mask};
    vector<bool> visited(n);
    queue<size_t> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
      const auto cur = q.front();
      q.pop();
      for (auto [nxt, w] : g[cur]) {
        if (visited[nxt]) continue;
        if (mask_inv & w) continue;
        visited[nxt] = true;
        q.push(nxt);
      }
    }

    return visited[n - 1];
  };

  const auto get = [&]() -> uint32_t {
    if (check(0)) return 0;

    uint32_t l{0}, r{numeric_limits<uint32_t>::max()};
    while (r - l > 1) {
      const uint32_t mid{(r + l) / 2};

      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  };

  cout << get() << endl;
}