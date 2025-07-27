#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<vector<s64>> as(h, vector<s64>(w));
  util::cin(as);

  const pair<s64, s64> dxys[] = {
      make_pair(0, -1),
      make_pair(0, 1),
      make_pair(-1, 0),
      make_pair(1, 0),
  };
  vector<vector<s64>> groups(h, vector<s64>(w, -1));
  vector<s64> cols;
  vector<s64> cnts;
  s64 group = 0;
  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      if (groups[i][j] >= 0) continue;
      queue<pair<s64, s64>> q;
      q.push(make_pair(i, j));
      groups[i][j] = group;
      s64 cnt = 1;
      while (!q.empty()) {
        const auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dxys) {
          const auto nx = x + dx;
          const auto ny = y + dy;
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if (groups[nx][ny] >= 0) continue;
          if (as[nx][ny] != as[i][j]) continue;
          groups[nx][ny] = group;
          ++cnt;
          q.push(make_pair(nx, ny));
        }
      }
      cols.push_back(as[i][j]);
      cnts.push_back(cnt);
      ++group;
    }
  }

  vector<set<s64>> graph(group);
  for (s64 x = 0; x < h; ++x) {
    for (s64 y = 0; y < w; ++y) {
      for (auto [dx, dy] : dxys) {
        const auto nx = x + dx;
        const auto ny = y + dy;
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (groups[nx][ny] != groups[x][y])
          graph[groups[x][y]].emplace(groups[nx][ny]);
      }
    }
  }

  s64 ans = 0;
  for (s64 i = 0; i < group; ++i) {
    map<s64, s64> acnts;
    for (auto nxt : graph[i]) {
      acnts[cols[nxt]] += cnts[nxt];
    }

    s64 acntmax = 0;
    for (auto [col, acnt] : acnts) acntmax = max(acntmax, acnt);
    ans = max(ans, acntmax + cnts[i]);
  }

  cout << ans << endl;
}