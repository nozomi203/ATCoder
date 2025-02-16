#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  u32 N, M;
  cin >> N >> M;

  struct pos {
    u32 x{0};
    u32 y{0};
    char c{0};
  };
  vector<pos> positions(M, pos{});
  for (u32 i = 0; i < M; ++i) {
    cin >> positions[i].x;
    cin >> positions[i].y;
    cin >> positions[i].c;
  }

  const auto check_x = [&]() -> bool {
    // sort positions in ascendant order of x. white comes first if x is same.
    std::sort(positions.begin(), positions.end(),
              [](const pos& l, const pos& r) -> bool {
                if (l.x == r.x) {
                  return l.c == 'W' || r.c == 'B';
                }
                return l.x < r.x;
              });

    u32 minwy{numeric_limits<u32>::max()};
    for (const auto& pos : positions) {
      if (pos.c == 'W') {
        minwy = min(minwy, pos.y);
      } else {
        if (pos.y >= minwy) {
          return false;
        }
      }
    }

    return true;
  };

  const auto check_y = [&]() -> bool {
    // sort positions in ascendant order of y. white comes first if y is same.
    std::sort(positions.begin(), positions.end(),
              [](const pos& l, const pos& r) -> bool {
                if (l.y == r.y) {
                  return l.c == 'W' || r.c == 'B';
                }
                return l.y < r.y;
              });

    u32 minwx{numeric_limits<u32>::max()};
    for (const auto& pos : positions) {
      if (pos.c == 'W') {
        minwx = min(minwx, pos.x);
      } else {
        if (pos.x >= minwx) {
          return false;
        }
      }
    }
    return true;
  };

  cout << (check_x() && check_y() ? "Yes" : "No") << endl;
}
