#include "util/common.h"

using vec2 = pair<int64_t, int64_t>;
int main() {
  size_t n;
  cin >> n;
  vector<size_t> as(n);
  for (size_t i{0}; i < n; ++i) cin >> as[i];
  size_t k;
  cin >> k;

  size_t ans{0};
  for (auto a : as) {
    if (k <= a) ++ans;
  }
  cout << ans << endl;
}