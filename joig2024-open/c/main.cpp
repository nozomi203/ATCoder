#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> cxs(n);
  util::cin(cxs);
  vector<pair<s64, s64>> xis(n);
  for (s64 i = 0; i < n; ++i) xis[i] = make_pair(cxs[i].second, i);
  sort(xis.begin(), xis.end());
  constexpr auto inf = numeric_limits<s64>::max();
  vector<s64> dr(n, inf), dl(n, inf);
  {
    s64 j = 0;
    for (s64 i = 0; i < n; ++i) {
      while (j < n && cxs[xis[i].second].first == cxs[xis[j].second].first) ++j;
      if (j < n) {
        for (; i < j; ++i) dr[xis[i].second] = xis[j].first - xis[i].first;
        i = j - 1;
      }
    }
  }
  {
    s64 j = n - 1;
    for (s64 i = n - 1; i >= 0; --i) {
      while (j >= 0 && cxs[xis[i].second].first == cxs[xis[j].second].first)
        --j;
      if (j >= 0) {
        for (; i > j; --i) dl[xis[i].second] = xis[i].first - xis[j].first;
        i = j + 1;
      }
    }
  }

  for (s64 i = 0; i < n; ++i) cout << min(dr[i], dl[i]) << endl;
}