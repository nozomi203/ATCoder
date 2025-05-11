#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (s64 i{0}; i < h; ++i) {
    cin >> s[i];
  }
  using pos = pair<s64, s64>;
  vector<vector<pos>> d(
      h, vector<pos>(w, make_pair(numeric_limits<s64>::max(), -1)));

  const tuple<s64, s64, char> dxys[] = {
      make_tuple(-1, 0, 'v'),
      make_tuple(1, 0, '^'),
      make_tuple(0, -1, '>'),
      make_tuple(0, 1, '<'),
  };

  const auto check = [&](s64 x, s64 y) -> bool {
    if (x < 0 || x >= h || y < 0 || y >= w) return false;
    if (s[x][y] != '.') return false;
    return true;
  };

  queue<pos> q;
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      if (s[i][j] == 'E') {
        for (auto [dx, dy, c] : dxys) {
          const auto nx{i + dx}, ny{j + dy};
          if (!check(nx, ny)) continue;
          s[nx][ny] = c;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto [dx, dy, c] : dxys) {
      const auto nx{x + dx}, ny{y + dy};
      if (!check(nx, ny)) continue;
      s[nx][ny] = c;
      q.push(make_pair(nx, ny));
    }
  }

  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      cout << s[i][j];
    }
    cout << endl;
  }
}