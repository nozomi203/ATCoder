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
  for (s64 i{n - 1}; i > 0; --i) {
    if (a[i] == 0) continue;
    s64 idx{-1};
    for (s64 j{i - c[i]}; j < i; ++j) {
      if (j < 0) continue;
      if (a[j]) {
        idx = j;
        break;
      }
    }
    if (idx < 0) {
      s64 max_c{-1};
      for (s64 j{i - c[i]}; j < i; ++j) {
        if (j < 0) continue;
        if (c[j] > max_c) {
          idx = j;
          max_c = c[j];
        }
      }
    }
    a[idx] += a[i];
    a[i] = 0;
    ++ans;
  }
  cout << ans << endl;
}