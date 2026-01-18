#include <atcoder/math>

#include "util/common.h"
int main() {
  s64 n, q;
  cin >> n >> q;
  vector<s64> as(n);
  util::cin(as);
  vector<pair<s64, s64>> xys(q);
  util::cin(xys);

  sort(as.begin(), as.end());

  for (auto [x, y] : xys) {
    const auto get = [&]() -> s64 {
      auto it = lower_bound(as.begin(), as.end(), x);
      if (it == as.end()) return x + y - 1;
      const s64 idx = distance(as.begin(), it);

      {
        s64 vl = (as[idx] - x + 1) - (idx - idx + 1);
        if (vl >= y) return x + y - 1;
      }

      {
        s64 vr = (as.back() - x + 1) - ((n - 1) - idx + 1);
        if (vr < y) return as.back() + (y - vr);
      }

      // vl<y && vr >= y
      s64 il = idx;
      s64 ir = n - 1;
      while (ir - il > 1) {
        s64 im = (il + ir) / 2;
        s64 vm = (as[im] - x + 1) - (im - idx + 1);
        if (vm < y) {
          il = im;
        } else {
          ir = im;
        }
      }

      const s64 vl = (as[il] - x + 1) - (il - idx + 1);
      assert(vl < y);
      return as[il] + (y - vl);
    };
    cout << get() << endl;
  }
}