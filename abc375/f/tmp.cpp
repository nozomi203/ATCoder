#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

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
  vector<vector<bool>> blocked(n + 1, vector<bool>(n + 1, false));
  const auto update_dist = [&]() {
    for (auto& v : dists) fill(v.begin(), v.end(), inf);
    for (const auto& conn : conns)
      if (!blocked[conn.a][conn.b])
        dists[conn.a][conn.b] = dists[conn.b][conn.a] = conn.c;

    for (s64 i{1}; i <= n; ++i) dists[i][i] = 0;

    for (s64 k{1}; k < n; ++k) {
      for (s64 i{1}; i <= n; ++i) {
        for (s64 j{1}; j <= n; ++j) {
          if (dists[i][k] != inf && dists[k][j] != inf) {
            dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
          }
        }
      }
    }
  };
  update_dist();

  vector<s64> answers;

  for (s64 i{0}; i < q; ++i) {
    s64 q;
    cin >> q;
    if (q == 1) {
      s64 i;
      cin >> i;
      --i;
      blocked[conns[i].a][conns[i].b] = blocked[conns[i].b][conns[i].a] = true;
      update_dist();
    } else {
      s64 i, j;
      cin >> i >> j;
      answers.push_back(dists[i][j] == inf ? -1 : dists[i][j]);
    }
  }

  for (auto ans : answers) {
    cout << ans << endl;
  }
}
