#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xys(n);
  util::cin(xys);

  vector<pair<s64, s64>> m;
  vector<pair<s64, s64>> m2;
  m.reserve(n * (n - 1) / 2);
  m2.reserve(n * (n - 1) / 2);
  for (s64 i = 0; i < n - 1; ++i) {
    for (s64 j = i + 1; j < n; ++j) {
      auto [x0, y0] = xys[i];
      auto [x1, y1] = xys[j];

      if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
      }
      auto dx = x1 - x0;
      auto dy = y1 - y0;
      assert(dx != 0 || dy != 0);
      if (dx == 0) {
        dy = 1;
      } else if (dy == 0) {
        dx = 1;
      } else {
        assert(dx > 0);
        const s64 gcd = std::gcd(dx, abs(dy));
        dx /= gcd;
        dy /= gcd;
      }
      m.push_back(make_pair(dx, dy));

      auto xm2 = (x0 + x1);
      auto ym2 = (y0 + y1);
      m2.push_back(make_pair(xm2, ym2));
    }
  }

  sort(m.begin(), m.end());
  sort(m2.begin(), m2.end());
  s64 ans = 0;
  {
    s64 i = 0;
    while (i < m.size()) {
      s64 j = i;
      while (j < m.size() && m[j] == m[i]) ++j;
      s64 cnt = j - i;
      ans += cnt * (cnt - 1) / 2;
      i = j;
    }
  }
  {
    s64 i = 0;
    while (i < m2.size()) {
      s64 j = i;
      while (j < m2.size() && m2[j] == m2[i]) ++j;
      s64 cnt = j - i;
      ans -= cnt * (cnt - 1) / 2;
      i = j;
    }
  }

  cout << ans << endl;
}