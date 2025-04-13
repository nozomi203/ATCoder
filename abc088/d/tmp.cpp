#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<string> f(h);
  for (s64 i{0}; i < h; ++i) cin >> f[i];
  queue<pair<s64, s64>> q;
  q.push(make_pair(0, 0));
  vector<vector<s64>> dists(h, vector<s64>(w, numeric_limits<s64>::max()));
  dists[0][0] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    const pair<s64, s64> dxys[] = {
        make_pair(0, 1),
        make_pair(0, -1),
        make_pair(1, 0),
        make_pair(-1, 0),
    };
    for (auto [dx, dy] : dxys) {
      auto nxt_x{x + dx}, nxt_y{y + dy};
      if (nxt_x < 0 || h <= nxt_x || nxt_y < 0 || w <= nxt_y) continue;
      if (f[nxt_x][nxt_y] == '#') continue;
      if (dists[nxt_x][nxt_y] <= dists[x][y] + 1) continue;
      dists[nxt_x][nxt_y] = dists[x][y] + 1;
      q.push(make_pair(nxt_x, nxt_y));
    }
  }
  s64 cnt{0};
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      if (f[i][j] == '.') ++cnt;
    }
  }
  if (dists[h - 1][w - 1] == numeric_limits<s64>::max()) {
    cout << -1 << endl;
  } else {
    cout << cnt - dists[h - 1][w - 1] - 1 << endl;
  }
}
