#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  struct node {
    s64 to;
    s64 d;
    s64 time;
  };
  vector<vector<node>> nodes(n);
  for (s64 i{0}; i < m; ++i) {
    s64 s, t, d, time;
    cin >> s >> t >> d >> time;
    nodes[s - 1].push_back(node{t - 1, d, time});
    nodes[t - 1].push_back(node{s - 1, d, time});
  }
  constexpr auto inf = numeric_limits<s64>::max();
  vector<vector<pair<s64, s64>>> dp((1 << n),
                                    vector<pair<s64, s64>>(n, {inf, 0}));
  dp[1][0] = {0, 1};
  for (s64 i{2}; i < (1 << n); ++i) {
    for (s64 j{0}; j < n; ++j) {
      if (!(i & (1 << j))) continue;
      for (const auto& node : nodes[j]) {
        if (!(i & (1 << node.to))) continue;
        const auto prv_dp = dp[i & ~(1 << j)][node.to];
        if (prv_dp.first == inf) continue;
        const auto time = prv_dp.first + node.d;
        if (time > node.time) continue;
        if (dp[i][j].first == time) {
          dp[i][j].second += prv_dp.second;
        } else if (time < dp[i][j].first) {
          dp[i][j].first = time;
          dp[i][j].second = prv_dp.second;
        }
      }
    }
  }
  s64 min_time{inf}, cnt{0};
  for (const auto& node : nodes[0]) {
    const auto dp_to = dp[(1 << n) - 1][node.to];
    if (dp_to.first == inf) continue;
    const auto time = dp_to.first + node.d;
    if (time > node.time) continue;
    if (time == min_time) {
      cnt += dp_to.second;
    } else if (time < min_time) {
      cnt = dp_to.second;
      min_time = time;
    }
  }
  if (min_time == inf) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << min_time << " " << cnt << endl;
  }
}