#include "util/common.h"
#include "util/math.h"

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