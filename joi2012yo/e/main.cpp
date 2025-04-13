#include "util/common.h"

int main() {
  s64 w, h;
  cin >> w >> h;
  vector<vector<s64>> f(h, vector<s64>(w));
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      cin >> f[i][j];
    }
  }

  const pair<s64, s64> dxys[2][6] = {
      {
          make_pair(-1, 0),
          make_pair(0, -1),
          make_pair(0, 1),
          make_pair(1, -1),
          make_pair(1, 0),
          make_pair(1, 1),
      },
      {
          make_pair(-1, -1),
          make_pair(-1, 0),
          make_pair(-1, 1),
          make_pair(0, -1),
          make_pair(0, 1),
          make_pair(1, 0),
      },
  };

  vector<vector<s64>> outside(h, vector<s64>(w, false));
  vector<vector<s64>> opened(h, vector<s64>(w, false));
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      if (f[i][j]) continue;
      if (0 < i && i < h - 1 && 0 < j && j < w - 1) continue;
      queue<pair<s64, s64>> q;
      q.push(make_pair(i, j));
      outside[i][j] = true;
      opened[i][j] = true;
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        for (auto [dx, dy] : dxys[y % 2]) {
          auto nxt_x{x + dx}, nxt_y{y + dy};
          if (nxt_x < 0 || w <= nxt_x || nxt_y < 0 || h <= nxt_y) continue;
          if (opened[nxt_y][nxt_x]) continue;
          if (f[nxt_y][nxt_x]) continue;
          outside[nxt_y][nxt_x] = true;
          opened[nxt_y][nxt_x] = true;
          q.push(make_pair(nxt_y, nxt_x));
        }
      }
    }
  }

  s64 ans{0};
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      if (!f[i][j]) continue;
      s64 cnt{0};
      for (auto [dx, dy] : dxys[i % 2]) {
        auto nxt_x{j + dx}, nxt_y{i + dy};
        if (nxt_x < 0 || w <= nxt_x || nxt_y < 0 || h <= nxt_y ||
            outside[nxt_y][nxt_x])
          ++cnt;
      }
      ans += cnt;
    }
  }
  cout << ans << endl;
}