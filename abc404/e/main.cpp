#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n;
  cin >> n;
  vector<s64> c(n);
  for (s64 i{1}; i <= n - 1; ++i) cin >> c[i];
  vector<s64> a(n);
  for (s64 i{1}; i <= n - 1; ++i) cin >> a[i];

  s64 ans{0};
  s64 prv{-1};
  for (s64 i{n - 1}; i >= 0; --i) {
    if (i > 0 && !a[i]) continue;
    if (prv < 0) {
      prv = i;
      continue;
    }

    s64 cnt{0};
    s64 l{prv}, r{prv};
    while (i < l) {
      ++cnt;
      s64 j_max{r};
      r = l;
      for (s64 j{l}; j <= j_max; ++j) {
        l = min(l, j - c[j]);
      }
      l = max<s64>(l, 0);
    }
    ans += cnt;
    prv = i;
  }

  cout << ans << endl;
}