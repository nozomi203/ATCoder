#include "util/common.h"

/*
華やかさの順にxvsをソートして、i番目以降の要素のみを使ってすべての位置が
 */

int main() {
  s64 n, m, d;
  cin >> n >> m >> d;
  vector<pair<s64, s64>> xvs(n);
  util::cin(xvs);
  sort(xvs.begin(), xvs.end());
  vector<pair<s64, s64>> vis(n);
  for (s64 i = 0; i < n; ++i) {
    vis[i] = make_pair(xvs[i].second, i);
  }
  sort(vis.begin(), vis.end());

  const auto check = [&](s64 idx) -> bool {
    auto [v, i] = vis[idx];
    s64 cnt = 0;
    s64 x = 0;
    for (s64 j = 0; j < n; ++j) {
      if (xvs[j].first >= x && xvs[j].second >= v) {
        x = xvs[j].first + d;
        ++cnt;
      }
    }
    return cnt >= m;
  };

  const auto get = [&]() -> s64 {
    if (!check(0)) return -1;
    if (check(n - 1)) return vis.back().first;

    s64 l = 0, r = n - 1;
    while (r - l > 1) {
      s64 mid = (r + l) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return vis[l].first;
  };

  cout << get() << endl;
}