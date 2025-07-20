#include "util/common.h"

#define ASSUMED_SOLUTION 1

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);

#if ASSUMED_SOLUTION
  as.resize(n * 2);
  for (size_t i = n; i < n * 2; ++i) as[i] = as[i - n];

  const s64 total = accumulate(as.begin(), as.begin() + n, 0);

  const auto check = [&](s64 x) -> bool {
    constexpr auto inf = numeric_limits<s64>::max();
    vector<s64> next(n * 2, inf);
    vector<s64> sum(n * 2);
    {
      sum[0] = as[0];
      for (size_t i = 1; i < 2 * n; ++i) sum[i] = sum[i - 1] + as[i];
      size_t j = 0;
      while (j < 2 * n && sum[j] < x) ++j;
      next[0] = j;
      for (size_t i = 1; i < 2 * n; ++i) {
        while (j < 2 * n && sum[j] - sum[next[i - 1]] + as[next[i - 1]] < x)
          ++j;
        if (j >= 2 * n) break;
        next[i] = j;
      }
    }
    for (s64 c0 = 0; c0 < n; ++c0) {
      const s64 c1 = next[c0];
      if (c1 >= 2 * n - 1) continue;
      const s64 c2 = next[c1 + 1];
      if (c2 >= 2 * n - 1) continue;
      if (c2 - c0 + 1 <= n) return true;
    }
    return false;
  };

  s64 xl = 0, xr = total;
  while (xr - xl > 1) {
    s64 x = (xl + xr) / 2;
    if (check(x)) {
      xl = x;
    } else {
      xr = x;
    }
  }
  cout << xl << endl;
#else
  vector<s64> sumas(n);
  sumas[0] = as[0];
  for (s64 i = 1; i < n; ++i) sumas[i] = sumas[i - 1] + as[i];

  const auto getw = [&](s64 l, s64 r) -> s64 {
    assert(l >= 0);
    assert(l <= r);
    if (l >= n) {
      l -= n;
      r -= n;
    }
    s64 ret = sumas[r % n];
    if (r >= n) ret += sumas[n - 1];
    ret -= sumas[l];
    ret += as[l];
    return ret;
  };

  const auto check = [&](s64 c0, s64 c1) -> bool {
    const s64 w0 = getw(c0, c1 - 1);
    const s64 c2 = [&]() -> s64 {
      const s64 wrem = sumas[n - 1] - w0;
      s64 c2l = c1 + 1;
      s64 c2r = c0 + n - 1;
      if (getw(c1, c2l - 1) * 2 >= wrem) return c2l;
      if (getw(c1, c2r - 1) * 2 < wrem) return c2r;
      while (c2r - c2l > 1) {
        s64 c2 = (c2l + c2r) / 2;
        if (getw(c1, c2 - 1) * 2 < wrem) {
          c2l = c2;
        } else {
          c2r = c2;
        }
      }
      return c2r;
    }();
    if (w0 <= min(getw(c1, c2 - 1), getw(c2, c0 + n - 1))) return true;
    if (c2 > c1 + 1) {
      if (w0 <= min(getw(c1, c2 - 2), getw(c2 - 1, c0 + n - 1))) return true;
    }
    return false;
  };

  s64 ans = 0;
  /*i=position of first cut*/
  for (s64 c0 = 0; c0 < n; ++c0) {
    s64 c1l = c0 + 1;
    s64 c1r = c0 + n - 2;
    if (!check(c0, c1l)) continue;
    if (check(c0, c1r)) {
      ans = max(ans, getw(c0, c1r - 1));
      continue;
    }
    while (c1r - c1l > 1) {
      const s64 c1 = (c1r + c1l) / 2;
      if (check(c0, c1)) {
        c1l = c1;
      } else {
        c1r = c1;
      }
    }
    ans = max(ans, getw(c0, c1l - 1));
  }

  cout << ans << endl;
#endif
}