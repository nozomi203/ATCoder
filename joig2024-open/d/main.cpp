#include "util/common.h"

s64 digit(s64 n) {
  s64 ret = 0;
  while (n) {
    ++ret;
    n /= 10;
  }
  return ret;
}

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n), bs(n);
  util::cin(as);
  util::cin(bs);
  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());

  vector<s64> das(n), dbs(n);
  transform(as.begin(), as.end(), das.begin(), [](s64 v) { return digit(v); });
  transform(bs.begin(), bs.end(), dbs.begin(), [](s64 v) { return digit(v); });

  s64 ans = 0;
  // a >= b
  {
    s64 j = 0;
    for (s64 i = 0; i < n; ++i) {
      while (j < n && as[i] >= bs[j]) ++j;
      if (j == 0) continue;

      const auto k = invoke([&]() -> s64 {
        if (das[i] < digit(as[i] + bs[0])) return 0;
        if (das[i] == digit(as[i] + bs[j - 1])) return j;

        s64 l = 0, r = j - 1;
        while (r - l > 1) {
          s64 mid = (l + r) / 2;
          if (das[i] == digit(as[i] + bs[mid])) {
            l = mid;
          } else {
            r = mid;
          }
        }
        return r;
      });

      ans += das[i] * j;
      ans += j - k;
    }
  }
  // b > a
  {
    s64 j = 0;
    for (s64 i = 0; i < n; ++i) {
      while (j < n && bs[i] > as[j]) ++j;
      if (j == 0) continue;

      const auto k = invoke([&]() -> s64 {
        if (dbs[i] < digit(bs[i] + as[0])) return 0;
        if (dbs[i] == digit(bs[i] + as[j - 1])) return j;

        s64 l = 0, r = j - 1;
        while (r - l > 1) {
          s64 mid = (l + r) / 2;
          if (dbs[i] == digit(bs[i] + as[mid])) {
            l = mid;
          } else {
            r = mid;
          }
        }
        return r;
      });

      ans += dbs[i] * j;
      ans += j - k;
    }
  }

  cout << ans << endl;
}