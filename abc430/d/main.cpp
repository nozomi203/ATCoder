#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> xs(n);
  util::cin(xs);
  map<s64, s64> ds;
  constexpr s64 inf = numeric_limits<s64>::max();
  ds[0] = inf;
  s64 sumd = inf;
  for (auto x : xs) {
    auto it = ds.lower_bound(x);

    {
      auto pit = prev(it);
      auto& [px, pd] = *pit;
      const s64 d = abs(x - px);
      if (d < pd) {
        sumd -= pd;
        sumd += d;
        pd = d;
      }
      ds[x] = d;
    }

    if (it != ds.end()) {
      auto& [nx, nd] = *it;
      const s64 d = abs(x - nx);
      if (d < nd) {
        sumd -= nd;
        sumd += d;
        nd = d;
      }
      ds[x] = min(ds[x], d);
    }

    sumd += ds[x];

    cout << sumd << endl;
  }
}