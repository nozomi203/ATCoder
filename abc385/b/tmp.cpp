#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 H, W, X, Y;
  cin >> H >> W >> X >> Y;
  vector<vector<char>> field(H + 1, vector<char>(W + 1));
  for (s64 h = 1; h <= H; ++h) {
    for (s64 w = 1; w <= W; ++w) {
      cin >> field[h][w];
    }
  }
  string T;
  cin >> T;

  const auto try_move = [&](s64 dx, s64 dy) -> bool {
    s64 x_next = X + dx;
    s64 y_next = Y + dy;
    if (1 <= x_next && x_next <= H && 1 <= y_next && y_next <= W &&
        field[x_next][y_next] != '#') {
      X = x_next;
      Y = y_next;
      return true;
    }
    return false;
  };
  s64 count{0};
  for (char c : T) {
    bool move{true};
    switch (c) {
      case 'U':
        move = try_move(-1, 0);
        break;
      case 'D':
        move = try_move(1, 0);
        break;
      case 'L':
        move = try_move(0, -1);
        break;
      case 'R':
        move = try_move(0, 1);
        break;
      default:
        move = false;
        break;
    }
    if (move) {
      if (field[X][Y] == '@') {
        field[X][Y] = '.';
        ++count;
      }
    }
  }

  cout << X << " " << Y << " " << count << endl;
}
