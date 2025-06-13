#include "util/common.h"

int main() {
  s64 n, m, k;
  cin >> n >> m >> k;
  vector<tuple<s64, s64, s64>> abcs(m);
  for (size_t i{0}; i < m; ++i) cin_tuple(abcs[i]);
  vector<pair<s64, s64>> xys(n);
  for (size_t i{0}; i < n; ++i) cin_pair(xys[i]);

  vector<vector<pair<s64, s64>>> g((k + 1) * n);

  const auto get_idx = [&](s64 idx, s64 f) -> s64 { return (k + 1) * idx + f; };

  const auto add_edge = [&](s64 from, s64 to, s64 c) -> void {
    for (s64 i{0}; i < k; ++i) {
      g[get_idx(from, i)].push_back(make_pair(
          xys[from].second, get_idx(from, min(k, i + xys[from].first))));
      g[get_idx(from, i)].push_back(make_pair(c, get_idx(to, i)));
    }
    g[get_idx(from, k)].push_back(make_pair(c, get_idx(to, k)));
  };

  for (auto& [a, b, c] : abcs) {
    --a;
    --b;
    add_edge(a, b, c);
    add_edge(b, a, c);
  }

  using work = pair<s64, s64>;
  priority_queue<work, vector<work>, greater<work>> q;
  q.push(make_pair(0, get_idx(0, 0)));
  constexpr auto inf = numeric_limits<s64>::max();
  vector<s64> dists((k + 1) * n, inf);
  while (!q.empty()) {
    auto [dist, cur] = q.top();
    q.pop();
    if (dist >= dists[cur]) continue;
    dists[cur] = dist;
    for (auto [d, nxt] : g[cur]) {
      if (dist + d >= dists[nxt]) continue;
      q.push(make_pair(dist + d, nxt));
    }
  }
  const auto ans = dists[(k + 1) * n - 1];
  cout << (ans == inf ? -1 : ans) << endl;
}