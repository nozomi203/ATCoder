#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

enum Dir { Dir_Horizontal, Dir_Vertical, Dir_Term };
constexpr s64 kInf = numeric_limits<s64>::max();
struct Grid {
  char c;
};
using FieldRow = vector<Grid>;
using Field = vector<FieldRow>;
using Pos = pair<s64, s64>;

s64 solve(const Pos& s, const Pos& g, const Field& f, s64 offset) {
  vector<vector<s64>> steps(f.size(), vector<s64>(f[0].size(), kInf));
  queue<Pos> works;
  works.push(s);
  steps[s.first][s.second] = 0;

  while (!works.empty()) {
    auto [h, w] = works.front();
    works.pop();
    auto& grid = f[h][w];

    constexpr auto diffs = to_array({to_array({Pos{-1, 0}, Pos{+1, 0}}),
                                     to_array({Pos{0, -1}, Pos{0, +1}})});
    for (const auto& diff : diffs[(h + w + offset) % 2]) {
      const auto h_next = h + diff.first;
      const auto w_next = w + diff.second;
      if (0 <= h_next && h_next < f.size() && 0 <= w_next &&
          w_next < f[0].size() && f[h_next][w_next].c != '#' &&
          steps[h_next][w_next] == kInf) {
        steps[h_next][w_next] = steps[h][w] + 1;
        works.push({h_next, w_next});
      }
    }
  }

  return steps[g.first][g.second];
}

int main() {
  s64 H, W;
  cin >> H >> W;
  Field f(H, FieldRow(W));
  Pos s, g;
  for (s64 i = 0; i < H; ++i) {
    string S;
    cin >> S;
    for (s64 j = 0; j < W; ++j) {
      f[i][j].c = S[j];
      if (S[j] == 'S') {
        s = {i, j};
      }
      if (S[j] == 'G') {
        g = {i, j};
      }
    }
  }

  const s64 min_step = min(solve(s, g, f, 0), solve(s, g, f, 1));

  cout << (min_step < kInf ? min_step : -1) << endl;
}
