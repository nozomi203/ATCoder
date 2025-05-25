#include <atcoder/mincostflow.hpp>

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
}