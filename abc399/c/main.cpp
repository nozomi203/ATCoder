#include <atcoder/dsu>

#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;

  s64 ans{0};

  atcoder::dsu dsu(n + 1);
  for (s64 i{0}; i < m; ++i) {
    s64 u, v;
    cin >> u >> v;
    if (dsu.leader(u) == dsu.leader(v)) {
      ++ans;
    } else {
      dsu.merge(u, v);
    }
  }

  cout << ans << endl;
}