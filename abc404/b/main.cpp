#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

using grid = vector<vector<char>>;

s64 diff(const grid& a, const grid& b, s64 n) {
  s64 ret{0};
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < n; ++j) {
      if (a[i][j] != b[i][j]) ++ret;
    }
  }
  return ret;
}

grid rot(const grid& g, s64 n) {
  grid ret(n, vector<char>(n));
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < n; ++j) {
      ret[j][n - 1 - i] = g[i][j];
    }
  }
  return ret;
}

int main() {
  s64 n;
  cin >> n;
  grid s(n, vector<char>(n)), t(n, vector<char>(n));
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < n; ++j) {
      cin >> s[i][j];
    }
  }
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < n; ++j) {
      cin >> t[i][j];
    }
  }

  s64 ans{numeric_limits<s64>::max()};
  for (s64 i{0}; i < 4; ++i) {
    ans = min(ans, diff(s, t, n) + i);
    s = rot(s, n);
  }
  cout << ans << endl;
}