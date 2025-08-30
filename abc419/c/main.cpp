#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> rcs(n);
  util::cin(rcs);
  constexpr auto inf = numeric_limits<s64>::max();
  s64 rmin(inf), rmax(0), cmin(inf), cmax(0);
  for (auto [r, c] : rcs) {
    rmin = min(rmin, r);
    rmax = max(rmax, r);
    cmin = min(cmin, c);
    cmax = max(cmax, c);
  }

  s64 dmax = max(rmax - rmin + 1, cmax - cmin + 1);
  cout << dmax / 2 << endl;
}