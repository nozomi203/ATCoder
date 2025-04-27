#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n;
  cin >> n;
  s64 ans{0};
  for (s64 i{0}; i < n; ++i) {
    s64 a;
    cin >> a;
    if (i % 2 == 0) ans += a;
  }
  cout << ans << endl;
}