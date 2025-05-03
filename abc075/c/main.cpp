#include <bits/stdc++.h>

#include <atcoder/dsu>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> abs(m);
  for (s64 i{0}; i < m; ++i) cin >> abs[i].first >> abs[i].second;

  s64 ans{0};
  for (s64 i{0}; i < m; ++i) {
    atcoder::dsu dsu(n + 1);
    for (s64 j{0}; j < m; ++j) {
      if (i == j) continue;
      dsu.merge(abs[j].first, abs[j].second);
    }
    if (!dsu.same(abs[i].first, abs[i].second)) ++ans;
  }
  cout << ans << endl;
}