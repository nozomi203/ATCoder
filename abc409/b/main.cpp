#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  vector<size_t> as(n);
  for (size_t i{0}; i < n; ++i) cin >> as[i];

  const auto check = [&](size_t x) -> bool {
    size_t cnt{0};
    for (size_t i{0}; i < n; ++i)
      if (as[i] >= x) ++cnt;

    return cnt >= x;
  };

  size_t l{0}, r{n + 1};
  while (r - l > 1) {
    size_t mid{(r + l) / 2};
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
}