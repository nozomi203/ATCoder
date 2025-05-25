#include <atcoder/maxflow.hpp>

#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<vector<s64>> a(h, vector<s64>(w));
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      cin >> a[i][j];
    }
  }
  s64 cnt{0};
  pair<s64, s64> s, t;
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      if (a[i][j] == 'o')
        ++cnt;
      else if (a[i][j] == 'S')
        s = {i, j};
      else if (a[i][j] == 'T')
        t = {i, j};
    }
  }

  atcoder::mf_graph<s64> mfg()
}