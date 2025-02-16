#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 H, W, D;
  cin >> H >> W >> D;
  struct Cell {
    char c;
    s64 d_min{numeric_limits<s64>::max()};
  };
  vector<vector<Cell>> cells(H, vector<Cell>(W));
  struct Work {
    s64 h;
    s64 w;
    s64 d;
    bool open;
  };
  queue<Work> works;
  for (s64 i = 0; i < H; ++i) {
    string str;
    cin >> str;
    for (s64 j = 0; j < W; ++j) {
      cells[i][j].c = str[j];
      if (str[j] == 'H') works.push(Work{i, j, 0, false});
    }
  }
  while (!works.empty()) {
    Work& work = works.front();
    if (work.open) {
      works.pop();
      continue;
    }

    work.open = true;
    if (cells[work.h][work.w].d_min <= work.d) continue;
    cells[work.h][work.w].d_min = work.d;
    if (work.d == D) continue;

    constexpr auto diffs = to_array({
        make_pair<s64, s64>(0, 1),
        make_pair<s64, s64>(0, -1),
        make_pair<s64, s64>(1, 0),
        make_pair<s64, s64>(-1, 0),
    });
    for (const auto& [dh, dw] : diffs) {
      s64 h = work.h + dh;
      s64 w = work.w + dw;
      if (h < 0 || h >= H || w < 0 || w >= W) continue;
      if (cells[h][w].c == 'H') continue;
      if (cells[h][w].c == '#') continue;
      works.push(Work{h, w, work.d + 1, false});
    }
  }

  s64 ans{0};
  for (s64 i = 0; i < H; ++i) {
    for (s64 j = 0; j < W; ++j) {
      if (cells[i][j].d_min <= D) ++ans;
    }
  }
  cout << ans << endl;
}
