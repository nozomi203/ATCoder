#include "util/cartesian_tree.h"
#include "util/common.h"

int main() {
  s64 n, m, k;
  cin >> n >> m >> k;
  vector<string> ss(n);
  util::cin(ss);

  vector<s64> cnts(m);
  for (s64 i = 0; i < n; ++i) {
    for (s64 j = 0; j < m; ++j) {
      cnts[j] = ss[i][j] == '#' ? 0 : cnts[j] + 1;
    }
    util::cartesian_tree<s64, [](s64 l, s64 r) -> bool { return l < r; }> ct(
        cnts);
  }
}