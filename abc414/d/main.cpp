#include <atcoder/dsu>

#include "util/common.h"

/*
 */
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> xs(n);
  util::cin(xs);
  sort(xs.begin(), xs.end());

  vector<tuple<s64, s64, s64>> dlrs(n - 1);
  for (s64 i = 0; i < n - 1; ++i)
    dlrs[i] = make_tuple(xs[i + 1] - xs[i], i, i + 1);

  sort(dlrs.begin(), dlrs.end());

  atcoder::dsu dsu(n);
  for (s64 i = 0; i < n - m; ++i) {
    auto [d, l, r] = dlrs[i];
    dsu.merge(l, r);
  }

  const auto groups = dsu.groups();
  s64 ans = 0;
  for (const auto& group : groups) {
    s64 xmin = numeric_limits<s64>::max();
    s64 xmax = 0;
    for (auto elem : group) {
      xmin = min<s64>(xmin, xs[elem]);
      xmax = max<s64>(xmax, xs[elem]);
    }
    ans += xmax - xmin;
  }

  cout << ans << endl;
}