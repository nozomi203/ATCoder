#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<vector<s64>> a(n, vector<s64>(n));
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  s64 mul{1};
  for (s64 i{2 * n - 2}; i >= 0; --i) {
    for (s64 j{0}; j <= i; ++j) {
      if (j >= n || i - j >= n) continue;
      a[j][i - j] = (a[j][i - j] * mul) % m;
    }
    mul = (mul * 10) % m;
  }

  const auto get = [&]() -> s64 {
    if (n == 1) return a[0][0];

    vector<vector<s64>> g0(n), g1(n);
    for (s64 b{0}; b < (1 << (n - 1)); ++b) {
      s64 x{0};
      s64 y{0};
      s64 val{0};
      for (s64 i{0}; i < n - 1; ++i) {
        val = (val + a[x][y]) % m;
        if (b & (1 << i)) {
          ++x;
        } else {
          ++y;
        }
      }
      val = (val + a[x][y]) % m;
      g0[x].push_back(val);
    }
    for (s64 b{0}; b < (1 << (n - 1)); ++b) {
      s64 x{n - 1};
      s64 y{n - 1};
      s64 val{0};
      for (s64 i{0}; i < n - 1; ++i) {
        val = (val + a[x][y]) % m;
        if (b & (1 << i)) {
          --x;
        } else {
          --y;
        }
      }
      g1[x].push_back(val);
    }

    s64 ans{0};
    for (s64 i{0}; i < n; ++i) {
      sort(g1[i].begin(), g1[i].end());
      for (s64 v0 : g0[i]) {
        auto it = lower_bound(g1[i].begin(), g1[i].end(), m - v0);
        if (it != g1[i].begin()) --it;
        ans = max(ans, (v0 + *it) % m);
      }
    }
    return ans;
  };

  cout << get() << endl;
}