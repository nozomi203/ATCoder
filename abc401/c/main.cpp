#include <atcoder/modint>

#include "util/common.h"

int main() {
  s64 n, k;
  cin >> n >> k;
  using mint = atcoder::static_modint<1000000000>;
  vector<mint> a(n + 1, 0);

  if (k > n) {
    cout << 1 << endl;
    return 0;
  }
  fill(a.begin(), a.begin() + k, 1);
  a[k] = k;
  for (s64 i{k + 1}; i <= n; ++i) {
    a[i] = 2 * a[i - 1] - a[i - k - 1];
  }
  cout << a[n].val() << endl;
}