#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  const auto check = [&]() -> bool {
    s64 cnt{0};
    s64 val{a[0]};
    for (s64 i{0}; i < n; ++i) {
      if (a[i] == val) {
        if (++cnt >= 3) return true;
      } else {
        cnt = 1;
        val = a[i];
      }
    }
    return false;
  };

  cout << (check() ? "Yes" : "No") << endl;
}