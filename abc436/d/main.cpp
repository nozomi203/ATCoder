#include "util/common.h"

int main() {
  s32 h, w;
  cin >> h >> w;
  vector<string> ss(h);
  util::cin(ss);

  const pair<s32, s32> diffs[] = {
      make_pair(0, 1),
      make_pair(0, -1),
      make_pair(1, 0),
      make_pair(-1, 0),
  };

  const auto to_idx = [&](s32 i, s32 j) -> s32 { return i * w + j; };

  const auto to_idx2 = [&](char c) -> s32 { return h * w + c - 'a'; };

  const s64 total = 26 + h * w;

  vector<vector<pair<s32, s32>>> g(total);
  for (s32 i = 0; i < h; ++i) {
    for (s32 j = 0; j < w; ++j) {
      if (ss[i][j] == '#') continue;

      for (auto [dx, dy] : diffs) {
        s32 ni = i + dx;
        s32 nj = j + dy;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (ss[ni][nj] == '#') continue;
        g[to_idx(i, j)].push_back(make_pair(to_idx(ni, nj), 1));
      }

      if (ss[i][j] >= 'a' && ss[i][j] <= 'z') {
        g[to_idx(i, j)].push_back(make_pair(to_idx2(ss[i][j]), 0));
        g[to_idx2(ss[i][j])].push_back(make_pair(to_idx(i, j), 1));
      }
    }
  }

  vector<s32> ds(total, -1);
  ds[0] = 0;
  deque<s64> q;
  q.push_front(0);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop_front();

    s32 d = ds[cur];

    for (auto [nxt, w] : g[cur]) {
      if (ds[nxt] != -1) continue;
      ds[nxt] = d + w;
      if (w == 0) {
        q.push_front(nxt);
      } else {
        q.push_back(nxt);
      }
    }
  }

  cout << ds[to_idx(h - 1, w - 1)] << endl;
}