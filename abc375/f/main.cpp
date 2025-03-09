#include "util/common.h"

int main() {
  s64 n, m, q;
  cin >> n >> m >> q;
  struct conn {
    s64 a;
    s64 b;
    s64 c;
  };
  vector<conn> conns(m);
  for (s64 i{0}; i < m; ++i) cin >> conns[i].a >> conns[i].b >> conns[i].c;

  constexpr s64 inf = numeric_limits<s64>::max();
  vector<vector<s64>> dists(n + 1, vector<s64>(n + 1, inf));
  for (const auto& conn : conns)
    dists[conn.a][conn.b] = dists[conn.b][conn.a] = conn.c;
  for (s64 i{1}; i <= n; ++i) dists[i][i] = 0;

  struct query {
    s64 q;
    s64 x;
    s64 y;
    s64 z;
  };
  vector<query> queries(q);
  for (s64 i{0}; i < q; ++i) {
    cin >> queries[i].q;
    if (queries[i].q == 1) {
      s64 c;
      cin >> c;
      --c;
      queries[i].x = conns[c].a;
      queries[i].y = conns[c].b;
      queries[i].z = conns[c].c;
      dists[queries[i].x][queries[i].y] = dists[queries[i].y][queries[i].x] =
          inf;
    } else {
      cin >> queries[i].x >> queries[i].y;
    }
  }

  for (s64 k{1}; k <= n; ++k) {
    for (s64 i{1}; i <= n; ++i) {
      for (s64 j{1}; j <= n; ++j) {
        if (dists[i][k] != inf && dists[k][j] != inf) {
          dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
        }
      }
    }
  }

  vector<s64> answers;

  for (auto qit = queries.rbegin(); qit != queries.rend(); ++qit) {
    const auto& query = *qit;
    if (query.q == 1) {
      for (s64 i{1}; i <= n; ++i) {
        for (s64 j{1}; j <= n; ++j) {
          if (dists[i][query.x] < inf && dists[query.y][j] < inf) {
            dists[i][j] = min(dists[i][j],
                              dists[i][query.x] + query.z + dists[query.y][j]);
          }
          if (dists[i][query.y] < inf && dists[query.x][j] < inf) {
            dists[i][j] = min(dists[i][j],
                              dists[i][query.y] + query.z + dists[query.x][j]);
          }
        }
      }
    } else {
      answers.push_back(
          dists[query.x][query.y] == inf ? -1 : dists[query.x][query.y]);
    }
  }

  for (auto ait = answers.rbegin(); ait != answers.rend(); ++ait) {
    cout << *ait << endl;
  }
}