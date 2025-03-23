#line 1 "main.cpp"
#include <atcoder/fenwicktree>

#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> a(n);
  constexpr size_t val_max = 2 * 100001;
  vector<vector<s64>> val2idxs(val_max);
  atcoder::fenwick_tree<s64> ft(val_max);
  s64 ans{0};
  for (s64 i = 0; i < n; ++i) {
    cin >> a[i];
    val2idxs[a[i]].push_back(i);
    ans += ft.sum(a[i] + 1, val_max);
    ft.add(a[i], 1);
  }
  cout << ans << endl;
  for (s64 c = {1}; c < m; ++c) {
    const auto& idxs = val2idxs[m - c];
    for (s64 i{0}; i < idxs.size(); ++i) {
      const s64 idx = idxs[i];
      ans -= (n - idx - idxs.size() + i);
      ans += (idx - i);
    }
    cout << ans << endl;
  }
}
