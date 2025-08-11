#include "util/common.h"

int main() {
  s64 W, H, n;
  cin >> W >> H >> n;

  vector<vector<s32>> hss(H, vector<s32>(W, 0));
  vector<queue<pair<s32, s32>>> qs(3001);
  for (size_t i = 0; i < n; ++i) {
    s64 x, y, h;
    cin >> x >> y >> h;
    qs[h].push(make_pair(y, x));
    hss[y][x] = h;
  }

  const pair<s64, s64> dxys[] = {
      make_pair(-1, -1), make_pair(-1, 0),  make_pair(-1, +1),
      make_pair(0, -1),  make_pair(0, +1),  make_pair(+1, -1),
      make_pair(+1, 0),  make_pair(+1, +1),
  };

  for (s64 h = 3000; h >= 1; --h) {
    while (!qs[h].empty()) {
      auto [x, y] = qs[h].front();
      qs[h].pop();
      if (hss[x][y] > h) continue;
      hss[x][y] = h;
      for (auto [dx, dy] : dxys) {
        auto nx = x + dx;
        auto ny = y + dy;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (hss[nx][ny] >= h - 1) continue;
        hss[nx][ny] = h - 1;
        qs[h - 1].push(make_pair(nx, ny));
      }
    }
  }

  s64 ans = 0;
  for (s64 i = 0; i < H; ++i) {
    for (s64 j = 0; j < W; ++j) {
      ans += hss[i][j];
      assert(hss[i][j] >= 0);
    }
  }

  cout << ans << endl;
}