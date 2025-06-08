#include "util/common.h"

/*
 */

int main() {
  size_t n;
  cin >> n;
  vector<int64_t> xs(n);
  for (size_t i{0}; i < n; ++i) cin >> xs[i];
  vector<tuple<size_t, size_t, size_t>> uvws(n - 1);
  for (size_t i{0}; i < n - 1; ++i) cin_tuple(uvws[i]);

  vector<vector<pair<size_t, size_t>>> g(n);
  for (auto [u, v, w] : uvws) {
    g[u - 1].push_back(make_pair(v - 1, w));
    g[v - 1].push_back(make_pair(u - 1, w));
  }

  size_t ans{0};
  vector<bool> visited(n);
  stack<tuple<size_t, size_t, size_t>> s;
  s.push(make_tuple(-1, 0, 0));
  while (!s.empty()) {
    const auto [prv, cur, w] = s.top();
    if (visited[cur]) {
      s.pop();
      if (prv < 0) continue;
      ans += w * abs(xs[cur]);
      xs[prv] += xs[cur];
      xs[cur] = 0;
    } else {
      visited[cur] = true;
      for (auto nxt : g[cur]) {
        if (visited[nxt.first]) continue;
        s.push(make_tuple(cur, nxt.first, nxt.second));
      }
    }
  }

  cout << ans << endl;
}