#include "util/common.h"
/*
d+r1>=r0
dd+rr1+2*d*r1 >= rr0
2*d*r1 >= rr0 - dd - rr1
*/

int main() {
  size_t n, w, h;
  cin >> n >> w >> h;
  vector<pair<int64_t, int64_t>> xys(n);
  util::cin(xys);
  size_t ans = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      for (size_t k = 0; k < n; ++k) {
        for (size_t l = 0; l < n; ++l) {
          if (i == j || i == k || i == l || j == k || j == l || k == l)
            continue;
          const auto [xa, ya] = xys[i];
          const auto [xb, yb] = xys[j];
          const auto [xc, yc] = xys[k];
          const auto [xd, yd] = xys[l];
          const int64_t dd = (xa - xc) * (xa - xc) + (ya - yc) * (ya - yc);
          const int64_t rr0 = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
          const int64_t rr1 = (xc - xd) * (xc - xd) + (yc - yd) * (yc - yd);
          if (rr0 - dd - rr1 < 0) continue;
          if (4 * dd * rr1 >= (rr0 - dd - rr1) * (rr0 - dd - rr1)) continue;
          if (xa * xa < rr0 || rr0 > (w - xa) * (w - xa) || ya * ya < rr0 ||
              rr0 > (h - ya) * (h - ya))
            continue;
          ++ans;
        }
      }
    }
  }
  cout << ans << endl;
}