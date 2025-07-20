#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<vector<s64>> mss(h, vector<s64>(w));
  util::cin(mss);

  const auto in_range = [&](s64 i, s64 j) -> bool {
    return 0 <= i && i < h && 0 <= j && j < w;
  };

  const pair<s64, s64> dijs[] = {
      make_pair(0, 1),
      make_pair(0, -1),
      make_pair(1, 0),
      make_pair(-1, 0),
  };

  const auto is_basin = [&](s64 i, s64 j) -> bool {
    const auto m = mss[i][j];
    size_t cnt = 0;
    for (auto [di, dj] : dijs) {
      const s64 ni = i + di;
      const s64 nj = j + dj;
      if (!in_range(ni, nj) || mss[ni][nj] >= m) {
        cnt++;
      }
    }
    return cnt == 4;
  };
}