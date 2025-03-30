#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  using pos = pair<s64, s64>;
  vector<pos> ps(n);
  set<pair<s64, s64>> exist;
  for (s64 i{0}; i < n; ++i) {
    cin >> ps[i].first >> ps[i].second;
    exist.emplace(ps[i]);
  }

  s64 ans{0};
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < n; ++j) {
      auto [x0, y0] = ps[i];
      auto [x1, y1] = ps[j];
      auto dx = x1 - x0;
      auto dy = y1 - y0;

      auto x2 = x0 + dy;
      auto y2 = y0 - dx;
      auto x3 = x1 + dy;
      auto y3 = y1 - dx;

      auto x2_ = x0 - dy;
      auto y2_ = y0 + dx;
      auto x3_ = x1 - dy;
      auto y3_ = y1 + dx;

      const auto inside = [](s64 x, s64 y) -> bool {
        return 0 <= x && x <= 5000 && 0 <= y && y <= 5000;
      };

      if ((exist.count(make_pair(x2, y2)) && exist.count(make_pair(x3, y3))) ||
          (exist.count(make_pair(x2_, y2_)) &&
           exist.count(make_pair(x3_, y3_)))) {
        ans = max(ans, dx * dx + dy * dy);
      }
    }
  }

  cout << ans << endl;
}
