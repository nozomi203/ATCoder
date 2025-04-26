#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, m;
  cin >> n >> m;
  constexpr auto inf = numeric_limits<s64>::max();
  vector<vector<s64>> dists(n, vector<s64>(n, inf));
  for (s64 i{0}; i < n; ++i) dists[i][i] = 0;
  for (s64 i{0}; i < m; ++i) {
    s64 a, b, t;
    cin >> a >> b >> t;
    dists[a - 1][b - 1] = dists[b - 1][a - 1] = t;
  }

  for (s64 k{0}; k < n; ++k) {
    for (s64 i{0}; i < n; ++i) {
      for (s64 j{0}; j < n; ++j) {
        if (dists[i][k] == inf || dists[k][j] == inf) continue;
        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
      }
    }
  }

  s64 ans{inf};
  for (s64 i{0}; i < n; ++i) {
    ans = min(ans, *max_element(dists[i].begin(), dists[i].end()));
  }
  cout << ans << endl;
}