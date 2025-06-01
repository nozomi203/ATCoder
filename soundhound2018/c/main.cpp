#include <atcoder/maxflow>

#include "util/common.h"
int main() {
  size_t r, c;
  cin >> r >> c;
  vector<string> ss(r);
  for (size_t i{0}; i < r; ++i) cin >> ss[i];

  atcoder::mf_graph<size_t> mfg(r * c + 2);
  for (size_t i{0}; i < r; ++i) {
    for (size_t j{0}; j < c; ++j) {
      if (ss[i][j] != '.') continue;
      const size_t idx{c * i + j};
      if ((i + j) % 2) {
        mfg.add_edge(idx, r * c + 1, 1);
      } else {
        constexpr pair<size_t, size_t> diffs[] = {
            make_pair(0, 1),
            make_pair(0, -1),
            make_pair(1, 0),
            make_pair(-1, 0),
        };
        for (auto [di, dj] : diffs) {
          auto ni{i + di};
          auto nj{j + dj};
          if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
          if (ss[ni][nj] != '.') continue;
          auto nidx{c * ni + nj};
          mfg.add_edge(idx, nidx, 1);
        }
        mfg.add_edge(r * c, idx, 1);
      }
    }
  }

  size_t cnt{0};
  for (size_t i{0}; i < r; ++i) {
    for (size_t j{0}; j < c; ++j) {
      if (ss[i][j] == '.') ++cnt;
    }
  }

  cout << cnt - mfg.flow(r * c, r * c + 1) << endl;
}