#include "util/common.h"

int main() {
  s64 h, w, k;
  cin >> h >> w >> k;
  vector<pair<s64, s64>> rcs(k);
  util::cin(rcs);

  constexpr auto inf = numeric_limits<s64>::max();
  vector<vector<s64>> costs(h, vector<s64>(w, inf));
  vector<vector<bool>> opened(h, vector<bool>(w, false));

  const auto get_cost = [&](s64 i, s64 j) -> s64 {
    if (i < 0 || i >= h || j < 0 || j >= w) return inf;
    return costs[i][j];
  };

  queue<tuple<s64, s64, s64>> q;
  queue<pair<s64, s64>> q2;
  for (auto [r, c] : rcs) {
    q.push(make_tuple(r - 1, c - 1, 0));
  }

  const pair<s64, s64> dijs[] = {
      make_pair(0, 1),
      make_pair(0, -1),
      make_pair(1, 0),
      make_pair(-1, 0),
  };

  while (!q.empty() || !q2.empty()) {
    while (!q.empty()) {
      auto [i, j, c] = q.front();
      q.pop();
      if (costs[i][j] != inf) continue;
      costs[i][j] = c;

      for (auto [di, dj] : dijs) {
        auto ni = i + di;
        auto nj = j + dj;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (costs[ni][nj] != inf) continue;
        q2.push(make_pair(ni, nj));
      }
    }
    while (!q2.empty()) {
      auto [i, j] = q2.front();
      q2.pop();
      array<s64, 4> cs;
      cs[0] = get_cost(i - 1, j);
      cs[1] = get_cost(i + 1, j);
      cs[2] = get_cost(i, j - 1);
      cs[3] = get_cost(i, j + 1);
      sort(cs.begin(), cs.end());
      if (cs[1] == inf) continue;
      q.push(make_tuple(i, j, cs[1] + 1));
    }
  }

  s64 ans = 0;
  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      if (costs[i][j] == inf) continue;
      ans += costs[i][j];
    }
  }

  cout << ans << endl;
}