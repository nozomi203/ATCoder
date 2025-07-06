#include "util/common.h"

/*
最小距離=min(全部徒歩,一番近いゴールと同じ色の魔法陣まで行ってワープ)
*/

int main() {
  s64 n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<pair<s64, s64>> xys(q);
  util::cin(xys);

  for (auto [x, y] : xys) {
    --x;
    --y;
    if (x > y) swap(x, y);
    const s64 diff = y - x;
    s64 dist = min(diff, n - diff);
    if (s[x] == s[y]) {
      dist = 1;
    } else {
      s64 step = 0;
      // move to another color
      if (s[(x + 1) % n] == s[x] && s[(x - 1 + n) % n] == s[x]) {
        // if both neighbors are same color, it takes 2 steps
        step += 2;
        // warp to y from b
        if (s[(y + 1) % n] == s[y] && s[(y - 1 + n) % n] == s[y]) ++step;
      } else {
        // if one or more neighbors are different color, it takes 1 step
        step += 1;
        // it takes 1 more step to warp to y
        step += 1;
      }
      dist = min(dist, step);
    }

    cout << dist << endl;
  }
}