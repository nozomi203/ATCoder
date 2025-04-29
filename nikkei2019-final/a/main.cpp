#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n + 1);
  for (s64 i{1}; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  for (s64 i{1}; i <= n; ++i) {
    s64 ans{0};
    for (s64 j{1}; j + i - 1 <= n; ++j) {
      ans = max(ans, a[j + i - 1] - a[j - 1]);
    }
    cout << ans << endl;
  }
}