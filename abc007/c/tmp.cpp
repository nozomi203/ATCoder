#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s32 R, C;
  cin >> R >> C;
  using pos = pair<s32, s32>;
  pos s, g;
  cin >> s.first >> s.second;
  cin >> g.first >> g.second;
  struct cell {
    char c;
    bool open;
  };
  vector<vector<cell>> cells(R + 1, vector<cell>(C + 1));
  for (size_t i = 1; i <= R; ++i) {
    string s;
    cin >> s;
    for (size_t j = 1; j <= C; ++j) {
      cells[i][j].c = s[j - 1];
      cells[i][j].open = false;
    }
  }

  struct work {
    pos p;
    size_t dist;
  };
  queue<work> q;
  q.push(work{s, 0});
  while (!q.empty()) {
    work w = q.front();
    q.pop();

    if (w.p.first == g.first && w.p.second == g.second) {
      cout << w.dist << endl;
      break;
    }

    const pair<s32, s32> diffs[] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    for (auto [dy, dx] : diffs) {
      auto y = w.p.first + dy;
      auto x = w.p.second + dx;
      if (y <= 0 || y > R || x <= 0 || x > C) continue;
      if (cells[y][x].c == '#' || cells[y][x].open) continue;
      cells[y][x].open = true;
      q.push(work{pos{y, x}, w.dist + 1});
    }
  }
}
