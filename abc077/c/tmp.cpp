#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n), b(n), c(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  for (s64 i{0}; i < n; ++i) cin >> b[i];
  for (s64 i{0}; i < n; ++i) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  vector<s64> sum_cld_b(n, 0);
  for (s64 i{0}; i < n; ++i) {
    auto it = lower_bound(c.begin(), c.end(), b[i] + 1);
    sum_cld_b[i] += distance(it, c.end());
    if (i > 0) sum_cld_b[i] += sum_cld_b[i - 1];
  }

  s64 ans{0};
  for (s64 i{0}; i < n; ++i) {
    auto it = lower_bound(b.begin(), b.end(), a[i] + 1);
    if (it == b.end()) continue;
    auto idx = distance(b.begin(), it);
    ans +=
        (idx == 0) ? sum_cld_b[n - 1] : sum_cld_b[n - 1] - sum_cld_b[idx - 1];
  }
  cout << ans << endl;
}
