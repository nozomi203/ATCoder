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

  vector<vector<set<pair<s64, s64>>>> dsts(h, vector<set<pair<s64, s64>>>(w));
  const auto get_dsts = [&](const auto& self, s64 i,
                            s64 j) -> const set<pair<s64, s64>>& {
    if (dsts[i][j].empty()) {
      if (is_basin(i, j)) {
        dsts[i][j].emplace(make_pair(i, j));
      } else {
        for (auto [di, dj] : dijs) {
          const s64 ni = i + di;
          const s64 nj = j + dj;
          if (in_range(ni, nj) && mss[ni][nj] < mss[i][j]) {
            const auto& sub_dsts = self(self, ni, nj);
            for (auto sub_dst : sub_dsts) {
              if (dsts[i][j].size() > 1) break;
              dsts[i][j].insert(sub_dst);
            }
          }
        }
      }
    }
    return dsts[i][j];
  };

  size_t cnt = 0;
  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      if (get_dsts(get_dsts, i, j).size() > 1) {
        ++cnt;
      }
    }
  }
  cout << cnt << endl;
}