#include "util/common.h"

s64 get_digit(s64 v) {
  s64 ret = 0;
  while (v) {
    ++ret;
    v /= 10;
  }
  return ret;
}

int main() {
  s64 t;
  cin >> t;
  vector<pair<s64, s64>> cds(t);
  util::cin(cds);

  vector<s64> pow10s(12);
  pow10s[0] = 1;
  for (s64 i = 1; i < 12; ++i) pow10s[i] = pow10s[i - 1] * 10;

  for (auto [c, d] : cds) {
    s64 ans = 0;

    // i = c+dの桁数
    for (s64 i = 1; i <= 10; ++i) {
      const s64 cxmin = max(pow10s[i - 1], c + 1);
      const s64 cxmax = min(pow10s[i] - 1, c + d);
      if (cxmin > cxmax) continue;

      const s64 vmin = c * pow10s[i] + cxmin;
      const s64 vmax = c * pow10s[i] + cxmax;

      const s64 nmax = static_cast<s64>(sqrtl(vmax));
      const s64 nmin = static_cast<s64>(sqrtl(vmin - 1));
      assert(nmax >= nmin);
      const s64 num = nmax - nmin;
      ans += num;
    }
    cout << ans << endl;
  }
}