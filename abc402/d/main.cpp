#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> ab(m);
  for (s64 i{0}; i < m; ++i) cin >> ab[i].first >> ab[i].second;

  vector<vector<s64>> g(n + 1, vector<s64>(2, 0));
  for (auto [a, b] : ab) {
    if (a > b) swap(a, b);
    auto sum = a + b;
    auto idx = sum % 2 ? 1 : 0;
    auto mid = sum / 2;
    if (idx) {
      if (mid > n / 2) {
        mid -= n / 2;
        if (n % 2) idx = 0;
      }
    } else {
      if (mid > (n + 1) / 2) {
        mid -= (n + 1) / 2;
        if (n % 2) idx = 1;
      }
    }
    ++g[mid][idx];
  }

  s64 ans{0};
  for (const auto& x : g) {
    for (const auto y : x) {
      if (!y) continue;
      ans += (m - y) * y;
    }
  }
  cout << ans / 2 << endl;
}