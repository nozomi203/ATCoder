#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> p(m);
  for (s64 i{0}; i < m; ++i) cin >> p[i];
  vector<s64> a(n), b(n), c(n);
  for (s64 i{1}; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
  vector<s64> cnts(n);
  for (s64 i{0}; i < m - 1; ++i) {
    auto p0{p[i]};
    auto p1{p[i + 1]};
    if (p0 > p1) swap(p0, p1);
    ++cnts[p0];
    --cnts[p1];
  }
  s64 ans{0};
  s64 cnt{0};
  for (s64 i{1}; i < n; ++i) {
    cnt += cnts[i];
    ans += min(a[i] * cnt, b[i] * cnt + c[i]);
  }

  cout << ans << endl;
}