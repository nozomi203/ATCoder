#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  vector<vector<s64>> cnts_l(n + 1, vector<s64>(2, 0)),
      cnts_r(n, vector<s64>(2, 0));
  ++cnts_r[n - 1][a[n - 1]];
  for (s64 i{n - 2}; i >= 0; --i) {
    cnts_r[i][a[i]] = cnts_r[i + 1][(a[i] + 1) % 2] + 1;
  }
  for (s64 i{1}; i <= n; ++i) {
    cnts_l[i][a[i - 1]] = cnts_l[i - 1][(a[i - 1] + 1) % 2] + 1;
  }

  s64 ans{0};
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < 2; ++j) {
      ans = max(ans, cnts_r[i][j] + cnts_l[i][(j + 1) % 2]);
      auto val = cnts_r[i][j] + cnts_l[i][j];
      if (i + cnts_r[i][j] < n) {
        val += cnts_r[i + cnts_r[i][j]][(j + cnts_r[i][j] + 1) % 2];
      }
      ans = max(ans, val);
    }
  }

  cout << ans << endl;
}