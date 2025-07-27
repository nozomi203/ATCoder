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
  for (auto& [q0, q1, q2, q3] : queries) {
    cin >> q0;
    if (q0 == 1)
      cin >> q1 >> q2 >> q3;
    else if (q0 == 2)
      cin >> q1;
  }

  const auto inf = numeric_limits<s64>::max();

  const s64 airport = n + 1;
  vector<vector<s64>> dists(n + 2, vector<s64>(n + 2, inf));
  for (s64 i = 1; i <= n + 1; ++i) dists[i][i] = 0;
  for (auto [a, b, c] : abcs) {
    dists[a][b] = min(dists[a][b], c);
    dists[b][a] = min(dists[b][a], c);
  }
  for (auto d : ds) {
    dists[d][airport] = t;
    dists[airport][d] = 0;
  }
  for (s64 k = 1; k <= n + 1; ++k) {
    for (s64 i = 1; i <= n + 1; ++i) {
      for (s64 j = 1; j <= n + 1; ++j) {
        if (dists[i][k] == inf || dists[k][j] == inf) continue;
        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
      }
    }
  }

  const auto update = [&](s64 a, s64 b, s64 c) -> void {
    for (s64 i = 1; i <= n + 1; ++i) {
      for (s64 j = 1; j <= n + 1; ++j) {
        if (dists[i][a] == inf || dists[b][j] == inf) continue;
        dists[i][j] = min(dists[i][j], dists[i][a] + c + dists[b][j]);
      }
    }
  };

  for (auto [q0, q1, q2, q3] : queries) {
    if (q0 == 1) {
      update(q1, q2, q3);
      update(q2, q1, q3);
    } else if (q0 == 2) {
      update(q1, airport, t);
      update(airport, q1, 0);
    } else {
      s64 sum = 0;
      for (s64 i = 1; i <= n; ++i) {
        for (s64 j = 1; j <= n; ++j) {
          if (dists[i][j] != inf) sum += dists[i][j];
        }
      }
      cout << sum << endl;
    }
  }
}