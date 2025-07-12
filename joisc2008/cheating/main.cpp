#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> xys(m);
  util::cin(xys);

  vector<s64> xs(m), ys(m);
  for (s64 i = 0; i < m; ++i) {
    const auto [x, y] = xys[i];
    xs[i] = x;
    ys[i] = y;
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  const auto check = [&](s64 d) -> bool {
    s64 nx = 0;
    s64 xidx = 0;
    while (xidx < m) {
      const auto x = xs[xidx];
      while (xidx < m && xs[xidx] - x <= d) ++xidx;
      ++nx;
    }
    s64 ny = 0;
    s64 yidx = 0;
    while (yidx < m) {
      const auto y = ys[yidx];
      while (yidx < m && ys[yidx] - y <= d) ++yidx;
      ++ny;
    }

    return nx + ny <= n;
  };

  const auto get_ans = [&]() -> s64 {
    if (check(0)) return 0;
    s64 l = 0, r = 1000000000;
    while (r - l > 1) {
      s64 mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  };

  cout << get_ans() << endl;
}