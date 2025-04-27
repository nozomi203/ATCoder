#include <bits/stdc++.h>

#include <atcoder/dsu>
using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, m, k;
  cin >> n >> m >> k;
  vector<tuple<s64, s64, s64>> cabs(m);
  for (s64 i{0}; i < m; ++i)
    cin >> get<1>(cabs[i]) >> get<2>(cabs[i]) >> get<0>(cabs[i]);

  sort(cabs.begin(), cabs.end());

  if (n == k) {
    cout << 0 << endl;
    return 0;
  }

  s64 cnt{n};
  s64 ans{0};
  atcoder::dsu uf(n + 1);
  for (auto [c, a, b] : cabs) {
    if (uf.leader(a) == uf.leader(b)) continue;
    uf.merge(a, b);
    --cnt;
    ans += c;
    if (cnt <= k) break;
  }

  cout << ans << endl;
}