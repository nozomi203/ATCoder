#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<u32, u32>> uvs(m);
  util::cin(uvs);

  u32 ans = numeric_limits<u32>::max();
  const u32 bmax = (1ULL << n);
  for (u32 b = 0; b < bmax; ++b) {
    u32 cnt = 0;
    for (auto [u, v] : uvs) {
      const bool bu = b & (1ULL << (u - 1ULL));
      const bool bv = b & (1ULL << (v - 1ULL));
      if (bu == bv) ++cnt;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}