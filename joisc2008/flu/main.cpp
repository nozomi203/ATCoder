#include "util/common.h"

int main() {
  s64 n, m, d, k;
  cin >> n >> m >> d >> k;
  vector<pair<s64, s64>> xys(n);
  util::cin(xys);
  vector<vector<s64>> idxss(1000, vector<s64>(1000, -1));
  for (s64 i = 0; i < n; ++i) {
    auto [x, y] = xys[i];
    idxss[x][y] = i;
  }

  vector<vector<s64>> g(n);
  for (s64 i = 0; i < n; ++i) {
    auto [x, y] = xys[i];
    for (s64 nx = x - d; nx <= x + d; ++nx) {
      for (s64 ny = y - d; ny <= y + d; ++ny) {
        if (nx < 0 || nx >= 1000 || ny < 0 || ny >= 1000) continue;
        if (nx == x && ny == y) continue;
        if (idxss[nx][ny] < 0) continue;
        s64 dx = nx - x;
        s64 dy = ny - y;
        if (dx * dx + dy * dy <= d * d) {
          g[i].push_back(idxss[nx][ny]);
        }
      }
    }
  }

  vector<s64> ds(n, -1);
  ds[0] = 0;
  queue<s64> q;
  q.push(0);
  while (!q.empty()) {
    auto idx = q.front();
    q.pop();

    if (ds[idx] >= k) continue;

    for (auto nxt : g[idx]) {
      if (ds[nxt] >= 0) continue;
      ds[nxt] = ds[idx] + 1;
      q.push(nxt);
    }
  }

  s64 cnt = 0;
  for (auto d : ds) {
    if (d < 0) continue;
    if (k - d < m) ++cnt;
  }
  cout << cnt << endl;
}