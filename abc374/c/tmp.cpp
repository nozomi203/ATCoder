#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 3 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\math.h"

namespace util {
uint64_t powi(uint64_t value, uint64_t pow) {
  if (pow == 0) return 1;
  return value * powi(value, pow - 1);
}
}  // namespace util
#line 3 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  vector<s64> k(n);
  for (s64 i{0}; i < n; ++i) cin >> k[i];

  s64 ans{numeric_limits<s64>::max()};
  for (u64 i{0}; i < util::powi(2, n); ++i) {
    s64 s0{0}, s1{0};
    for (s64 j{0}; j < n; ++j) {
      if (i & (1 << j)) {
        s0 += k[j];
      } else {
        s1 += k[j];
      }
    }
    ans = min(ans, max(s0, s1));
  }
  cout << ans << endl;
}
