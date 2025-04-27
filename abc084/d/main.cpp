#include <bits/stdc++.h>

#include <atcoder/fenwicktree>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> lrs(q);
  for (s64 i{0}; i < q; ++i) cin >> lrs[i].first >> lrs[i].second;
  vector<s64> isp(500001, true);
  isp[0] = isp[1] = false;
  for (s64 i{2}; i < isp.size(); ++i) {
    if (!isp[i]) continue;
    auto v{i * 2};
    while (v < isp.size()) {
      isp[v] = false;
      v += i;
    }
  }

  atcoder::fenwick_tree<s64> ft(500001);
  for (s64 i{0}; i < 500001; ++i) {
    if (!isp[i]) continue;
    if (isp[(i + 1) / 2]) ft.add(i, 1);
  }

  for (auto [l, r] : lrs) {
    cout << ft.sum(l, r + 1) << endl;
  }
}