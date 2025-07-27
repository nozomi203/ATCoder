#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<tuple<s64, s64, s64>> abcs(m);
  util::cin(abcs);
  s64 k, t;
  cin >> k >> t;
  vector<s64> ds(k);
  util::cin(ds);
  s64 q;
  cin >> q;
  vector<tuple<s64, s64, s64, s64>> queries(q);
  for (auto& [a, b, c, d] : queries) {
    cin >> a;
    if (a == 1)
      cin >> b >> c >> d;
    else if (a == 2)
      cin >> b;
  }

  const auto inf = numeric_limits<s64>::max();

  vector<vector<pair<s64, s64>>> g(n + 2);
  const s64 airport = n + 1;

  vector<vector<s64>> dists(n + 2, vector<s64>(n + 2, inf));
  for (auto [a, b, c] : abcs) {
    g[a].push_back(make_pair(c, b));
    g[b].push_back(make_pair(c, a));
    dists[a][b] = dists[b][a] = c;
  }
  for (auto d : ds) {
    g[d].push_back(make_pair(t, airport));
    g[airport].push_back(make_pair(0, d));
    dists[d][airport] = t;
    dists[airport][d] = 0;
  }

  const auto update = [&]() -> void {

  };

  for (auto [q0, q1, q2, q3] : queries) {
    if (q0 == 1) {
    } else if (q0 == 2) {
    } else {
    }
  }
}