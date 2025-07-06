#include <atcoder/dsu>

#include "util/common.h"
int main() {
  s64 h, w, k;
  cin >> h >> w >> k;
  vector<pair<s64, s64>> rcs(k);
  util::cin(rcs);

  const pair<s64, s64> drcs[] = {
      make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, -1),
      make_pair(0, 1),   make_pair(1, -1), make_pair(1, 0),  make_pair(1, 1),
  };

  map<pair<s64, s64>, s64> m;
  atcoder::dsu uf(
      k + 4);  // 4 additional virtual cells that represents each side of grid
  for (s64 i = 0; i < k; ++i) {
    m[rcs[i]] = i;
  }

  for (s64 i = 0; i < k; ++i) {
    auto [r, c] = rcs[i];
    if (r == 1) uf.merge(i, k);
    if (r == h) uf.merge(i, k + 1);
    if (c == 1) uf.merge(i, k + 2);
    if (c == w) uf.merge(i, k + 3);
    for (auto [dr, dc] : drcs) {
      auto nr = r + dr;
      auto nc = c + dc;
      if (nr <= 0 || nr > h || nc <= 0 || nc > w) continue;
      if (auto it = m.find(make_pair(nr, nc)); it != m.end()) {
        uf.merge(i, it->second);
      }
    }
  }

  cout << (uf.same(k, k + 1) || uf.same(k, k + 2) || uf.same(k + 1, k + 3) ||
                   uf.same(k + 2, k + 3)
               ? "No"
               : "Yes")
       << endl;
}