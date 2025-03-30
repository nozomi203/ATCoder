#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 m, n;
  cin >> m;
  vector<pair<s64, s64>> t(m);
  for (s64 i{0}; i < m; ++i) cin >> t[i].first >> t[i].second;
  cin >> n;
  set<pair<s64, s64>> s;
  for (s64 i{0}; i < n; ++i) {
    s64 x, y;
    cin >> x >> y;
    s.emplace(make_pair(x, y));
  }

  const auto get = [&]() -> pair<s64, s64> {
    auto [ox, oy] = t.front();
    for (auto [x, y] : s) {
      bool cnt{false};
      for (auto [dx, dy] : t) {
        if (!s.contains(make_pair(x + dx - ox, y + dy - oy))) {
          cnt = true;
          break;
        }
      }
      if (cnt) continue;
      return {x - t.front().first, y - t.front().second};
    }

    return {-1, -1};
  };

  auto [dx, dy] = get();
  cout << dx << " " << dy << endl;
}
