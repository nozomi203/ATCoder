#include <atcoder/dsu>

#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<tuple<s64, s64, s64>> xys_x(n), xys_y(n);
  for (s64 i{0}; i < n; ++i) {
    cin >> get<0>(xys_x[i]) >> get<1>(xys_x[i]);
    get<2>(xys_x[i]) = i;
  }
  xys_y = xys_x;
  sort(xys_x.begin(), xys_x.end(),
       [](const auto& l, const auto& r) { return get<0>(l) < get<0>(r); });
  sort(xys_y.begin(), xys_y.end(),
       [](const auto& l, const auto& r) { return get<1>(l) < get<1>(r); });

  atcoder::dsu uf(n);
  s64 idx_x{0}, idx_y{0};
  while (idx_x < n - 1 || idx_y < n - 1) {
    constexpr auto inf = numeric_limits<s64>::max();
    const auto d_x = invoke([&]() {
      if (idx_x >= n - 1) return inf;
      auto [xl, yl, il] = xys_x[idx_x];
      auto [xr, yr, ir] = xys_x[idx_x + 1];
      return min(abs(xr - xl), abs(yr - yl));
    });
    const auto d_y = invoke([&]() {
      if (idx_y >= n - 1) return inf;
      auto [xl, yl, il] = xys_y[idx_y];
      auto [xr, yr, ir] = xys_y[idx_y + 1];
      return min(abs(xr - xl), abs(yr - yl));
    });
    if (d_x < d_y) {
      ++idx_x;
    } else {
      ++idx_y;
    }
  }
}