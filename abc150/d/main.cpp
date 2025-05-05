#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

u64 num2(u64 n) {
  u64 cnt{0};
  while (n % 2 == 0) {
    ++cnt;
    n >>= 1;
  }
  return cnt;
}

int main() {
  u64 n, m;
  cin >> n >> m;
  vector<u64> a(n);
  for (u64 i{0}; i < n; ++i) cin >> a[i];
  for (u64 i{0}; i < n; ++i) a[i] /= 2;

  const auto get = [&]() -> u64 {
    const u64 n2 = num2(a[0]);
    for (u64 i{1}; i < n; ++i) {
      if (num2(a[i]) != n2) return 0;
    }

    s64 lcm{1};
    for (s64 i{0}; i < n; ++i) {
      lcm = std::lcm(lcm, a[i]);
      if (lcm > m) return 0;
    }

    u64 xl{0}, xr{m};
    while (xr - xl > 1) {
      u64 mid = (xr + xl) / 2;
      if (lcm * (2 * mid + 1) < m) {
        xl = mid;
      } else {
        xr = mid;
      }
    }

    return xl + 1;
  };

  cout << get() << endl;
}