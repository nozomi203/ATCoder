#include "util/common.h"

/*
9 7
07
16
25
34
...
97
106
125

mで割った余りがrとなる数を調べていく
→どこまで調べればいいのか
*/

int main() {
  size_t m, r;
  cin >> m >> r;

  constexpr size_t h = 4;
  constexpr size_t w = 3;

  constexpr size_t inf = numeric_limits<size_t>::max();
  array<array<size_t, w>, h> digits;
  digits[0][0] = 0;
  digits[0][1] = inf;
  digits[0][2] = inf;
  digits[1][0] = 1;
  digits[1][1] = 2;
  digits[1][2] = 3;
  digits[2][0] = 4;
  digits[2][1] = 5;
  digits[2][2] = 6;
  digits[3][0] = 7;
  digits[3][1] = 8;
  digits[3][2] = 9;

  vector<vector<vector<size_t>>> dp(
      h, vector<vector<size_t>>(w, vector<size_t>(m, inf)));

  dp[0][0][0] = 0;

  using elem_t = tuple<s64, s64, size_t>;
  queue<elem_t> q;
  q.push(make_tuple(0, 0, 0));

  const pair<s64, s64> dxys[] = {
      make_pair(0, 1),
      make_pair(0, -1),
      make_pair(1, 0),
      make_pair(-1, 0),
  };

  while (!q.empty()) {
    const auto [cx, cy, cr] = q.front();
    q.pop();

    {
      const auto nr = (cr * 10 + digits[cx][cy]) % m;
      if (dp[cx][cy][nr] > dp[cx][cy][cr] + 1) {
        dp[cx][cy][nr] = dp[cx][cy][cr] + 1;
        q.push(make_tuple(cx, cy, nr));
      }
    }

    for (auto [dx, dy] : dxys) {
      const auto nx = cx + dx;
      const auto ny = cy + dy;
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (digits[nx][ny] == inf) continue;
      if (dp[nx][ny][cr] > dp[cx][cy][cr] + 1) {
        dp[nx][ny][cr] = dp[cx][cy][cr] + 1;
        q.push(make_tuple(nx, ny, cr));
      }
      const size_t nr = (cr * 10 + digits[nx][ny]) % m;
      if (dp[nx][ny][nr] > dp[cx][cy][cr] + 2) {
        dp[nx][ny][nr] = dp[cx][cy][cr] + 2;
        q.push(make_tuple(nx, ny, nr));
      }
    }
  }

  size_t ans = inf;
  for (size_t i = 0; i < h; ++i) {
    for (size_t j = 0; j < w; ++j) {
      ans = min(ans, dp[i][j][r]);
    }
  }
  cout << ans << endl;
}