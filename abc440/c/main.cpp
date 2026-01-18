#include <atcoder/math>

#include "util/common.h"
int main() {
  s64 t;
  cin >> t;
  vector<tuple<s64, s64, vector<s64>>> cases(t);
  for (auto& [n, w, cs] : cases) {
    cin >> n >> w;
    cs.resize(n);
    util::cin(cs);
  }

  for (const auto& [n, w, cs] : cases) {
    s64 sum = 0;
    // x == 1
    for (s64 i = 1; i <= n; ++i) {
      if ((i + 1) % (2 * w) < w) {
        sum += cs[i - 1];
      }
    }
    s64 ans = sum;
    s64 iadd = -3;
    s64 isub = -3 + w;
    for (s64 x = 2; x <= 2 * w; ++x) {
      for (s64 i = iadd; i < n; i += 2 * w) {
        if (i >= 0) {
          sum += cs[i];
        }
      }
      for (s64 i = isub; i < n; i += 2 * w) {
        if (i >= 0) {
          sum -= cs[i];
        }
      }
      ans = min(ans, sum);

      --iadd;
      --isub;
      if (iadd <= -3 - 2 * w) iadd += 2 * w;
      if (isub <= -3 - w) isub += 2 * w;
    }

    cout << ans << endl;
  }
}