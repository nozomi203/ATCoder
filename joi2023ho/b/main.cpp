#include "util/common.h"

/*
1番影響力の大きい人には献本しないと買ってもらえない。
*/

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xes(n);
  util::cin(xes);

  vector<pair<s64, s64>> xis(n), eis(n);
  for (s64 i = 0; i < n; ++i) {
    auto [x, e] = xes[i];
    xis[i] = make_pair(x, i);
    eis[i] = make_pair(e, i);
  }
  sort(xis.begin(), xis.end(), less());
  sort(eis.begin(), eis.end(), greater());

  vector<s64> idxs(n);
  for (s64 i = 0; i < n; ++i) idxs[xis[i].second] = i;

  s64 cnt = 0;
  vector<bool> bs(n, false);
  for (auto [e, i] : eis) {
    if (bs[i]) continue;
    ++cnt;
    const auto idx = idxs[i];
    const auto [x, i2] = xis[idx];
    assert(i == i2);
    for (s64 j = idx; j < n; ++j) {
      const auto [x2, i3] = xis[j];
      if (abs(x - x2) > e - xes[i3].second) break;
      bs[i3] = true;
    }
    for (s64 j = idx - 1; j >= 0; --j) {
      const auto [x2, i3] = xis[j];
      if (abs(x - x2) > e - xes[i3].second) break;
      bs[i3] = true;
    }
  }

  cout << cnt << endl;
}