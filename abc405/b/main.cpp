#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  const auto get = [&]() -> s64 {
    map<s64, s64> mp;
    for (s64 i{0}; i < n; ++i) {
      if (a[i] <= m) {
        ++mp[a[i]];
      }
    }

    if (mp.size() < m) return 0;

    for (s64 i{n - 1}; i >= 0; --i) {
      if (a[i] <= m) {
        if (--mp[a[i]] == 0) return n - i;
      }
    }
  };

  cout << get() << endl;
}