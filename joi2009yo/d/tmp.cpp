#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 m, n;
  cin >> m >> n;
  vector<vector<bool>> f(n, vector<bool>(m));
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < m; ++j) {
      s64 b;
      cin >> b;
      f[i][j] = b;
    }
  }

  vector<vector<bool>> open(n, vector<bool>(m, false));

  s64 ans{0};
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < m; ++j) {
      if (!f[i][j]) continue;

      s64 cnt{0};
      stack<pair<s64, s64>> s;
      s.push(make_pair(i, j));
      while (!s.empty()) {
        auto [x, y] = s.top();
        if (open[x][y]) {
          open[x][y] = false;
          ans = max(ans, cnt);
          --cnt;
          s.pop();

        } else {
          open[x][y] = true;
          ++cnt;
          const pair<s64, s64> dxys[] = {
              make_pair(0, 1),
              make_pair(0, -1),
              make_pair(1, 0),
              make_pair(-1, 0),
          };
          for (auto [dx, dy] : dxys) {
            auto nxt_x = x + dx;
            auto nxt_y = y + dy;
            if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= m) continue;
            if (open[nxt_x][nxt_y]) continue;
            if (!f[nxt_x][nxt_y]) continue;
            s.push(make_pair(nxt_x, nxt_y));
          }
        }
      }
    }
  }

  cout << ans << endl;
}
