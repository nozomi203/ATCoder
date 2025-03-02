#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
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
    u32 x;
    u32 y;
    u32 c;
  };
  vector<pos> positions(M);
  for (u32 i = 0; i < M; ++i) {
    s64 x, y;
    char c;
    cin >> x >> y >> c;
    positions[i].x = x;
    positions[i].y = y;
    positions[i].c = c == 'W' ? 0 : 1;
  }

  const auto check_x = [](vector<pos> positions) -> bool {
    // sort positions in ascendant order of x. white comes first if x is same.
    std::sort(positions.begin(), positions.end(),
              [](const pos& l, const pos& r) -> bool {
                if (l.x == r.x) {
                  return l.c < r.c;
                }
                return l.x < r.x;
              });

    u32 minwy{numeric_limits<u32>::max()};
    for (const auto& p : positions) {
      if (p.c == 0) {
        minwy = min<u32>(minwy, p.y);
      } else {
        if (p.y >= minwy) {
          return false;
        }
      }
    }
    return true;
  };

  const auto check_y = [](vector<pos> positions) -> bool {
    // sort positions in ascendant order of y. white comes first if y is same.
    std::sort(positions.begin(), positions.end(),
              [](const pos& l, const pos& r) -> bool {
                if (l.y == r.y) {
                  return l.c < r.c;
                }
                return l.y < r.y;
              });

    u32 minwx{numeric_limits<u32>::max()};
    for (const auto& p : positions) {
      if (p.c == 0) {
        minwx = min<u32>(minwx, p.x);
      } else {
        if (p.x >= minwx) {
          return false;
        }
      }
    }
    return true;
  };

  cout << ((check_x(positions) && check_y(positions)) ? "Yes" : "No") << endl;
}
