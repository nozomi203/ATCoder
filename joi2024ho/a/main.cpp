#include "util/common.h"

/*
4 6 7

a b c (<t) diff c-a
b c a+t a+t - b

(a+t-b)-(c-a) = 2a-b-c+t

 */
int main() {
  s64 n, t;
  cin >> n >> t;
  vector<s64> as(n);
  util::cin(as);
  for (auto& a : as) a %= t;
  sort(as.begin(), as.end());

  s64 ans = numeric_limits<s64>::max();
  for (s64 imin = 0; imin < n; ++imin) {
    s64 val = (as[(imin + n - 1) % n] - as[imin] + 1) / 2;
    ans = min(ans, val);
    as[imin] = as[imin] + t;
  }
  cout << ans << endl;
}