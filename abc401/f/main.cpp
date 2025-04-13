#include "util/common.h"

using graph = vector<vector<s64>>;

vector<s64> get_depth(const graph& g, s64 root) {
  vector<s64> depth(g.size(), 0);
  stack<pair<s64, s64>> s;
  s.push(make_pair(-1, root));
  while (!s.empty()) {
    auto [prv, cur] = s.top();
    s.pop();
    if (prv >= 0) depth[cur] = depth[prv] + 1;

    for (auto nxt : g[cur]) {
      if (nxt == prv) continue;
      s.push(make_pair(cur, nxt));
    }
  }

  return depth;
}

pair<s64, s64> max_depth(const graph& g, s64 root) {
  const auto depth = get_depth(g, root);
  auto it = max_element(depth.begin(), depth.end());
  return {distance(depth.begin(), it), *it};
}

tuple<s64, s64, s64> diam(const graph& g) {
  auto [e0, d0] = max_depth(g, 0);
  auto [e1, d1] = max_depth(g, e0);
  return {e0, e1, d1};
}

int main() {
  s64 n1;
  cin >> n1;
  graph g1(n1);
  for (s64 i{0}; i < n1 - 1; ++i) {
    s64 u, v;
    cin >> u >> v;
    g1[u - 1].push_back(v - 1);
    g1[v - 1].push_back(u - 1);
  }
  s64 n2;
  cin >> n2;
  graph g2(n2);
  for (s64 i{0}; i < n2 - 1; ++i) {
    s64 u, v;
    cin >> u >> v;
    g2[u - 1].push_back(v - 1);
    g2[v - 1].push_back(u - 1);
  }

  const auto [b1, e1, diam1] = diam(g1);
  const auto db1 = get_depth(g1, b1);
  const auto de1 = get_depth(g1, e1);

  const auto [b2, e2, diam2] = diam(g2);
  const auto db2 = get_depth(g2, b2);
  const auto de2 = get_depth(g2, e2);

  const auto max_diam{max(diam1, diam2)};

  vector<s64> d1(n1), d2(n2);
  for (s64 i{0}; i < n1; ++i) d1[i] = max(db1[i], de1[i]);
  for (s64 i{0}; i < n2; ++i) d2[i] = max(db2[i], de2[i]);
  sort(d1.begin(), d1.end());
  sort(d2.begin(), d2.end());
  vector<s64> sum_d2(n2);
  sum_d2[0] = d2[0];
  for (s64 i{1}; i < n2; ++i) sum_d2[i] = sum_d2[i - 1] + d2[i];

  s64 ans{0};
  s64 j{n2 - 1};
  for (s64 i{0}; i < n1; ++i) {
    while (j >= 0 && d1[i] + d2[j] + 1 > max_diam) {
      --j;
    }
    if (j < 0) {
      ans += (d1[i] + 1) * n2 + sum_d2[n2 - 1];
    } else {
      ans += (d1[i] + 1) * (n2 - j - 1) + sum_d2[n2 - 1] - sum_d2[j];
      ans += max_diam * (j + 1);
    }
  }
  cout << ans << endl;
}