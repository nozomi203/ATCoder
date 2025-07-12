#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> xys(n);
  util::cin(xys);
  vector<tuple<s64, s64, s64>> abcs(m);
  util::cin(abcs);

  const auto get_idx = [&](s64 to, s64 from) -> s64 {
    return (n + 1) * to + from + 1;
  };

  constexpr auto inf = numeric_limits<s64>::max();

  vector<vector<pair<s64, s64>>> g(n * (n + 1));

  const auto add_edge = [&](s64 from, s64 to, s64 cost) -> void {
    const auto [xf, yf] = xys[from];
    const auto [xt, yt] = xys[to];
    const auto xft = xt - xf;
    const auto yft = yt - yf;
    const auto to_idx = get_idx(to, from);
    for (s64 prev = 0; prev < n; ++prev) {
      if (prev == from) continue;
      const auto [xp, yp] = xys[prev];
      const auto xfp = xp - xf;
      const auto yfp = yp - yf;
      const auto from_idx = get_idx(from, prev);
      const auto dot = xft * xfp + yft * yfp;
      if (dot <= 0) g[from_idx].push_back(make_pair(cost, to_idx));
    }
    // no previous node
    g[get_idx(from, -1)].push_back(make_pair(cost, to_idx));
  };

  for (auto& [a, b, c] : abcs) {
    add_edge(a - 1, b - 1, c);
    add_edge(b - 1, a - 1, c);
  }

  vector<s64> costs(n * (n + 1), inf);
  using work = pair<s64, s64>;
  priority_queue<work, vector<work>, greater<work>> ws;
  ws.push(make_pair(0, get_idx(0, -1)));
  while (!ws.empty()) {
    auto [cost, idx] = ws.top();
    ws.pop();
    if (costs[idx] <= cost) continue;
    costs[idx] = cost;

    for (auto [nxtc, nxti] : g[idx]) {
      if (cost + nxtc >= costs[nxti]) continue;
      ws.push(make_pair(cost + nxtc, nxti));
    }
  }

  s64 ans = numeric_limits<s64>::max();
  for (s64 i = 0; i < n; ++i) {
    ans = min(ans, costs[get_idx(1, i)]);
  }
  cout << (ans == inf ? -1 : ans) << endl;
}