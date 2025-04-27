#include <bits/stdc++.h>

#include <atcoder/dsu>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xs(n), ys(n);
  for (s64 i{0}; i < n; ++i) {
    cin >> xs[i].first >> ys[i].first;
    xs[i].second = ys[i].second = i;
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  vector<tuple<s64, s64, s64>> ds;
  ds.reserve(2 * n);
  for (s64 i{0}; i < n - 1; ++i) {
    auto [xl, il] = xs[i];
    auto [xr, ir] = xs[i + 1];
    ds.push_back(make_tuple(xr - xl, il, ir));
  }
  for (s64 i{0}; i < n - 1; ++i) {
    auto [yl, il] = ys[i];
    auto [yr, ir] = ys[i + 1];
    ds.push_back(make_tuple(yr - yl, il, ir));
  }
  sort(ds.begin(), ds.end());

  s64 ans{0};
  atcoder::dsu uf(n);
  for (auto [d, il, ir] : ds) {
    if (uf.same(il, ir)) continue;
    ans += d;
    uf.merge(il, ir);
  }

  cout << ans << endl;
}
