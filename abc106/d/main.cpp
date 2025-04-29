#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, m, q;
  cin >> n >> m >> q;
  vector<vector<s64>> cnts(n + 1, vector<s64>(n + 1, 0));
  for (s64 i{0}; i < m; ++i) {
    s64 l, r;
    cin >> l >> r;
    ++cnts[l][r];
  }
  vector<pair<s64, s64>> pqs(q);
  for (s64 i{0}; i < q; ++i) cin >> pqs[i].first >> pqs[i].second;

  vector<vector<s64>> cum(n + 1, vector<s64>(n + 1));
  for (s64 i{1}; i <= n; ++i) {
    for (s64 j{1}; j <= n; ++j) {
      cum[i][j] = cum[i][j - 1] + cnts[i][j];
    }
  }

  for (auto [p, q] : pqs) {
    s64 sum{0};
    for (s64 i{p}; i <= q; ++i) sum += cum[i][q];
    cout << sum << endl;
  }
}