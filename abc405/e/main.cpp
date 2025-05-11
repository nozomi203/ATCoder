#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

mint fact(s64 n) {
  mint ans = 1;
  for (s64 i{1}; i <= n; ++i) ans *= i;
  return ans;
}

int main() {
  s64 a, b, c, d;
  cin >> a >> b >> c >> d;

  mint x = fact(a + b);
  mint y = fact(a) * fact(b);
  mint z = fact(d - 1 + c);
  mint w = fact(d - 1) * fact(c);

  mint ans = 1;
  ans *= x;
  ans /= y;
  ans *= z;
  ans /= w;
  mint tmp = ans;
  for (s64 i{1}; i <= c; ++i) {
    tmp *= (a + b + i);
    tmp /= (a + i);
    tmp /= (d - 1 + c - i + 1);
    tmp *= (c - i + 1);
    ans += tmp;
  }
  cout << ans.val() << endl;
}