#include "util/common.h"

int main() {
  s64 t;
  cin >> t;
  vector<tuple<s64, s64, s64>> abcs(t);
  util::cin(abcs);
  for (auto [na, nb, nc] : abcs) {
    const auto check = [&](s64 n) -> bool {
      if (min(na, nc) < n) return false;
      s64 rem = na + nb + nc - 2 * n;
      return rem >= n;
    };

    s64 l = 0;
    s64 r = max({na, nb, nc}) + 1;
    while (r - l > 1) {
      s64 m = (l + r) / 2;
      if (check(m)) {
        l = m;
      } else {
        r = m;
      }
    }

    cout << l << endl;
  }
}