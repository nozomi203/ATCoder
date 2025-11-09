#include "util/common.h"

/*

左上下右
 0 1 2 3


 頂点倍化。
 各セルを方向によって倍化。
 さらに、
*/

int main() {
  s64 t;
  cin >> t;

  vector<s64> answers;

  const auto solve = [&answers]() {
    s64 h, w;
    cin >> h >> w;
    vector<string> ss(h);
    util::cin(ss);

    map<char, vector<s64>> m;
    m['A'] = {0, 1, 2, 3};
    m['B'] = {1, 0, 3, 2};
    m['C'] = {2, 3, 0, 1};

    const array<s64, 4> banned = {3, 2, 1, 0};

    const array<pair<s64, s64>, 4> diffs = {
        make_pair(0, 1),
        make_pair(1, 0),
        make_pair(-1, 0),
        make_pair(0, -1),
    };

    using key = tuple<s64, s64, s64, s64>;
    map<key, vector<pair<s64, key>>> g;
    for (s64 i = 0; i < h; ++i) {
      for (s64 j = 0; j < w; ++j) {
        for (s64 k = 0; k < 4; ++k) {
          for (s64 l = 0; l < 4; ++l) {
            if (l == banned[k]) continue;

            auto kc0 = make_tuple(i, j, k, 0);
            auto kc1 = make_tuple(i, j, k, 1);
            auto [dh, dw] = diffs[l];
            if (l == m[ss[i][j]][k]) {
              auto kn = make_tuple(i + dh, j + dw, l, 0);
              g[kc0].push_back(make_pair(0, kn));
              g[kc1].push_back(make_pair(1, kn));
            } else {
              auto kn = make_tuple(i + dh, j + dw, l, 1);
              g[kc0].push_back(make_pair(1, kn));
            }
          }
        }
      }
    }

    using elem = pair<s64, key>;
    priority_queue<elem, vector<elem>, greater<elem>> pq;
    pq.push(make_pair(0, make_tuple(0, 0, 0, 0)));
    map<key, s64> ds;
    ds[make_tuple(0, 0, 0, 0)] = 0;
    while (!pq.empty()) {
      auto [d, k] = pq.top();
      pq.pop();
      if (ds.count(k) != 0 && ds[k] < d) continue;
      ds[k] = d;
      for (auto [nd, nk] : g[k]) {
        if (ds.count(nk) != 0 && ds[nk] <= d + nd) continue;
        ds[nk] = d + nd;
        pq.push(make_pair(d + nd, nk));
      }
    }

    s64 ans = numeric_limits<s64>::max();
    const auto k0 = make_tuple(h - 1, w - 1, 0, 0);
    const auto k1 = make_tuple(h - 1, w - 1, 0, 1);
    if (ds.count(k0)) ans = min(ans, ds[k0]);
    if (ds.count(k1)) ans = min(ans, ds[k1]);
    answers.push_back(ans);
  };

  for (s64 i = 0; i < t; ++i) {
    solve();
  }

  for (auto ans : answers) cout << ans << endl;
}