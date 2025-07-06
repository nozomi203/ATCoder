#include "util/common.h"

int main() {
  s64 t;
  cin >> t;
  vector<vector<s64>> ass(t);
  for (s64 i = 0; i < t; ++i) {
    s64 n;
    cin >> n;
    ass[i].resize(n);
    util::cin(ass[i]);
  }

  const auto check = [&](vector<s64>& as) -> bool {
    sort(as.begin(), as.end(), [](s64 l, s64 r) { return abs(l) > abs(r); });

    // r == 1.0f
    if (all_of(as.begin(), as.end(), [&](s64 v) { return v == as.front(); })) {
      return true;
    }

    // r == -1.0f
    {
      s64 cnt_p = 0, cnt_n = 0;
      for (auto a : as) {
        if (abs(a) != abs(as.front())) continue;
        if (a > 0) {
          ++cnt_p;
        } else {
          ++cnt_n;
        }
      }
      if (cnt_p + cnt_n == as.size() && min(cnt_p, cnt_n) == as.size() / 2)
        return true;
    }

    for (size_t i = 1; i < as.size() - 1; ++i) {
      if (as[i] * as[i] != as[i - 1] * as[i + 1]) return false;
    }

    return true;
  };

  for (auto& as : ass) {
    cout << (check(as) ? "Yes" : "No") << endl;
  }
}