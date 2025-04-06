#include "util/bit.h"
#include "util/common.h"

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  s64 ans{numeric_limits<s64>::max()};
  for (u64 b{0}; b < (1 << n); ++b) {
    if (util::bit_count(b) != k) continue;
    s64 cost{0};
    s64 max_height{0};
    for (s64 i{0}; i < n; ++i) {
      if (b & (1 << i)) {
        if (a[i] <= max_height) {
          cost += (max_height + 1) - a[i];
          ++max_height;
        } else {
          max_height = a[i];
        }
      } else {
        max_height = max(max_height, a[i]);
      }
    }

    ans = min(ans, cost);
  }

  cout << ans << endl;
}