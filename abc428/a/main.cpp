#include "util/common.h"

int main() {
  s64 s, a, b, x;
  cin >> s >> a >> b >> x;
  s64 ans = 0;
  const s64 div = x / (a + b);
  ans += s * a * div;
  x -= div * (a + b);
  ans += s * min(a, x);
  cout << ans << endl;
}