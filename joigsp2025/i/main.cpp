#include "util/common.h"

/*
 */

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> bas(n), dcs(m);
  for (auto& [b, a] : bas) cin >> a;
  for (auto& [b, a] : bas) cin >> b;
  for (auto& [d, c] : dcs) cin >> c;
  for (auto& [d, c] : dcs) cin >> d;

  sort(bas.begin(), bas.end(), greater());
  sort(dcs.begin(), dcs.end(), greater());

  vector<queue<s64>> mp(n + 1);
  for (auto [b, a] : bas) mp[a].push(b);

  const auto get_score = [](const tuple<s64, s64, s64, s64>& t) -> {
    const auto& [d, c, b, a] = t;
    return b + (c == a ? d : 0);
  };

  vector<tuple<s64, s64, s64, s64>> sels;
  for (auto [d, c] : dcs) {
    if (mp[c].empty()) {
      sels.push_back(make_tuple(d, c, 0, -1));
    } else {
      sels.push_back(make_tuple(d, c, mp[c].front(), c));
      mp[c].pop();
    }
  }
}