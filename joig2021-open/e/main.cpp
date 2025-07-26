#include "util/common.h"

int main() {
  size_t n, m, l;
  cin >> n >> m >> l;
  vector<tuple<size_t, size_t, size_t>> abcs(m);
  util::cin(abcs);
  for (auto& [a, b, c] : abcs) {
    --a;
    --b;
  }

  const auto toidx = [&](size_t i, size_t j) -> size_t {
    return (m + 1) * i + j;
  };

  const size_t node_cnt = (m + 1) * n;
  vector<vector<pair<size_t, size_t>>> g(node_cnt);
  for (const auto& [a, b, c] : abcs) {
    for (size_t i = 0; i <= m; ++i) {
      g[toidx(a, i)].push_back(make_pair(c, toidx(b, i)));
      if (i < m) g[toidx(b, i)].push_back(make_pair(c, toidx(a, i + 1)));
    }
  }

  constexpr auto inf = numeric_limits<size_t>::max();
  vector<size_t> dists(node_cnt, inf);
  using elem_t = pair<size_t, size_t>;
  priority_queue<elem_t, vector<elem_t>, greater<elem_t>> pq;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    const auto [d, cur] = pq.top();
    pq.pop();

    if (dists[cur] <= d) continue;
    dists[cur] = d;

    for (auto [c, nxt] : g[cur]) {
      const size_t nd = d + c;
      if (dists[nxt] <= nd) continue;
      pq.push(make_pair(nd, nxt));
    }
  }

  for (size_t j = 0; j <= m; ++j) {
    if (dists[toidx(n - 1, j)] <= l) {
      cout << j << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}