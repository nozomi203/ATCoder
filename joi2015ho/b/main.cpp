#include "util/common.h"

s64 get(vector<vector<s64>>& dp, const vector<s64>& a, s64 l, s64 r,
        bool take) {
  if (dp[l][r] >= 0) {
    return dp[l][r];
  }

  if (l == r) {
    if (take) {
      return dp[l][r] = a[l];
    } else {
      return 0;
    }
  }
  const s64 val =
      take          ? max(a[l] + get(dp, a, (l + 1) % a.size(), r, false),
                          a[r] + get(dp, a, l, (r - 1 + a.size()) % a.size(), false))
      : a[l] > a[r] ? get(dp, a, (l + 1) % a.size(), r, true)
                    : get(dp, a, l, (r - 1 + a.size()) % a.size(), true);
  return dp[l][r] = val;
}

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  vector<vector<s64>> dp(n, vector<s64>(n, -1));
  s64 ans{0};
  for (s64 i{0}; i < n; ++i) {
    ans = max(ans, a[i] + get(dp, a, (i + 1) % n, (i + n - 1) % n, false));
  }
  cout << ans << endl;
}