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
  vector<vector<s64>> rds(n + 1, vector<s64>(n + 1, inf));
  vector<vector<s64>> aps(n + 1, vector<s64>(n + 1, inf));

  for (auto [a, b, c] : abcs) {
    rds[a][b] = rds[b][c] = c;
  }
  for (size_t i = 0; i < k; ++i) {
    for (size_t j = 0; j < k; ++k) {
      if (i == j) continue;
      aps[i][j] = t;
    }
  }

  for (auto [a, b, c, d] : queries) {
    if (a == 1) {
      rds[b][c] = rds[c][b] = d;
    } else if (a == 2) {
      for (auto d : ds) aps[d][b] = aps[b][d] = t;
      ds.push_back(b);
    }
  }

  reverse(queries.begin(), queries.end());
  for (auto [a, b, c, d] : queries) {
    if (a == 1) {
      rds[b][c] = rds[c][b] = d;
    } else if (a == 2) {
      for (auto d : ds) aps[d][b] = aps[b][d] = t;
      ds.push_back(b);
    } else {
    }
  }
}