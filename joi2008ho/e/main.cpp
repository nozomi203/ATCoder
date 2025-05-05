#include "util/common.h"

int main() {
  s64 w, h;
  cin >> w >> h;
  s64 n;
  cin >> n;
  vector<tuple<s64, s64, s64, s64>> xys(n);
  for (s64 i{0}; i < n; ++i) cin_tuple(xys[i]);
  map<s64, s64> cmpx, cmpy;
  for (auto [x1, y1, x2, y2] : xys) {
    cmpx.try_emplace(x1, 0);
    if (x2 < w) cmpx.try_emplace(x2, 0);
    cmpy.try_emplace(y1, 0);
    if (y2 < h) cmpy.try_emplace(y2, 0);
  }
  cmpx.try_emplace(0, 0);
  cmpx.try_emplace(w - 1, 0);
  cmpy.try_emplace(0, 0);
  cmpy.try_emplace(h - 1, 0);
  {
    s64 idx{0};
    for (auto& [k, v] : cmpx) v = idx++;
    idx = 0;
    for (auto& [k, v] : cmpy) v = idx++;
  }
  vector<vector<s64>> cnts(cmpx.size(), vector<s64>(cmpy.size()));
  for (auto [x1, y1, x2, y2] : xys) {
    auto cmpx1{cmpx.at(x1)}, cmpy1{cmpy.at(y1)},
        cmpx2{x2 < w ? cmpx.at(x2) : -1}, cmpy2{y2 < h ? cmpy.at(y2) : -1};
    ++cnts[cmpx1][cmpy1];
    if (cmpy2 >= 0) --cnts[cmpx1][cmpy2];
    if (cmpx2 >= 0) --cnts[cmpx2][cmpy1];
    if (cmpx2 >= 0 && cmpy2 >= 0) ++cnts[cmpx2][cmpy2];
  }

  for (s64 x{0}; x < cmpx.size(); ++x) {
    for (s64 y{0}; y < cmpy.size() - 1; ++y) {
      cnts[x][y + 1] += cnts[x][y];
    }
  }
  for (s64 y{0}; y < cmpy.size(); ++y) {
    for (s64 x{0}; x < cmpx.size() - 1; ++x) {
      cnts[x + 1][y] += cnts[x][y];
    }
  }

  s64 ans{0};
  vector<vector<s64>> g(cmpx.size(), vector<s64>(cmpy.size()));
  for (s64 x{0}; x < cmpx.size(); ++x) {
    for (s64 y{0}; y < cmpy.size(); ++y) {
      if (cnts[x][y]) continue;
      if (g[x][y]) continue;
      ++ans;
      queue<pair<s64, s64>> q;
      q.push(make_pair(x, y));
      while (!q.empty()) {
        auto [curx, cury] = q.front();
        q.pop();
        g[curx][cury] = ans;
        const pair<s64, s64> diffs[] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
        };
        for (auto [dx, dy] : diffs) {
          auto nxtx{curx + dx}, nxty{cury + dy};
          if (nxtx < 0 || nxtx >= cmpx.size() || nxty < 0 ||
              nxty >= cmpy.size())
            continue;
          if (cnts[nxtx][nxty] > 0) continue;
          if (g[nxtx][nxty] > 0) continue;
          q.push(make_pair(nxtx, nxty));
        }
      }
    }
  }

  cout << ans << endl;
}