#include "util/binary_search.h"
#include "util/common.h"

int main() {
  s64 n;
  cin >> n;

  // x^3 - y^3 = (x - y)(x^2 + xy + y^)
  for (s64 a{1}; a <= 1000000; ++a) {
    // a = x - y;
    if (n % a) continue;
    // b = x^2 + xy+ y^2 = (x - y)^2 + 3xy
    s64 b = n / a;
    if (b <= a * a) continue;
    // c = 3xy
    s64 c = b - a * a;
    if (c % 3) continue;
    // c = xy
    c /= 3;
    auto [ok, ng] = util::binary_search<s64>(
        0ll, sqrt(c), [&](s64 y) -> bool { return y * (y + a) < c; });
    if (ng * (ng + a) == c) {
      cout << ng + a << " " << ng << endl;
      return 0;
    } else {
      continue;
    }
  }

  cout << -1 << endl;
}