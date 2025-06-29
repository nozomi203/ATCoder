#include <atcoder/segtree>

#include "util/common.h"
int main() {
  s64 t;
  cin >> t;

  vector<vector<s64>> sss(t);
  for (s64 i = 0; i < t; ++i) {
    s64 n;
    cin >> n;
    sss[i].resize(n);
    util::cin(sss[i]);
    sort(sss[i].begin() + 1, sss[i].end() - 1);
  }

  for (const auto& ss : sss) {
    constexpr auto inf = numeric_limits<s64>::max();
    vector<s64> cnts(ss.size(), inf);
    cnts[ss.size() - 1] = 1;
    s64 j = ss.size() - 1;
    for (s64 i = ss.size() - 2; i >= 1; --i) {
      while (j > i && ss[j] > ss[i] * 2) --j;
      if (j > i && cnts[j] != inf) cnts[i] = 1 + cnts[j];
    }
    if (ss[0] * 2 >= ss.back()) cnts[0] = 2;
    for (s64 i = 1; i < ss.size(); ++i) {
      if (ss[0] * 2 >= ss[i] && cnts[i] != inf) {
        cnts[0] = min(cnts[0], 1 + cnts[i]);
      }
    }
    cout << (cnts[0] == inf ? -1 : cnts[0]) << endl;
  }
}