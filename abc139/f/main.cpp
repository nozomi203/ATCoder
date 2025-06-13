#include "util/arg_sort.h"
#include "util/common.h"

using vec2 = pair<int64_t, int64_t>;

int main() {
  size_t n;
  cin >> n;
  vector<tuple<double, int64_t, int64_t>> xys(n);
  for (size_t i{0}; i < n; ++i) {
    auto& [arg, x, y] = xys[i];
    cin >> x >> y;
    arg = atan2(y, x);
    if (x != 0 || y != 0) {
    }
  }
  // xys.erase(remove(xys.begin(), xys.end(), make_pair(0, 0)), xys.end());
  // n = xys.size();
  // util::arg_sort::sort(xys);
  sort(xys.begin(), xys.end());

  double ans{0.0};
  for (size_t i{0}; i < n; ++i) {
    vec2 sum{};
    for (size_t j{0}; j < n; ++j) {
      const auto [arg, x, y] = xys[(i + j) % n];
      sum.first += x;
      sum.second += y;
      const double l = sum.first * sum.first + sum.second * sum.second;
      const double v = sqrt(l);
      ans = max(ans, v);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}