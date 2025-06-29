#include "util/common.h"
#include "util/prime.h"

int main() {
  size_t l, r;
  cin >> l >> r;

  if (l == r) {
    cout << 1 << endl;
    return 0;
  }

  const auto min_factors = util::get_min_factors(l + 1, r + 1);
  size_t cnt = 1;
  for (size_t i = l + 1; i <= r; ++i) {
    const size_t min_factor = min_factors[i - l - 1];
    size_t val = i;
    while (val % min_factor == 0) val /= min_factor;
    if (val == 1) ++cnt;
  }

  cout << cnt << endl;
}