#include "util/common.h"

int main() {
  s64 h, w, n;
  cin >> h >> w >> n;
  vector<vector<char>> f(h, vector<char>(w));
  vector<pair<s64, s64>> gs(n + 1);
  for (s64 i{0}; i < h; ++i) {
    string str;
    cin >> str;
    for (s64 j{0}; j < w; ++j) {
      f[i][j] = str[j];
      if (str[j] == 'S') gs[0] = make_pair(i, j);
      if ('1' <= str[j] && str[j] <= '9') {
        gs[str[j] - '0'] = make_pair(i, j);
      }
    }
  }

  s64 ans{0};
  for (s64 i{0}; i < gs.size() - 1; ++i) {
    vector<vector<s64>> dists(h, vector<s64>(w, numeric_limits<s64>::max()));
    auto s{gs[i]}, g(gs[i + 1]);
    dists[s.first][s.second] = 0;
    queue<pair<s64, s64>> q;
    q.push(s);
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
        auto nxt_x(x + dx), nxt_y(y + dy);
        if (nxt_x < 0 || nxt_x >= h || nxt_y < 0 || nxt_y >= w) continue;
        if (f[nxt_x][nxt_y] == 'X') continue;
        if (dists[nxt_x][nxt_y] <= dists[x][y] + 1) continue;
        dists[nxt_x][nxt_y] = dists[x][y] + 1;
        q.push(make_pair(nxt_x, nxt_y));
      }
    }

    ans += dists[g.first][g.second];
  }

  cout << ans << endl;
}