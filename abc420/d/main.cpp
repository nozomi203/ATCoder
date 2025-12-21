#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<string> ass(h);
  util::cin(ass);

  const auto get_idx = [&](s64 i, s64 j, bool flip) -> s64 {
    return w * i + j + (flip ? h * w : 0);
  };

  const pair<s64, s64> dijs[] = {
      pair<s64, s64>(0, 1),
      pair<s64, s64>(0, -1),
      pair<s64, s64>(1, 0),
      pair<s64, s64>(-1, 0),
  };

  const s64 total = h * w * 2;

  vector<vector<s64>> g(total);

  pair<s64, s64> sij, gij;
  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      const char a = ass[i][j];
      if (a == 'S') {
        ass[i][j] = '.';
        sij = make_pair(i, j);
      } else if (a == 'G') {
        ass[i][j] = '.';
        gij = make_pair(i, j);
      }
    }
  }

  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      const char a = ass[i][j];
      switch (a) {
        case '.':
        case 'o':
        case 'x':
        case '?':
          for (auto [di, dj] : dijs) {
            auto ni = i + di;
            auto nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (ass[ni][nj] == '#') continue;
            if (ass[ni][nj] == '?') {
              g[get_idx(i, j, false)].push_back(get_idx(ni, nj, true));
              g[get_idx(i, j, true)].push_back(get_idx(ni, nj, false));
            } else {
              if (ass[ni][nj] != 'x') {
                g[get_idx(i, j, false)].push_back(get_idx(ni, nj, false));
              }
              if (ass[ni][nj] != 'o') {
                g[get_idx(i, j, true)].push_back(get_idx(ni, nj, true));
              }
            }
          }
          break;
        case '#':
          break;
        default:
          assert(false);
          break;
      }
    }
  }

  constexpr s64 inf = numeric_limits<s64>::max();
  vector<s64> nums(total, inf);
  queue<s64> q;
  q.push(get_idx(sij.first, sij.second, false));
  nums[q.front()] = 0;
  while (!q.empty()) {
    const s64 idx = q.front();
    q.pop();
    for (auto nxt : g[idx]) {
      if (nums[nxt] != inf) continue;
      nums[nxt] = nums[idx] + 1;
      q.push(nxt);
    }
  }

  const auto get_ans = [&]() -> s64 {
    const s64 gidx0 = get_idx(gij.first, gij.second, false);
    const s64 gidx1 = get_idx(gij.first, gij.second, true);

    const s64 ret = min(nums[gidx0], nums[gidx1]);
    return ret == inf ? -1 : ret;
  };
  cout << get_ans() << endl;
}