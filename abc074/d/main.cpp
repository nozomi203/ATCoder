#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n;
  cin >> n;
  vector<vector<s64>> a(n, vector<s64>(n));
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<tuple<s64, s64, s64>> e;
  e.reserve(n * n / 2);
  for (s64 i{0}; i < n - 1; ++i) {
    for (s64 j{i + 1}; j < n; ++j) {
      e.push_back(make_tuple(a[i][j], i, j));
    }
  }
  sort(e.begin(), e.end());

  const auto get = [&]() -> s64 {
    set<s64> s;
    s64 ans{0};
    for (const auto [d, f, t] : e) {
      if (f == t) continue;
      s64 dist_min{numeric_limits<s64>::max()};
      for (auto mid : s) {
        if (mid == f || mid == t) continue;
        dist_min = min(dist_min, a[f][mid] + a[mid][t]);
      }
      if (dist_min < d) return -1;
      if (dist_min > d) ans += d;
      s.emplace(f);
      s.emplace(t);
    }

    return ans;
  };

  cout << get() << endl;
}