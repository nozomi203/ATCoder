#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 H, W, X, P, Q;
  cin >> H >> W >> X >> P >> Q;
  struct Cell {
    s64 value;
    bool open{false};
  };
  vector<vector<Cell>> cells(H + 1, vector<Cell>(W + 1));
  for (s64 h = 1; h <= H; ++h) {
    for (s64 w = 1; w <= W; ++w) {
      cin >> cells[h][w].value;
    }
  }
  constexpr pair<s64, s64> kDiffs[] = {
      {0, 1},
      {0, -1},
      {1, 0},
      {-1, 0},
  };

  cells[P][Q].open = true;
  s64 power{cells[P][Q].value};
  using Target = tuple<s64, s64, s64>;
  priority_queue<Target, vector<Target>, greater<Target>> targets;
  for (const auto& diff : kDiffs) {
    s64 h = P + diff.first;
    s64 w = Q + diff.second;
    if (1 <= h && h <= H && 1 <= w && w <= W && !cells[h][w].open) {
      targets.push({cells[h][w].value, h, w});
      cells[h][w].open = true;
    }
  }
  while (!targets.empty()) {
    auto [targetPower, targetH, targetW] = targets.top();
    targets.pop();

    if (targetPower >= power / (double)X) {
      break;
    }

    power += targetPower;

    for (const auto& diff : kDiffs) {
      s64 h = targetH + diff.first;
      s64 w = targetW + diff.second;
      if (1 <= h && h <= H && 1 <= w && w <= W && !cells[h][w].open) {
        targets.push({cells[h][w].value, h, w});
        cells[h][w].open = true;
      }
    }
  }

  cout << power << endl;
}
