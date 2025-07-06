#include "util/common.h"
#include "util/topological_sort.h"
int main() {
  s64 n, x;
  cin >> n >> x;
  vector<s64> as(n + 1), ps(n + 1);
  util::cin(as.begin() + 1, as.end());
  util::cin(ps.begin() + 1, ps.end());

  vector<vector<size_t>> g(n + 1);
  for (s64 i = 1; i <= n; ++i) {
    if (ps[i] < 0) continue;
    g[ps[i]].push_back(i);
  }

  auto [success, v] = util::topological_sort(g);

  constexpr auto inf = numeric_limits<s64>::max();
  vector<s64> sump(n + 1, inf);
  for (auto i : v) {
    if (ps[i] < 0) {
      sump[i] = as[i];
    } else {
      if (sump[ps[i]] != inf) {
        sump[i] = sump[ps[i]] + as[i];
      }
    }
  }

  for (s64 i = n; i >= 1; --i) {
    if (sump[i] <= x) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}