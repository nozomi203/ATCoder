#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 h, w, k, v;
  cin >> h >> w >> k >> v;
  vector<vector<s64>> cum(h + 1, vector<s64>(w + 1));
  for (s64 i{1}; i <= h; ++i) {
    for (s64 j{1}; j <= w; ++j) {
      s64 a;
      cin >> a;
      cum[i][j] += a;
      cum[i][j] += cum[i - 1][j] + cum[i][j - 1] - cum[i - 1][j - 1];
    }
  }

  const auto get_cost = [&](s64 a, s64 b, s64 c, s64 d, s64 k) -> s64 {
    return cum[c][d] - cum[a - 1][d] - cum[c][b - 1] + cum[a - 1][b - 1] +
           k * (c - a + 1) * (d - b + 1);
  };

  s64 ans{0};
  for (s64 a{1}; a <= h; ++a) {
    for (s64 b{1}; b <= w; ++b) {
      for (s64 c{a}; c <= h; ++c) {
        if (get_cost(a, b, c, b, k) > v) {
          continue;
        }
        if (get_cost(a, b, c, w, k) <= v) {
          ans = max(ans, (c - a + 1) * (w - b + 1));
          continue;
        }

        s64 d_min{b}, d_max{w};
        while (d_max - d_min > 1) {
          s64 mid{(d_max + d_min) / 2};
          if (get_cost(a, b, c, mid, k) > v) {
            d_max = mid;
          } else {
            d_min = mid;
          }
        }
        ans = max(ans, (c - a + 1) * (d_min - b + 1));
      }
    }
  }
  cout << ans << endl;
}